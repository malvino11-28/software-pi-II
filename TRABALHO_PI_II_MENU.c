#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TF 100
#define TFR 15
#define TS 1000

// struct Produto -  id, nome, medida, marca, categoria, data_validade
typedef struct {
	int id;
	char nome[TF], medida[TFR], marca[TF], categoria[TF], Data validade; 
} PRODUTO;
// struct Assinatura - id_cliente, plano, Data vencimento, status

void exibirMenuInicial() {
    printf("\n==============================================\n");
    printf("               CORTE IMPERIAL                 \n");
    printf("==============================================\n");
    printf("  [1] Pessoas\n");
    printf("  [2] Produtos\n");
    printf("  [3] Assinaturas\n");
    printf("  [4] Vendas\n");
    printf("  [5] Relatorios\n");
    printf("  [0] Sair\n");
    printf("----------------------------------------------\n");
    printf(" Selecione uma opcao: ");
}

// MENU PESSOAS
void exibirMenuPessoas() {
    printf("\n==============================================\n");
    printf("           CORTE IMPERIAL - PESSOAS           \n");
    printf("==============================================\n");
    printf("  [1] Gerenciar Clientes\n");
    printf("  [2] Gerenciar Fornecedores\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------------\n");
    printf(" Selecione uma opcao: ");
}

//Gerenciamento Clientes
void menu_cli() {
    printf("\n==================================================\n");
    printf("      CORTE IMPERIAL - GERENCIAR CLIENTES         \n");
    printf("==================================================\n");
    printf("  [1] Cadastrar Cliente\n");
    printf("  [2] Alterar Cliente\n");
    printf("  [3] Consultar Cliente\n");
    printf("  [4] Excluir Cliente\n");
    printf("  [0] Voltar\n");
    printf("--------------------------------------------------\n");
    printf("  Selecione uma opcao: ");
}

//Gerenciamento Fornecedores
void menu_forn() {
    printf("\n========================================================\n");
    printf("        CORTE IMPERIAL - GERENCIAR FORNECEDORES          \n");
    printf("========================================================\n");
    printf("  [1] Cadastrar Fornecedor\n");
    printf("  [2] Alterar Fornecedor\n");
    printf("  [3] Consultar Fornecedor\n");
    printf("  [4] Excluir Fornecedor\n");
    printf("  [0] Voltar\n");
    printf("--------------------------------------------------------\n");
    printf(" Selecione uma opcao: ");
}

void exibirMenuProdutos() {
    printf("\n==============================================\n");
    printf("           CORTE IMPERIAL - PRODUTOS          \n");
    printf("==============================================\n");
    printf("  [1] Cadastrar Produto\n");
    printf("  [2] Alterar Produto\n");
    printf("  [3] Consultar Produto\n");
    printf("  [4] Excluir Produto\n");
    printf("  [5] Gerenciar Marcas\n");
    printf("  [6] Gerenciar Categorias\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------------\n");
    printf(" Selecione uma opcao: ");
}

void exibirMenuAssinaturas() {
    printf("\n==============================================\n");
    printf("          CORTE IMPERIAL - ASSINATURAS        \n");
    printf("==============================================\n");
    printf("  [1] Criar Assinatura para Cliente\n");
    printf("  [2] Renovar Assinatura\n");
    printf("  [3] Consultar Status da Assinatura\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------------\n");
    printf(" Selecione uma opcao: ");
}

void exibirMenuVendas() {
    printf("\n==============================================\n");
    printf("            CORTE IMPERIAL - VENDAS           \n");
    printf("==============================================\n");
    printf("  [1] Visualizar Pedidos Recebidos\n");
    printf("  [2] Atualizar Status do Pedido\n");
    printf("  [3] Confirmar Retirada\n");
    printf("  [4] Confirmar Entrega\n");
    printf("  [5] Finalizar Pedido\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------------\n");
    printf(" Selecione uma opcao: ");
}

void exibirMenuRelatorios() { 	
    printf("\n==============================================\n");
    printf("          CORTE IMPERIAL - RELATORIOS         \n");
    printf("==============================================\n");
    printf("  [1] Vendas por Periodo\n");
    printf("  [2] Produtos com Estoque Baixo\n");
    printf("  [3] Ticket Medio por Cliente\n");
    printf("  [4] Listar Proximas do Vencimento\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------------\n");
    printf(" Selecione uma opcao: ");
}

