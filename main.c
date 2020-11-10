#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
#define STRTAM 27

int main() {
	int optionGeral, optionMenu, productQuantities[TAM], iterator = 0, i, j, id, qtd;
	char productNames[TAM][STRTAM], strAlt[STRTAM];
	float productPrices[TAM], totalCash = 0;
	do {
		system("cls");
		printf("+---+---------------+\n|   | Entrar como:  |\n+---+---------------+\n| 1 | Administrador |\n| 2 | Cliente       |\n| 3 | Sair          |\n+---+---------------+\n");
		scanf("%d", &optionGeral);
		switch(optionGeral) {
			case 1:
				do {
					system("cls");
					printf("+---+---------------------------+\n|   |    Menu Administrativo    |\n+---+---------------------------+\n| 1 | Cadastrar produto         |\n| 2 | Listar produtos           |\n| 3 | Ver total (R$) das vendas |\n| 4 | Voltar                    |\n+---+---------------------------+\n");
					scanf("%d", &optionMenu);
					system("cls");
					switch(optionMenu) {
						case 1:
							printf("Digite o nome do produto: ");
							fflush(stdin);
							scanf("%[^\n]26s", productNames[iterator]);
							printf("Digite o preco do produto: R$");
							fflush(stdin);
							scanf("%f", &productPrices[iterator]);
							printf("Digite a quantidade em estoque desse produto: ");
							fflush(stdin);
							scanf("%d", &productQuantities[iterator]);
							iterator++;
							printf("[INFO] Produto cadastrado com sucesso.\n");
							getch();
							break;
						case 2:
							printf("+----------------------------+----------+------------+\n|            Nome            |  Preco   | Quantidade |\n+----------------------------+----------+------------+\n");
							if(iterator != 0) {
								for(i = 0; i < iterator; i++) {
									printf("| %s ", productNames[i]);
									for(j = 0; j < 26 - strlen(productNames[i]); j++) printf(" ");
									printf("| R$%.2f ", productPrices[i]);
									sprintf(strAlt, "%.2f", productPrices[i]);
									for(j = 0; j < 6 - strlen(strAlt); j++) printf(" ");
									printf("| %d ", productQuantities[i]);
									sprintf(strAlt, "%d", productQuantities[i]);
									for(j = 0; j < 10 - strlen(strAlt); j++) printf(" ");
									printf("|\n");
								}
								printf("+----------------------------+----------+------------+\n");
							} else printf("|          NENHUM PRODUTO CADASTRADO AINDA           |\n+----------------------------------------------------+\n");
							getch();
							break;
						case 3:
							printf("+----------------+\n| Total em Caixa |\n+----------------+\n| R$%.2f ", totalCash);
							sprintf(strAlt, "%.2f", totalCash);
							for(j = 0; j < 12 - strlen(strAlt); j++) printf(" ");
							printf("|\n+----------------+\n");
							getch();
							break;
						case 4:
							break;
						default:
							printf("[INFO] Opcao invalida.\n");
					}
				} while(optionMenu != 4);
			break;
			case 2:
				do {
					system("cls");
					printf("+---+-----------------------------+\n|   |   Seja bem-vindo, cliente   |\n+---+-----------------------------+\n| 1 | Listar produtos disponiveis |\n| 2 | Comprar um produto          |\n| 3 | Voltar                      |\n+---+-----------------------------+\n");
					scanf("%d", &optionMenu);
					system("cls");
					switch(optionMenu) {
						case 1:
							printf("+----------------------------+----------+------------+\n|            Nome            |  Preco   | Quantidade |\n+----------------------------+----------+------------+\n");
							if(iterator != 0) {
								for(i = 0; i < iterator; i++) {
									if(productQuantities[i] == 0) continue;
									printf("| %s ", productNames[i]);
									for(j = 0; j < 26 - strlen(productNames[i]); j++) printf(" ");
									printf("| R$%.2f ", productPrices[i]);
									sprintf(strAlt, "%.2f", productPrices[i]);
									for(j = 0; j < 6 - strlen(strAlt); j++) printf(" ");
									printf("| %d ", productQuantities[i]);
									sprintf(strAlt, "%d", productQuantities[i]);
									for(j = 0; j < 10 - strlen(strAlt); j++) printf(" ");
									printf("|\n");
								}
								printf("+----------------------------+----------+------------+\n");
							} else printf("|          NENHUM PRODUTO CADASTRADO AINDA           |\n+----------------------------------------------------+\n");
							getch();
							break;
						case 2:
							printf("+------+----------------------------+----------+------------+\n|  Id  |            Nome            |  Preco   | Quantidade |\n+------+----------------------------+----------+------------+\n");
							if(iterator != 0) {
								printf("| 0    | Voltar                     |          |            |\n");
								for(i = 0; i < iterator; i++) {
									if(productQuantities[i] == 0) continue;
									sprintf(strAlt, "%d", i);
									printf("| %d ", i + 1);
									for(j = 0; j < 4 - strlen(strAlt); j++) printf(" ");
									printf("| %s ", productNames[i]);
									for(j = 0; j < 26 - strlen(productNames[i]); j++) printf(" ");
									printf("| R$%.2f ", productPrices[i]);
									sprintf(strAlt, "%.2f", productPrices[i]);
									for(j = 0; j < 6 - strlen(strAlt); j++) printf(" ");
									printf("| %d ", productQuantities[i]);
									sprintf(strAlt, "%d", productQuantities[i]);
									for(j = 0; j < 10 - strlen(strAlt); j++) printf(" ");
									printf("|\n");
								}
								printf("+------+----------------------------+----------+------------+\nDigite o Id do produto que deseja comprar: ");
								scanf("%d", &id);
								if(id != 0) {
									if(id > 0 && id <= iterator && productQuantities[id - 1] > 0) {
										printf("Digite a quantidade de %s que deseja comprar: ", productNames[id - 1]);
										scanf("%d", &qtd);
										if(qtd > 0 && qtd <= productQuantities[id - 1]) {
											totalCash += qtd * productPrices[id - 1];
											productQuantities[id - 1] -= qtd;
											printf("[INFO] Compra realizada com sucesso.\n");
										} else printf("[INFO] Quantidade invalida.\n");
									} else printf("[INFO] ID invalido.\n");
									getch();
								}
							} else {
								printf("|              NENHUM PRODUTO CADASTRADO AINDA              |\n+-----------------------------------------------------------+\n");
								getch();
							}
							break;
						case 3:
							break;
						default:
							printf("[INFO] Opcao invalida.\n");
					}
				} while(optionMenu != 3);
			break;
			case 3:
				printf("Saindo...");
			break;
			default:
				printf("[INFO] Opcao invalida.\n");
		}
	} while(optionGeral != 3);
	return 0;
}