# LPROG I - Engenharia de Computação
Este repositório será utilizado para versionamento de um trabalho da matéria Laboratório de Programação de Computadores I (LPROG I).

## Projeto: Caixa registradora simples

### Descrição:

O programa funcionará como uma caixa registradora de produtos.

Estamos nos espelhando neste projeto: https://emanuelcandido-js.netlify.app/javascript/vuejs/joao_ribeiro/challenges/01_cash_register/cash_register.

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