// FUNCOES PESSOAS - CLIENTES

//Cadastro Clientes
void cad_cli() {
    char nome[50], cpf[50], rg[50], data_nasc[1000], ender[100], email[100], tel[20];
    printf("\n========================================================\n");
    printf("         CORTE IMPERIAL - CADASTRAR CLIENTES            \n");
    printf("========================================================\n");

    printf("\nDigite o Nome Completo: "); fflush(stdin);
    gets(nome);
    printf("\nDigite o CPF: "); fflush(stdin);
    gets(cpf);
    printf("\nDigite o RG: "); fflush(stdin);
    gets(rg);
    printf("\nDigite a Data de Nascimento: "); fflush(stdin);
    gets(data_nasc);
    printf("\nDigite o Endereco: "); fflush(stdin);
    gets(ender);
    printf("\nDigite o E-mail: "); fflush(stdin);
    gets(email);
    printf("\nDigite o Telefone: "); fflush(stdin);
    gets(tel);
	printf("----------------------------------------------\n");
    printf("Cadastro realizado com sucesso!!!\n");
}

//Para buscar o cliente que sera alterado / Colocar dentro da funcao alterar_forc*
void exibir_cli() {
    printf("\nNome Completo: ------SAIDA--------\n");
    printf("CPF: ------------------SAIDA--------\n");
    printf("RG: -------------------SAIDA--------\n");
    printf("Data de Nascimento: ---SAIDA--------\n");
    printf("Endereco: -------------SAIDA--------\n");
    printf("E-mail: ---------------SAIDA--------\n");
    printf("Telefone: -------------SAIDA--------\n");
}

//Alterar Cadastro Cliente
void alterar_cli() {
    int opcao = -1, alterou = 0;
    char teste[1000];
    char cpf_busca[100];

    printf("\n========================================================\n");
    printf("           CORTE IMPERIAL - ALTERAR CLIENTE             \n");
    printf("========================================================\n");

    printf("\nDigite o CPF do Cliente: ");
    fflush(stdin);
    gets(cpf_busca);

    exibir_cli(); //*

    while (opcao != 0) {
        printf("\n----------------------------------------------\n");
		printf("\nQual informacao voce deseja alterar?\n\n");
        printf("  [1] Nome Completo\n");
        printf("  [2] RG\n");
        printf("  [3] Data de Nascimento\n");
        printf("  [4] Endereco\n");
        printf("  [5] E-mail\n");
        printf("  [6] Telefone\n");
        printf("  [0] Voltar\n");
        printf("\n----------------------------------------------\n");
		printf(" Selecione uma opcao: ");
		scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n Digite o novo Nome Completo: ");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 2:
                printf("\n Digite o novo RG: ");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 3:
                printf("\n Digite a nova Data de Nascimento: ");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 4:
                printf("\n Digite o novo Endereco: ");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 5:
                printf("\n Digite o novo E-mail: ");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 6:
                printf("\n Digite o novo Telefone: ");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 0:
                break;

            default:
                printf("\n Opcao Invalida!!!");
                break;
        }
    }

    if (alterou != 0) {
        printf("\n Alteracao realizada com sucesso!!!");
    }
}

//Consultar Cliente
void consul_cli() {
    char cpf_busca[100];

    printf("\n========================================================\n");
    printf("          CORTE IMPERIAL - CONSULTAR CLIENTE            \n");
    printf("========================================================\n");

    printf("\nDigite o CPF do Cliente: ");
    fflush(stdin);
    gets(cpf_busca);

    exibir_cli();
}

//Excluir Cliente
void excl_cli() {
    int esc;
    char cpf_busca[100];

    printf("\nDigite o CPF do Cliente: ");
    fflush(stdin);
    gets(cpf_busca);

    printf("\n----- CPF ENCONTRADO!!! ------\n");
    exibir_cli();

    do {
        printf("\nVoce tem certeza que deseja excluir esse Cliente?\n");
        printf("Esta acao nao pode ser desfeita.\n\n");
        printf(" [1] Confirmar\n");
        printf(" [0] Cancelar\n");
        printf("----------------------------------------------\n");
		printf(" Selecione uma opcao: ");
        scanf("%d", &esc);

        if (esc == 1) {
            printf("\n Cliente Excluido com Sucesso!!!\n");
        } else if (esc == 0) {
            printf("\nOperacao cancelada!\n");
        } else {
            printf("\nOpcao invalida!!!\n");
        }

    } while (esc != 1 && esc != 0);
}

