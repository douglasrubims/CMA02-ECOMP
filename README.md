# LPROG I - Engenharia de Computação
Este repositório será utilizado para versionamento de um trabalho da matéria Laboratório de Programação de Computadores I (LPROG I).

## Projeto: Caixa registradora simples

### Descrição:

O programa funcionará como uma caixa registradora de produtos.

Estamos nos espelhando neste projeto: https://emanuelcandido-js.netlify.app/javascript/vuejs/challenges/01_cash_register/cash_register.html.

A ideia é que o administrador possa cadastrar produtos com Nome, Preço e Quantidade, e o cliente possa escolher um produto para comprar e a quantidade de produtos, e enfim, quando um produto for comprado, será somado no caixa o valor total.

### Informações cadastadas:

| Nome | Tipo | Descrição |
|---|---|---|
| product_name | String (Cadeia de caracteres) | Nome do produto a ser vendido |
| amount | Integer (Inteiro) | Quantidade de produtos disponíveis |
| price | Float (Real) | Preço unitário do produto |
| total | Float (Real) | Total de dinheiro em caixa |

### Funcionamento do programa:
- Menu em loop:
  - 1 - Entrar como administrador
    - Menu do admnistrador:
      - 1 - Cadastrar produto:
        - Entrada para nome do produto
        - Entrada para preço do produto
        - Entrada para quantidade de produtos a vender
      - 2 - Listar produtos
        - Exibição dos dados de todos os produtos:
          - Nome do produto
          - Preço do produto
          - Quantidade de produtos disponíveis
      - 3 - Ver total (R$) das vendas
        - Dinheiro em caixa: R$X.XX
      - 4 - Opção de voltar
  - 2 - Entrar como cliente
    - Menu do cliente:
      - 1 - Listagem dos produtos disponíveis
      - 2 - Comprar produto
        - Entrada para saber qual produto vai comprar
        - Entrada para dizer a quantidade que vai comprar deste produto
      - 3 - Opção de voltar

- Constantes
	Linhas: 5 e 6
	Exemplo: #define TAM 1000

- Variaveis
	Linhas: 9, 10 e 11
	Exemplo: int optionGeral, optionMenu, productQuantities[TAM], iterator = 0, i, j, id, qtd;

- Operação aritmeticas
	Linha: 36, 43, 48, 51, 54, 64, 86, 92, 95, 98, 109, 116, 118, 121, 124, 134 e 135
	Exemplo: iterator++;

- Operações lógicas
	Linha: 42, 85, 90, 107, 113, 129, 130 e 133
	Exemplo: iterator != 0

- Comandos de atribuição
	Linha: 9, 11, 35, 36, 43, 48, 50, 51, 53, 54, 63, 64, 86, 92, 94, 95, 97, 98, 109, 114, 116, 118, 120, 121, 123 e 124
	Exemplo: iterator = 0

- Comando de entrada e saída
	Linha: 15, 16, 22, 23, 27, 29, 30, 32, 33, 35, 37, 41, 47, 48, 49, 51, 52, 54, 55, 57, 58, 62, 64, 65, 71, 79, 80, 84, 91, 92, 93, 95, 96, 98, 99, 101, 102, 106, 108, 115, 116, 117, 118, 119, 121, 122, 124, 125, 127, 128, 131, 132, 136, 137, 138, 142, 149, 154 e 157
	Exemplo: printf("+---+---------------+\n|   | Entrar como:  |\n+---+---------------+\n| 1 | Administrador |\n| 2 | Cliente       |\n| 3 | Sair          |\n+---+---------------+\n");

- Estrutura condicional simples e/ou estrutura condicional composta e/ou estrutura condicional de múltipla escolha
	Linha: 17, 25, 42, 58, 82, 85, 90, 102, 107, 113, 129, 130, 133, 137, 138 e 141
	Exemplo: switch(optionGeral) {}

- Estrutura de repetição com teste no início e/ou estrutura de repetição com teste no fim e/ou estrutura de repetição com variável de controle
	Linha: 12, 19, 43, 48, 51, 54, 64, 73, 76, 86, 92, 95, 98, 109, 116, 118, 121, 124, 151 e 159
	Exemplo: do {} while(optionGeral != 3);

- Estruturas de dados homogêneas: vetores numéricos, vetores de caracteres e/ou matrizes
	Linha: 9, 10, 11, 29, 32, 35, 47, 48, 49, 50, 52, 53, 90, 91, 92, 93, 94, 96, 97, 113, 117, 118, 119, 120, 122, 123, 130, 131, 133, 134, 135 e 136
	Exemplo: productQuantities[TAM]
