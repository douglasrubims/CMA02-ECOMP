#include <stdio.h>
#include <stdlib.h> // system está contido nessa lib
#include <string.h> // strlen está contido nessa lib
// constantes
#define TAM 1000
#define STRTAM 27

typedef struct {
	char nome[STRTAM];
	float preco;
	int quantidade;
} Produto;

typedef struct {
	Produto itens[TAM];
	int qtd_itens;
	float total;
} Caixa;

void cadastrarProduto(Caixa *caixa) {
	printf("Digite o nome do produto: ");
	fflush(stdin);
	scanf("%[^\n]26s", caixa->itens[caixa->qtd_itens].nome); // entrada do nome do produto
	printf("Digite o preco do produto: R$");
	fflush(stdin);
	scanf("%f", &caixa->itens[caixa->qtd_itens].preco); // entrada do preço do produto
	printf("Digite a quantidade em estoque desse produto: ");
	fflush(stdin);
	scanf("%d", &caixa->itens[caixa->qtd_itens].quantidade); // entrada da quantidade de produtos em estoque
	caixa->qtd_itens++;
	printf("[INFO] Produto cadastrado com sucesso.\n");
	getch();
}

void aumentarQuantidade(Caixa *caixa) {
	int i, j, id, qtd;
	char strAlt[STRTAM];
	printf("+------+----------------------------+----------+------------+\n|  Id  |            Nome            |  Preco   | Quantidade |\n+------+----------------------------+----------+------------+\n");
	if(caixa->qtd_itens != 0) { // verifica se tem produto cadastrado. se n tiver, ele diz que nao tem produtos cadastrados
		printf("| 0    | Voltar                     |          |            |\n");
		for(i = 0; i < caixa->qtd_itens; i++) {
			// as sequencias de FOR abaixo servem para preencher com espaços na frente de cada campo de texto dentro da tabela
			// isso é feito pra que a tabela não fique deformada
			// o sprintf esta servindo para transformar de float e int para string, para que possamos usar o strlen
			sprintf(strAlt, "%d", i);
			printf("| %d ", i + 1);
			for(j = 0; j < 4 - strlen(strAlt); j++) printf(" ");
			printf("| %s ", caixa->itens[i].nome);
			for(j = 0; j < 26 - strlen(caixa->itens[i].nome); j++) printf(" ");
			printf("| R$%.2f ", caixa->itens[i].preco);
			sprintf(strAlt, "%.2f", caixa->itens[i].preco);
			for(j = 0; j < 6 - strlen(strAlt); j++) printf(" ");
			printf("| %d ", caixa->itens[i].quantidade);
			sprintf(strAlt, "%d", caixa->itens[i].quantidade);
			for(j = 0; j < 10 - strlen(strAlt); j++) printf(" ");
			printf("|\n");
		}
		printf("+------+----------------------------+----------+------------+\nDigite o Id do produto que deseja aumentar a quantidade: ");
		scanf("%d", &id);
		if(id != 0) { // se o id for 0, ele nao entra no for e volta pro menu, pois 0 é para voltar
			if(id > 0 && id <= caixa->qtd_itens) { // verifica se o id existe
				printf("Quantidade a adicionar de %s: ", caixa->itens[id - 1].nome);
				scanf("%d", &qtd); // entrada da nova quantidade de produtos
				// verifica se foi digitado uma quantidade válida
				if(qtd > 0) {
					caixa->itens[id - 1].quantidade += qtd;
					printf("Nova quantidade de %s: %d produtos.\n[INFO] Modificacao realizada com sucesso.\n", caixa->itens[id - 1].nome, caixa->itens[id - 1].quantidade);
				} else printf("[INFO] Quantidade invalida.\n");
			} else printf("[INFO] ID invalido.\n");
			getch();
		}
	} else {
		printf("|              NENHUM PRODUTO CADASTRADO AINDA              |\n+-----------------------------------------------------------+\n");
		getch();
	}
}