// FUNCOES PESSOAS - FORNECEDORES

//Cadastro Fornecedores
void cad_forn() {
    char cnpj[50], razaoSoc[1000], nomeFan[1000], cidade[1000], estado[100], email[100], tel[20];

    printf("\n========================================================\n");
    printf("        CORTE IMPERIAL - CADASTRAR FORNECEDOR           \n");
    printf("========================================================\n");

    printf("\nDigite o CNPJ: "); fflush(stdin);
    gets(cnpj);
    printf("\nDigite a Razao Social: "); fflush(stdin);
    gets(razaoSoc);
    printf("\nDigite o Nome Fantasia: "); fflush(stdin);
    gets(nomeFan);
    printf("\nDigite a Cidade: "); fflush(stdin);
    gets(cidade);
    printf("\nDigite o Estado: "); fflush(stdin);
    gets(estado);
    printf("\nDigite o E-mail: "); fflush(stdin);
    gets(email);
    printf("\nDigite o Telefone: "); fflush(stdin);
    gets(tel);

    printf("\nCadastro realizado com sucesso!!!\n");
}

//Para buscar o CNPJ que sera alterado / Colocar dentro da funcao alterar_forc*
void exibir_forn() {
    printf("\nRazao Social: -------------SAIDA--------------\n");
    printf("Nome Fantasia: ------------SAIDA--------------\n");
    printf("Cidade: -------------------SAIDA--------------\n");
    printf("Estado: -------------------SAIDA--------------\n");
    printf("E-mail: -------------------SAIDA--------------\n");
    printf("Telefone: -----------------SAIDA--------------\n");
}

//Alterar Cadastro Fornecedor
void alterar_forn() {
    int opcao, alterou = 0;
    char teste[1000];
    char cnpj_busca[100];

    printf("\n========================================================\n");
    printf("         CORTE IMPERIAL - ALTERAR FORNECEDOR            \n");
    printf("========================================================\n");

    printf("Digite o CNPJ do Fornecedor: \n");
    fflush(stdin);
    gets(cnpj_busca);

    exibir_forn(); //*

    do {
        printf("\nQual informacao voce deseja alterar?\n");
        printf("  [1] Razao Social\n");
        printf("  [2] Nome Fantasia\n");
        printf("  [3] Cidade\n");
        printf("  [4] Estado\n");
        printf("  [5] E-mail\n");
        printf("  [6] Telefone\n");
        printf("  [0] Voltar\n");
        printf("----------------------------------------------\n");
		printf(" Selecione uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n Digite a nova Razao Social: ");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 2:
                printf("\n Digite o novo Nome Fantasia: ");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 3:
                printf("\n Digite a nova Cidade: \n");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 4:
                printf("\n Digite o novo Estado: \n");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 5:
                printf("\n Digite o novo E-mail: \n");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 6:
                printf("\n Digite o novo Telefone: ");
                fflush(stdin);
                gets(teste);
                alterou = 1;
                break;

            case 0:
                break;

            default:
                printf("\nOpcao Invalida!!!\n");
        }

    } while (opcao != 0);

    if (alterou != 0) {
        printf("\nAlteracao realizada com sucesso!!!\n");
    }
}

//Consultar Fornecedor
void consul_forn() {
    char cnpj_busca[100];

    printf("\n========================================================\n");
    printf("        CORTE IMPERIAL - CONSULTAR FORNECEDOR           \n");
    printf("========================================================\n");

    printf("\nDigite o CNPJ do Fornecedor: ");
    fflush(stdin);
    gets(cnpj_busca);

    exibir_forn();
}

//Excluir Fornecedor
void excl_forn() {
    int esc;
    char cnpj_busca[100];

    printf("\nDigite o CNPJ do Fornecedor: ");
    fflush(stdin);
    gets(cnpj_busca);

    printf("\n----- CNPJ ENCONTRADO!!! ------\n");
    exibir_forn();

    do {
        printf("\nVoce tem certeza de que deseja excluir esse Fornecedor?\n");
        printf("Esta acao nao pode ser desfeita.\n\n");
        printf(" [1] Confirmar\n");
        printf(" [0] Cancelar\n");
        scanf("%d", &esc);

        if (esc == 1)
            printf("\nFornecedor Excluido com Sucesso!!!\n");
        else if (esc == 0)
            printf("\nOperacao Cancelada!\n");
        else
            printf("\nOpcao invalida!!!\n");

    } while (esc != 1 && esc != 0);
}

