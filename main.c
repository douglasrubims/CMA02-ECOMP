#include <stdio.h>
#include <stdlib.h> // system está contido nessa lib
#include <string.h> // strlen está contido nessa lib
// constantes
#define TAM 1000
#define STRTAM 27

int main() {
	int optionGeral, optionMenu, productQuantities[TAM], iterator = 0, i, j, id, qtd;
	char productNames[TAM][STRTAM], strAlt[STRTAM];
	float productPrices[TAM], totalCash = 0;
	do {
		system("cls"); // limpa a tela
		// menu geral para escolher entrar como administrador (1) ou cliente (2)
		printf("+---+---------------+\n|   | Entrar como:  |\n+---+---------------+\n| 1 | Administrador |\n| 2 | Cliente       |\n| 3 | Sair          |\n+---+---------------+\n");
		scanf("%d", &optionGeral); // entrada da opcao escolhida pelo usuario
		switch(optionGeral) {
			case 1:
				do {
					system("cls");
					// menu do admin para cadastrar (1) e listar (2) produtos, e também ver total do caixa (3)
					printf("+---+---------------------------+\n|   |    Menu Administrativo    |\n+---+---------------------------+\n| 1 | Cadastrar produto         |\n| 2 | Listar produtos           |\n| 3 | Ver total (R$) das vendas |\n| 4 | Voltar                    |\n+---+---------------------------+\n");
					scanf("%d", &optionMenu); // entrada da opcao escolhida pelo usuario
					system("cls");
					switch(optionMenu) {
						case 1:
							printf("Digite o nome do produto: ");
							fflush(stdin);
							scanf("%[^\n]26s", productNames[iterator]); // entrada do nome do produto
							printf("Digite o preco do produto: R$");
							fflush(stdin);
							scanf("%f", &productPrices[iterator]); // entrada do preço do produto
							printf("Digite a quantidade em estoque desse produto: ");
							fflush(stdin);
							scanf("%d", &productQuantities[iterator]); // entrada da quantidade de produtos em estoque
							iterator++;
							printf("[INFO] Produto cadastrado com sucesso.\n");
							getch();
							break;
						case 2:
							printf("+----------------------------+----------+------------+\n|            Nome            |  Preco   | Quantidade |\n+----------------------------+----------+------------+\n");
							if(iterator != 0) { // verifica se tem produto cadastrado. se n tiver, ele diz que nao tem produtos cadastrados
								for(i = 0; i < iterator; i++) {
									// as sequencias de FOR abaixo servem para preencher com espaços na frente de cada campo de texto dentro da tabela
									// isso é feito pra que a tabela não fique deformada
									// o sprintf esta servindo para transformar de float e int para string, para que possamos usar o strlen
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
				} while(optionMenu != 4); // flag do while --> volta para o menu geral quando digita 4
			break;
			case 2:
				do {
					system("cls");
					// menu do cliente para listar (1) ou comprar (2) produtos
					printf("+---+-----------------------------+\n|   |   Seja bem-vindo, cliente   |\n+---+-----------------------------+\n| 1 | Listar produtos disponiveis |\n| 2 | Comprar um produto          |\n| 3 | Voltar                      |\n+---+-----------------------------+\n");
					scanf("%d", &optionMenu); // entrada da opcao escolhida pelo usuario
					system("cls");
					switch(optionMenu) {
						case 1:
							printf("+----------------------------+----------+------------+\n|            Nome            |  Preco   | Quantidade |\n+----------------------------+----------+------------+\n");
							if(iterator != 0) { // verifica se tem produto cadastrado. se n tiver, ele diz que nao tem produtos cadastrados
								for(i = 0; i < iterator; i++) {
									// as sequencias de FOR abaixo servem para preencher com espaços na frente de cada campo de texto dentro da tabela
									// isso é feito pra que a tabela não fique deformada
									// o sprintf esta servindo para transformar de float e int para string, para que possamos usar o strlen
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
							if(iterator != 0) { // verifica se tem produto cadastrado. se n tiver, ele diz que nao tem produtos cadastrados
								printf("| 0    | Voltar                     |          |            |\n");
								for(i = 0; i < iterator; i++) {
									// as sequencias de FOR abaixo servem para preencher com espaços na frente de cada campo de texto dentro da tabela
									// isso é feito pra que a tabela não fique deformada
									// o sprintf esta servindo para transformar de float e int para string, para que possamos usar o strlen
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
								if(id != 0) { // se o id for 0, ele nao entra no for e volta pro menu, pois 0 é para voltar
									if(id > 0 && id <= iterator && productQuantities[id - 1] > 0) { // verifica se o id existe e se tem em estoque
										printf("Digite a quantidade de %s que deseja comprar: ", productNames[id - 1]);
										scanf("%d", &qtd); // entrada da quantidade de produtos que o cliente comprará
										if(qtd > 0 && qtd <= productQuantities[id - 1]) { // verifica se foi digitado uma quantidade válida
											totalCash += qtd * productPrices[id - 1]; // adiciona o valor no caixa
											productQuantities[id - 1] -= qtd; // diminui a quantidade de produtos comprados no estoque
											printf("Sua compra ficou em: R$%.2f.\n[INFO] Compra realizada com sucesso.\n", qtd * productQuantities[id - 1]);
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
				} while(optionMenu != 3); // flag do while --> volta para o menu geral quando digita 3
			break;
			case 3:
				printf("Saindo...");
			break;
			default:
				printf("[INFO] Opcao invalida.\n");
		}
	} while(optionGeral != 3); // flag do while --> encerra o programa quando digita 3 no menu geral
	return 0;
}