void submenuCadastrarProduto(Caixa *caixa) {
	int optionSubmenu;
	do {
		system("cls");
		// menu para cadastrar novo produto (1) ou aumentar quantidade de produtos (2)
		printf("+---+---------------------------+\n|   |    Menu Administrativo    |\n+---+---------------------------+\n| 1 | Cadastrar um novo produto |\n| 2 | Mudar quantidade          |\n| 3 | Voltar                    |\n+---+---------------------------+\n");
		scanf("%d", &optionSubmenu); // entrada da opcao escolhida pelo usuario
		system("cls");
		switch(optionSubmenu) {
			case 1:
				cadastrarProduto(caixa);
				break;
			case 2:
				aumentarQuantidade(caixa);
				break;
			case 3:
				break;
			default:
				printf("[INFO] Opcao invalida.\n");
		}
	} while(optionSubmenu != 3); // flag do while --> volta para o menu administrador quando digita 3
}

void listarProdutos(Caixa *caixa, int administrador) {
	int i, j;
	char strAlt[STRTAM];
	printf("+----------------------------+----------+------------+\n|            Nome            |  Preco   | Quantidade |\n+----------------------------+----------+------------+\n");
	if(caixa->qtd_itens != 0) { // verifica se tem produto cadastrado. se n tiver, ele diz que nao tem produtos cadastrados
		for(i = 0; i < caixa->qtd_itens; i++) {
			// as sequencias de FOR abaixo servem para preencher com espaços na frente de cada campo de texto dentro da tabela
			// isso é feito pra que a tabela não fique deformada
			// o sprintf esta servindo para transformar de float e int para string, para que possamos usar o strlen
			if(administrador == 0 && caixa->itens[i].quantidade == 0) continue;
			printf("| %s ", caixa->itens[i].nome);
			for(j = 0; j < 26 - strlen(caixa->itens[i].nome); j++) printf(" ");
			printf("| R$%.2f ", caixa->itens[i].preco);
			sprintf(strAlt, "%.2f", caixa->itens[i].preco);
			for(j = 0; j < 6 - strlen(strAlt); j++) printf(" ");
			printf("| %d ", caixa->itens[i].quantidade);
			sprintf(strAlt, "%d", caixa->itens[i].quantidade);
			for(j = 0; j < 10 - strlen(strAlt); j++) printf(" ");
			printf("|\n");
		}
		printf("+----------------------------+----------+------------+\n");
	} else printf("|          NENHUM PRODUTO CADASTRADO AINDA           |\n+----------------------------------------------------+\n");
	getch();
}

void exibeTotal(Caixa *caixa) {
	char strAlt[STRTAM];
	int i;
	printf("+----------------+\n| Total em Caixa |\n+----------------+\n| R$%.2f ", caixa->total);
	sprintf(strAlt, "%.2f", caixa->total);
	for(i = 0; i < 12 - strlen(strAlt); i++) printf(" ");
	printf("|\n+----------------+\n");
	getch();
}

void menuAdministrador(Caixa *caixa) {
	int optionMenu;
	do {
		system("cls");
		// menu do admin para cadastrar (1) e listar (2) produtos, e também ver total do caixa (3)
		printf("+---+---------------------------+\n|   |    Menu Administrativo    |\n+---+---------------------------+\n| 1 | Cadastrar produto         |\n| 2 | Listar produtos           |\n| 3 | Ver total (R$) das vendas |\n| 4 | Voltar                    |\n+---+---------------------------+\n");
		scanf("%d", &optionMenu); // entrada da opcao escolhida pelo usuario
		system("cls");
		switch(optionMenu) {
			case 1:
				submenuCadastrarProduto(caixa);
				break;
			case 2:
				listarProdutos(caixa, 1);
				break;
			case 3:
				exibeTotal(caixa);
				break;
			case 4:
				break;
			default:
				printf("[INFO] Opcao invalida.\n");
		}
	} while(optionMenu != 4); // flag do while --> volta para o menu geral quando digita 4
}