/* FUNCOES PRODUTOS */

void exibirProduto() {
    printf("\n--------------------------------------------");
    printf("\nNome do Produto: teste");
    printf("\nUnidade de medida: UN");
    printf("\nMarca do Produto: teste");
    printf("\nQuantidade em estoque: 10.00");
    printf("\nCategoria do Produto: 1");
    printf("\nCodigo do produto: 1");
    printf("\n--------------------------------------------\n");
}

void cadastrarProduto() {
    int opcao = -1;
    char descricao[TF], medida[TFR], marca[TF];
    int categoriaCod;

    printf("\n---------CADASTRO DE PRODUTO-----------\n");
    while (opcao != 0) {
        printf("Deseja cadastrar? \n");
        printf("[1] Continuar\n[0] Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                getchar();

                printf("Nome do produto: ");
                fgets(descricao, sizeof(descricao), stdin);

                printf("Unidade de medida (ex: UN, KG, M�, LT): ");
                fgets(medida, sizeof(medida), stdin);

                printf("Marca do produto: ");
                fgets(marca, sizeof(marca), stdin);

                printf("Categoria do produto: \n");
                printf("[1] Bovino\n[2] Lacteo\n[3] Domestico\n");
                scanf("%d", &categoriaCod);

                printf("\nProduto cadastrado!\nCodigo do produto: %d\n\n", 1);
                break;

            case 0:
                printf("\n[Saindo...]\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente\n");
                break;
        }
    }
}

void alterarProduto() {
    int opcao, op;
    char descricao[TF], medida[TFR], marca[TF];
    float qtd;
    int categoriaCod;

    printf("\n---------ALTERAR PRODUTO-----------\n");
    printf("Deseja alterar algum produto?");
    printf("\n[1] Continuar\n[0] Sair\n");
    scanf("%d", &opcao);

    while (opcao != 0) {
        printf("Selecione o produto pelo codigo dele.\n");
        printf("[0] Voltar\n");
        printf("Codigo: ");
        scanf("%d", &opcao);

        switch (opcao != 0) {
            case 1:
                do {
                    printf("\n--------------------------------------------");
                    printf("\nNome do Produto: teste");
                    printf("\nUnidade de medida: UN");
                    printf("\nMarca do Produto: teste");
                    printf("\nQuantidade em estoque: 10.00");
                    printf("\nCategoria do Produto: 1");
                    printf("\nCodigo do produto: %d", opcao);
                    printf("\n--------------------------------------------\n");
                    printf("\nDeseja alterar alguma informacao?\n");
                    printf("[1] Alterar nome\n[2] Alterar unidade de medida\n");
                    printf("[3] Alterar marca\n[4] Alterar quantidade\n[5] Alterar categoria\n[0] Voltar\n");

                    scanf("%d", &op);

                    switch (op) {
                        case 1:
                            getchar();
                            printf("Novo nome: ");
                            fgets(descricao, sizeof(descricao), stdin);
                            printf("\nNome alterado com sucesso! Deseja realizar mais alguma alteracao?");
                            printf("\n[1] Continuar\n[0] Sair\n");
                            scanf("%d", &op);
                            break;

                        case 2:
                            getchar();
                            printf("Nova unidade de medida: ");
                            fgets(medida, sizeof(medida), stdin);
                            printf("\nUnidade de medida alterada com sucesso! Deseja realizar mais alguma alteracao?");
                            printf("\n[1] Continuar\n[0] Sair\n");
                            scanf("%d", &op);
                            break;

                        case 3:
                            getchar();
                            printf("Nova marca: ");
                            fgets(marca, sizeof(marca), stdin);
                            printf("\nMarca alterada com sucesso! Deseja realizar mais alguma alteracao?");
                            printf("\n[1] Continuar\n[0] Sair\n");
                            scanf("%d", &op);
                            break;

                        case 4:
                            printf("Nova quantidade em estoque: ");
                            scanf("%f", &qtd);
                            printf("\nQuantidade alterada com sucesso! Deseja realizar mais alguma alteracao?");
                            printf("\n[1] Continuar\n[0] Sair\n");
                            scanf("%d", &op);
                            break;

                        case 5:
                            printf("Nova categoria: \n");
                            printf("[1] Bovino\n[2] Lacteo\n[3] Domestico\n");
                            scanf("%d", &categoriaCod);
                            printf("\nCategoria alterada com sucesso! Deseja realizar mais alguma alteracao?");
                            printf("\n[1] Continuar\n[0] Sair\n");
                            scanf("%d", &op);
                            break;

                        case 0:
                            printf("\n[Saindo...]\n");
                            break;

                        default:
                            printf("\nOpcao invalida!\n");
                            break;
                    }

                } while (op != 0);
                break;

            case 0:
                break;
        }
    }
}

void consultarProduto() {
    int op, opC;
    char busca[TS];

    printf("\n---------CONSULTAR PRODUTO-----------\n");
    printf("Deseja consultar algum produto?");
    printf("\n[1] Continuar\n[0] Sair\n");
    scanf("%d", &op);

    while (op != 0) {
        printf("\nSelecione uma opcao de busca.\n");
        printf("[1] Buscar pelo nome\n[2] Buscar pela categoria\n[3] Buscar pela marca\n[4] Buscar pela unidade de medida\n[0] Voltar\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                getchar();
                printf("\nDigite o nome do produto: ");
                fgets(busca, sizeof(busca), stdin);

				exibirProduto();
                break;

            case 2:
                printf("\nSelecione a categoria do produto: \n");
                printf("[1] Bovino\n[2] Lacteo\n[3] Domestico\n");
                scanf("%d", &opC);

                exibirProduto();
                break;

            case 3:
                getchar();
                printf("\nDigite o nome da marca do produto: ");
                fgets(busca, sizeof(busca), stdin);

                exibirProduto();
                break;

            case 4:
                getchar();
                printf("\nDigite a unidade de medida abreviada: ");
                fgets(busca, sizeof(busca), stdin);

                exibirProduto();
                break;

            case 0:
                break;
        }
    }
}

void excluirProduto() {
    int op, prodCod;

    printf("\n---------EXCLUIR PRODUTO-----------\n");
    printf("Deseja excluir algum produto?");
    printf("\n[1] Continuar\n[0] Sair\n");
    scanf("%d", &op);

    while (op != 0) {
        printf("Procure o produto pelo codigo.\n");
        printf("Codigo: ");
        scanf("%d", &prodCod);

        printf("\n--------------------------------------------");
        printf("\nNome do Produto: teste");
        printf("\nUnidade de medida: UN");
        printf("\nMarca do Produto: teste");
        printf("\nQuantidade em estoque: 10.00");
        printf("\nCategoria do Produto: Bovino");
        printf("\nCodigo do produto: %d", prodCod);
        printf("\n--------------------------------------------\n");

        printf("\nRealmente deseja excluir o produto?\n");
        printf("[1] Excluir\n[0] Voltar\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nProduto deletado com sucesso.\n");
                printf("\n[0] Sair\n");
                scanf("%d", &op);
                break;

            case 0:
                break;
        }
    }
}

void gerenciarMarcas() {
    int op;

    printf("\n---------GERENCIAR MARCAS-----------\n");
    printf("Deseja consultar as marcas dos produtos do sistema?");
    printf("\n[1] Continuar\n[0] Sair\n");
    scanf("%d", &op);

    while (op != 0) {
        printf("\n--------------------------------------------\n");
        printf("teste 1\n");
        printf("teste 2\n");
        printf("teste 3\n");
        printf("--------------------------------------------\n");
        printf("\n[0] Sair\n");
        scanf("%d", &op);
    }
}

void gerenciarCategorias() {
    int op;

    printf("\n---------GERENCIAR CATEGORIAS-----------\n");
    printf("Deseja consultar as categorias dos produtos do sistema?");
    printf("\n[1] Continuar\n[0] Sair\n");
    scanf("%d", &op);

    while (op != 0) {
        printf("\n--------------------------------------------\n");
        printf("Bovino\n");
        printf("Lacteo\n");
        printf("Domestico\n");
        printf("--------------------------------------------\n");
        printf("\n[0] Sair\n");
        scanf("%d", &op);
    }
}

// FUNCOES ASSINATURAS