void comprarProduto(Caixa *caixa) {
	int i, j, id, qtd;
	char strAlt[STRTAM];
	printf("+------+----------------------------+----------+------------+\n|  Id  |            Nome            |  Preco   | Quantidade |\n+------+----------------------------+----------+------------+\n");
	if(caixa->qtd_itens != 0) { // verifica se tem produto cadastrado. se n tiver, ele diz que nao tem produtos cadastrados
		printf("| 0    | Voltar                     |          |            |\n");
		for(i = 0; i < caixa->qtd_itens; i++) {
			// as sequencias de FOR abaixo servem para preencher com espaços na frente de cada campo de texto dentro da tabela
			// isso é feito pra que a tabela não fique deformada
			// o sprintf esta servindo para transformar de float e int para string, para que possamos usar o strlen
			if(caixa->itens[i].quantidade == 0) continue;
			sprintf(strAlt, "%d", i);
			printf("| %d ", i + 1);
			for(j = 0; j < 4 - strlen(strAlt); j++) printf(" ");
			printf("| %s ", caixa->itens[i].nome);
			for(j = 0; j < 26 - strlen(caixa->itens[i].nome); j++) printf(" ");
			printf("| R$%.2f ", caixa->itens[i].preco);
			sprintf(strAlt, "%.2f", caixa->itens[i].preco);
			for(j = 0; j < 6 - strlen(strAlt); j++) printf(" ");
			printf("| %d ", caixa->itens[i].quantidade);
			sprintf(strAlt, "%d", caixa->itens[i].quantidade);
			for(j = 0; j < 10 - strlen(strAlt); j++) printf(" ");
			printf("|\n");
		}
		printf("+------+----------------------------+----------+------------+\nDigite o Id do produto que deseja comprar: ");
		scanf("%d", &id);
		if(id != 0) { // se o id for 0, ele nao entra no for e volta pro menu, pois 0 é para voltar
			if(id > 0 && id <= caixa->qtd_itens && caixa->itens[id - 1].quantidade > 0) { // verifica se o id existe e se tem em estoque
				printf("Digite a quantidade de %s que deseja comprar: ", caixa->itens[id - 1].nome);
				scanf("%d", &qtd); // entrada da quantidade de produtos que o cliente comprará
				if(qtd > 0 && qtd <= caixa->itens[id - 1].quantidade) { // verifica se foi digitado uma quantidade válida
					caixa->total += qtd * caixa->itens[id - 1].preco; // adiciona o valor no caixa
					caixa->itens[id - 1].quantidade -= qtd; // diminui a quantidade de produtos comprados no estoque
					printf("Sua compra ficou em: R$%.2f.\n[INFO] Compra realizada com sucesso.\n", (qtd * caixa->itens[id - 1].preco));
				} else printf("[INFO] Quantidade invalida.\n");
			} else printf("[INFO] ID invalido.\n");
			getch();
		}
	} else {
		printf("|              NENHUM PRODUTO CADASTRADO AINDA              |\n+-----------------------------------------------------------+\n");
		getch();
	}
}

void menuCliente(Caixa *caixa) {
	int optionMenu;
	do {
		system("cls");
		// menu do cliente para listar (1) ou comprar (2) produtos
		printf("+---+-----------------------------+\n|   |   Seja bem-vindo, cliente   |\n+---+-----------------------------+\n| 1 | Listar produtos disponiveis |\n| 2 | Comprar um produto          |\n| 3 | Voltar                      |\n+---+-----------------------------+\n");
		scanf("%d", &optionMenu); // entrada da opcao escolhida pelo usuario
		system("cls");
		switch(optionMenu) {
			case 1:
				listarProdutos(caixa, 0);
				break;
			case 2:
				comprarProduto(caixa);
				break;
			case 3:
				break;
			default:
				printf("[INFO] Opcao invalida.\n");
		}
	} while(optionMenu != 3); // flag do while --> volta para o menu geral quando digita 3
}

int main() {
	Caixa caixa;
	caixa.qtd_itens = 0;
	caixa.total = 0;
	int optionGeral;
	do {
		system("cls"); // limpa a tela
		// menu geral para escolher entrar como administrador (1) ou cliente (2)
		printf("+---+---------------+\n|   | Entrar como:  |\n+---+---------------+\n| 1 | Administrador |\n| 2 | Cliente       |\n| 3 | Sair          |\n+---+---------------+\n");
		scanf("%d", &optionGeral); // entrada da opcao escolhida pelo usuario
		switch(optionGeral) {
			case 1:
				menuAdministrador(&caixa);
			break;
			case 2:
				menuCliente(&caixa);
			break;
			case 3:
				printf("Saindo...\n");
			break;
			default:
				printf("[INFO] Opcao invalida.\n");
		}
	} while(optionGeral != 3); // flag do while --> encerra o programa quando digita 3 no menu geral
	return 0;
}