void criarAssinatura() {
    int op;
    int idCliente, status;
    char plano[TF];
    int dia, mes, ano;

    printf("\n---------CRIAR ASSINATURA PARA CLIENTE-----------\n");
    printf("Deseja criar uma assinatura para um cliente?");
    printf("\n[1] Continuar\n[0] Sair\n");
    scanf("%d", &op);

    while (op != 0) {
        printf("Informe o ID do cliente que recebera a assinatura: ");
        scanf("%d", &idCliente);

        getchar();
        printf("Informe o plano da assinatura: ");
        fgets(plano, sizeof(plano), stdin);

        printf("Informe a data de vencimento da assinatura (dia mes ano): ");
        scanf("%d %d %d", &dia, &mes, &ano);

        printf("Informe o status da assinatura: \n");
        printf("[1] Ativo\n[2] Em periodo de teste\n");
        scanf("%d", &status);

        printf("\nAssinatura para o cliente [%d] criada!\n", idCliente);

        printf("\n[1] Continuar criando\n[0] Sair\n");
        scanf("%d", &op);
    }
}

void renovarAssinatura() {
    int op, idCliente;

    printf("\n---------RENOVAR ASSINATURA-----------\n");
    printf("Deseja renovar uma assinatura?");
    printf("\n[1] Continuar\n[0] Sair\n");
    scanf("%d", &op);

    while (op != 0) {
        printf("Informe o ID do cliente: ");
        scanf("%d", &idCliente);

        printf("\nAssinatura do cliente [%d] renovada com sucesso!\n", idCliente);

        printf("\n[1] Continuar\n[0] Sair\n");
        scanf("%d", &op);
    }
}

void consultarStatus() {
    int op, idCliente;

    printf("\n---------CONSULTAR STATUS DA ASSINATURA-----------\n");
    printf("Deseja consultar o status de uma assinatura?");
    printf("\n[1] Continuar\n[0] Sair\n");
    scanf("%d", &op);

    while (op != 0) {
        printf("Informe o ID do cliente: ");
        scanf("%d", &idCliente);

        printf("\nStatus da assinatura do cliente [%d]: ATIVA\n", idCliente);

        printf("\n[1] Continuar\n[0] Sair\n");
        scanf("%d", &op);
    }
}

void consultarVencimento() {
    int op;

    printf("\n---------LISTAR PROXIMAS DO VENCIMENTO-----------\n");
    printf("Deseja consultar assinaturas próximas do vencimento?");
    printf("\n[1] Continuar\n[0] Sair\n");
    scanf("%d", &op);

    while (op != 0) {
        printf("\ncliente 1 - vencimento: 10/12/2025\n");
        printf("cliente 2 - vencimento: 15/12/2025\n");
        printf("cliente 3 - vencimento: 20/12/2025\n");

        printf("\n[1] Consultar novamente\n[0] Sair\n");
        scanf("%d", &op);
    }
}

// FUNCOES VENDAS 

void atualizarVenda() {
    int cod;
    printf("\n--- ATUALIZAR STATUS ---\n");
    printf("\nDigite o codigo de um pedido: ");
    scanf("%d", &cod);

    do {
        switch (cod) {
            case 1:
                printf(" [1] Recebido\n");
                printf(" [2] Em Preparo\n");
                printf(" [3] Pronto (Retirada)\n");
                printf(" [4] Saiu para Entrega\n");
                printf(" [5] Finalizado\n");
                printf(" Selecione o novo status: ");
                scanf(" %d", &cod);
                printf("\nStatus atualizado com sucesso!\n");
                printf("\n [1] Atualizar novamente\n [0] Sair\n");
                scanf(" %d", &cod);
                break;
        }
    } while (cod != 0);
}

void exibirStatusPedido() {
    int cod;
    printf("\n--- EXIBIR STATUS ---\n");
    printf("\nDigite o codigo de um pedido: ");
    scanf("%d", &cod);

    do {
        switch (cod) {
            case 1:
                printf("\n Status do Pedido: Entregue\n");
                printf("\n [0] Sair\n");
                scanf(" %d", &cod);
                break;

            case 0:
                printf("\nCodigo invalido!\n");
                printf("\n [1] Tentar novamente\n [0] Sair\n");
                scanf("%d", &cod);
                break;
        }
    } while (cod != 0);
}

void confirmarRetirada() {
    int cod;
    printf("\n--- CONFIRMAR RETIRADA ---\n");
    printf("\nDigite o codigo de um pedido: ");
    scanf("%d", &cod);

    do {
        switch (cod) {
            case 1:
                printf("\n Dados do pedido: \n");
                printf("\n--------------------------------------------\n");
                printf("\n--------------------------------------------\n");
                printf("\n [1] Confirmar a retirada\n [0] Voltar\n");
                scanf(" %d", &cod);

                switch (cod) {
                    case 1:
                        printf("\nRetirada confirmada com sucesso!\n");
                        printf("\n[0] Sair\n");
                        scanf(" %d", &cod);
                        break;

                    case 0:
                        break;
                }
                break;

            case 0:
                printf("\nCodigo invalido!\n");
                printf("\n [1] Tentar novamente\n [0] Sair\n");
                scanf("%d", &cod);
                break;
        }
    } while (cod != 0);
}

void confirmarEntrega() {
    int cod;
    printf("\n--- CONFIRMAR ENTREGA ---\n");
    printf("\nDigite o codigo de um pedido: ");
    scanf("%d", &cod);

    do {
        switch (cod) {
            case 1:
                printf("\n Dados do pedido: \n");
                printf("\n--------------------------------------------\n");
                printf("\n--------------------------------------------\n");
                printf("\n [1] Confirmar a entrega\n [0] Voltar\n");
                scanf(" %d", &cod);

                switch (cod) {
                    case 1:
                        printf("\nEntrega confirmada com sucesso!\n");
                        printf("\n[0] Sair\n");
                        scanf(" %d", &cod);
                        break;

                    case 0:
                        break;
                }
                break;

            case 0:
                printf("\nCodigo invalido!\n");
                printf("\n [1] Tentar novamente\n [0] Sair\n");
                scanf("%d", &cod);
                break;
        }
    } while (cod != 0);
}

void finalizarPedido() {

}

// FUNCOES RELATORIOS GERENCIONAIS

void exibirVendasPeriodo() {
    int op;
    
    do {
        printf("\n--- VENDAS POR PERIODO ---\n");
        printf("\nSelecione um dos periodos.\n");
        printf(" [1] Carnaval\n");
        printf(" [2] Pascoa\n");
        printf(" [3] Copa do mundo 2026\n");
        printf(" [4] Natal\n");
        printf(" [5] Reveillon\n");
        printf(" [0] Voltar\n");
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                printf("\n--------------------------------------------\n");
                printf("Vendas do periodo: CARNAVAL\n");
                printf("\nVenda <1>\n");
                printf("\n--------------------------------------------\n");
                printf("\nVenda <1>\n");
                printf("\n--------------------------------------------\n");
                break;
            
            case 2:
                printf("\n--------------------------------------------\n");
                printf("Vendas do periodo: PASCOA\n");
                printf("\nVenda <1>\n");
                printf("\n--------------------------------------------\n");
                printf("\nVenda <1>\n");
                printf("\n--------------------------------------------\n");
                break;
            
            case 3:
                printf("\n--------------------------------------------\n");
                printf("Vendas do periodo: COPA DO MUNDO 2026\n");
                printf("\nVenda <1>\n");
                printf("\n--------------------------------------------\n");
                printf("\nVenda <1>\n");
                printf("\n--------------------------------------------\n");
                break;
            
            case 4:
                printf("\n--------------------------------------------\n");
                printf("Vendas do periodo: NATAL\n");
                printf("\nVenda <1>\n");
                printf("\n--------------------------------------------\n");
                printf("\nVenda <1>\n");
                printf("\n--------------------------------------------\n");
                break;
            
            case 5:
                printf("\n--------------------------------------------\n");
                printf("Vendas do periodo: REVEILLON\n");
                printf("\nVenda <1>\n");
                printf("\n--------------------------------------------\n");
                printf("\nVenda <1>\n");
                printf("\n--------------------------------------------\n");
                break;
                
            default:
                printf("\nOpcao invalida!\n");
                break;
        } 
    } while(op != 0);
}

void exibirProdutosQTDBaixo() {
    printf("\n--- PRODUTOS COM ESTOQUE BAIXO ---\n");
    
    printf("\n--------------------------------------------");
    printf("\nProduto: teste -- QTD: 0");
    printf("\nProduto: teste -- QTD: 0");
    printf("\nProduto: teste -- QTD: 0");
    printf("\nProduto: teste -- QTD: 0");
    printf("\n--------------------------------------------\n");
}

void exibirTicket() {
    printf("\n--- TICKET MEDIO POR CLIENTE ---\n");

    printf("\nCliente: Joao\n");
    printf("Total gasto: R$ 300.00\n");
    printf("Quantidade de compras: 3\n");
    printf("Ticket medio: R$ 100.00\n");

    printf("\nCliente: Maria\n");
    printf("Total gasto: R$ 200.00\n");
    printf("Quantidade de compras: 2\n");
    printf("Ticket medio: R$ 100.00\n");
}

int main() {
    int opcoes, subOpcoes;
    int op_pess, op_cli, op_forn;

    do {
        system("cls");
        exibirMenuInicial();
        scanf("%d", &opcoes);

        switch (opcoes) {
            case 1: // MENU PESSOAS
                do {
                    exibirMenuPessoas();
                    scanf("%d", &op_pess);

                    switch (op_pess) {
                        case 1: // CLIENTES
                            do {
                                menu_cli();
                                scanf("%d", &op_cli);

                                switch (op_cli) {
                                    case 1:
                                        cad_cli();
                                        break;

                                    case 2:
                                        alterar_cli();
                                        break;

                                    case 3:
                                        consul_cli();
                                        break;

                                    case 4:
                                        excl_cli();
                                        break;

                                    case 0:
                                        break;

                                    default:
                                        printf("Opcao invalida!!!\n");
                                }

                            } while (op_cli != 0);
                            break;

                        case 2: // FORNECEDORES
                            do {
                                menu_forn();
                                scanf("%d", &op_forn);

                                switch (op_forn) {
                                    case 1:
                                        cad_forn();
                                        break;

                                    case 2:
                                        alterar_forn();
                                        break;

                                    case 3:
                                        consul_forn();
                                        break;

                                    case 4:
                                        excl_forn();
                                        break;

                                    case 0:
                                        break;

                                    default:
                                        printf("Opcao invalida!!!\n");
                                }

                            } while (op_forn != 0);
                            break;

                        case 0:
                            break;

                        default:
                            printf("\nOpcao invalida! Tente novamente.\n");
                            break;
                    }

                } while (op_pess != 0);
                break;

            case 2: // MENU PRODUTOS
                do {
                    exibirMenuProdutos();
                    scanf("%d", &subOpcoes);

                    switch (subOpcoes) {
                        case 1:
                            cadastrarProduto();
                            break;

                        case 2:
                            alterarProduto();
                            break;

                        case 3:
                            consultarProduto();
                            break;

                        case 4:
                            excluirProduto();
                            break;

                        case 5:
                            gerenciarMarcas();
                            break;

                        case 6:
                            gerenciarCategorias();
                            break;

                        case 0:
                            break;

                        default:
                            printf("\nOpcao invalida! Tente novamente.\n");
                            break;
                    }

                } while (subOpcoes != 0);
                break;

            case 3: // MENU ASSINATURAS
                do {
                    exibirMenuAssinaturas();
                    scanf("%d", &subOpcoes);

                    switch (subOpcoes) {
                        case 1:
                            criarAssinatura();
                            break;

                        case 2:
                            renovarAssinatura();
                            break;

                        case 3:
                            consultarStatus();
                            break;

                        case 0:
                            break;

                        default:
                            printf("\nOpcao invalida! Tente novamente.\n");
                            break;
                    }

                } while (subOpcoes != 0);
                break;

            case 4: // MENU VENDAS
                do {
                    exibirMenuVendas();
                    scanf("%d", &subOpcoes);

                    switch (subOpcoes) {
                        case 1:
                            exibirStatusPedido();
                            break;

                        case 2:
                            atualizarVenda();
                            break;

                        case 3:
                            confirmarRetirada();
                            break;

                        case 4:
                            confirmarEntrega();
                            break;

                        case 5:
                            finalizarPedido();
                            break;

                        case 0:
                            break;

                        default:
                            printf("\nOpcao invalida! Tente novamente.\n");
                            break;
                    }

                } while (subOpcoes != 0);
                break;

            case 5: // MENU RELATORIOS
                do {
                    exibirMenuRelatorios();
                    scanf("%d", &subOpcoes);

                    switch (subOpcoes) {
                        case 0:
                            break;

                        case 1:
                            exibirVendasPeriodo();
                            break;

                        case 2:
                            exibirProdutosQTDBaixo();
                            break;
                        
                        case 3:
                            exibirTicket();
                            break;
                        
                        case 4:
                            consultarVencimento();
                            break;

                        	break;
                        default:
                            printf("\nOpcao invalida!\n");
                            break;
                    }

                } while (subOpcoes != 0);
                break;

            case 0:
                printf("\n\n[Saindo do sistema...]\n\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcoes != 0);

    return 0;
}
