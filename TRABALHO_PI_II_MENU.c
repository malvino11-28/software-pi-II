#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TF 100
#define TFR 15
#define TS 1000

//STRUCTS GERAIS

typedef struct {

    int dia, mes, ano;

} DATA;

typedef struct {
    
    char rua[100], bairro[50], cidade[100], estado[2], cep[10];
    int num;
    
} ENDERECO;

typedef struct {
    
    char email[100], tel[20];
    
} CONTATO;

//STRUCTS CADASTRO PESSOAS

typedef struct {
    
    DATA nasc;
    ENDERECO end_cad;
    CONTATO ctt_cad;
    char nome[100], cpf[14], rg[12];
    
} CADASTRO;

// struct Produto -  id, nome, medida, marca, categoria, data_validade
typedef struct {
	int id;
	char nome[TF], medida[TFR], marca[TF], categoria[TF], Data validade; 
} PRODUTO;

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

int busca(FILE *fp, char cpf[]) {
    
    CADASTRO cli;
    
    rewind(fp);
    fread(&cli, sizeof(CADASTRO), 1, fp);
    while(!feof(fp) && stricmp(cpf, cli.cpf) != 0){
        
        fread(&cli, sizeof(CADASTRO), 1, fp);
    }
    if(!feof(fp)){
        
        return (ftell(fp) - sizeof(CADASTRO));
        
    } else {
        
        return -1;
    }
}

//Cadastro Clientes
void cad_cli() {
    
    CADASTRO cli;
    int pos;
    
    FILE *fp;
    fp = fopen("cadastros.bin", "ab+");
    if(fp == NULL){
        
        printf("Erro na ABERTURA do arquivo");
        
    } else {
        
        do{
            printf("\n========================================================\n");
            printf("         CORTE IMPERIAL - CADASTRAR CLIENTES            \n");
            printf("========================================================\n");
        
            printf("\nDigite o Nome Completo: "); fflush(stdin);
            gets(cli.nome);
            printf("\nDigite o CPF: "); fflush(stdin);
            gets(cli.cpf);
            
            pos = busca(fp, cli.cpf);
            if(pos == -1) {
                
                printf("\nDigite o RG: "); fflush(stdin);
                gets(cli.rg);
                printf("\nDigite a Data de Nascimento (dd mm aaaa): ");
                scanf("%d%d%d", &cli.nasc.dia, &cli.nasc.mes, &cli.nasc.ano);
                printf("\nDigite o Rua: "); fflush(stdin);
                gets(cli.end_cad.rua);
                printf("\nDigite o No: ");
                scanf("%d", &cli.end_cad.num);
                printf("\nDigite o Bairro: "); fflush(stdin);
                gets(cli.end_cad.bairro);
                printf("\nDigite a Cidade: "); fflush(stdin);
                gets(cli.end_cad.cidade);
                printf("\nDigite o Estado (SP): "); fflush(stdin);
                gets(cli.end_cad.estado);
                printf("\nDigite o CEP: "); fflush(stdin);
                gets(cli.end_cad.cep);
                printf("\nDigite o E-mail: "); fflush(stdin);
                gets(cli.ctt_cad.email);
                printf("\nDigite o Telefone: "); fflush(stdin);
                gets(cli.ctt_cad.tel);
                fwrite(&cli, sizeof(CADASTRO), 1, fp);
            	printf("\n----------------------------------------------\n");
                printf("\nCadastro realizado com sucesso!!!\n");
                
            } else {

                fseek(fp, pos, 0);
                fread(&cli, sizeof(CADASTRO), 1, fp);
                printf("\nCPF ja cadastrado no sistema.");
                system("pause");
            }
            
            printf("\nDeseja continuar S/N ");

        } while(toupper(getche()) == 'S');
        fclose(fp);
    }
}
//perguntar pra prof se podemos fazer uma funcao que receba como parametro a posicao da info no arquivo binario afim de exibir direto as info
//Para buscar o cliente que sera alterado / Colocar dentro da funcao alterar_forc*
// void exibir_cli() {
    
//     CADASTRO cli;
    
//     FILE *fp;
//     fp = fopen("cadastros.bin", "rb");
//     if(fp == NULL){
        
//         printf("Erro na ABERTURA do arquivo.");
        
//     } else {
        
//         system("cls");
//         while(fread(&cli, sizeof(CADASTRO), 1, fp) == 1) {

//             printf("\nNome Completo: %s", cli.nome);
//             printf("\nCPF: %s", cli.cpf);
//             printf("\nRG: %s", cli.rg);
//             printf("\nData de Nascimento: %d/%d/%d", cli.end_cad.dia, cli.end_cad.mes, cli.end_cad.ano);
//             printf("\nRua: %s", cli.end_cad.rua);
//             printf("\nNº: %d", cli.end_cad.num);
//             printf("\nBairro: %s", cli.end_cad.bairro);
//             printf("\nCidade: %s", cli.end_cad.cidade);
//             printf("\nEstado: %s", cli.end_cad.estado);
//             printf("\nCEP: %s", cli.end_cad.cep);
//             printf("\nE-mail: %s", cli.ctt_cad.email);
//             printf("\nTelefone: %s", cli.ctt_cad.tel);
//             printf("----------------------------------------------\n");
//             printf("\n");
//         }
//     }
//     fclose(fp);
//     system("pause");
//     system("cls");
// }

//Alterar Cadastro Cliente
void alterar_cli() {
    
    CADASTRO cli;
    int pos, op;

    FILE *fp;
    fp = fopen("cadastros.bin", "rb+");
    if(fp == NULL){

        printf("Erro na ABERTURA do arquivo.");

    } else {

        system("cls");
        printf("\n========================================================\n");
        printf("           CORTE IMPERIAL - ALTERAR CLIENTE             \n");
        printf("========================================================\n");

        printf("\nDigite o CPF do Cliente: "); fflush(stdin);
        gets(cli.cpf);
        while(stricmp(cli.cpf, "") != 0) {
            
            pos = busca(fp, cli.cpf);
            if(pos == -1){

                printf("\nCliente Nao Cadastrado.");
            
            } else {

                fseek(fp, pos, 0);
                fread(&cli, sizeof(CADASTRO), 1, fp);
                printf("\nNome Completo: %s", cli.nome);
                printf("\nRG: %s", cli.rg);
                printf("\nData de Nascimento: %d/%d/%d", cli.nasc.dia, cli.nasc.mes, cli.nasc.ano);
                printf("\nRua: %s", cli.end_cad.rua);
                printf("\nNº: %d", cli.end_cad.num);
                printf("\nBairro: %s", cli.end_cad.bairro);
                printf("\nCidade: %s", cli.end_cad.cidade);
                printf("\nEstado: %s", cli.end_cad.estado);
                printf("\nCEP: %s", cli.end_cad.cep);
                printf("\nE-mail: %s", cli.ctt_cad.email);
                printf("\nTelefone: %s", cli.ctt_cad.tel);
                printf("\n----------------------------------------------\n");

                printf("\nQual informacao voce deseja alterar?\n\n");
                printf("  [1] Nome Completo    [2] RG              [3] Data de Nascimento\n");
                printf("  [4] Rua              [5] Numero          [6] Bairro\n");
                printf("  [7] Cidade           [8] Estado          [9] CEP\n");
                printf("  [10] E-mail          [11] Telefone\n");
                printf("\n  [0] Voltar\n");
                printf("\n----------------------------------------------\n");
                printf("Selecione uma opcao: ");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        printf("\nDigite o novo Nome Completo: "); fflush(stdin);
                        gets(cli.nome);
                        fseek(fp,pos,0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\nRegistro Atualizado com Sucesso!\n\n");
                        system("pause");
                        break;

                    case 2:
                        printf("\nDigite o novo RG: "); fflush(stdin);
                        gets(cli.rg);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\nRegistro Atualizado com Sucesso!\n\n");
                        system("pause");
                        break;

                    case 3:
                        printf("\nDigite a nova Data de Nascimento: ");
                        scanf("%d%d%d", &cli.nasc.dia, &cli.nasc.mes, &cli.nasc.ano);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\nRegistro Atualizado com Sucesso!\n\n");
                        system("pause");
                        break;

                    case 4:
                        printf("\nDigite a nova Rua: "); fflush(stdin);
                        gets(cli.end_cad.rua);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\nRegistro Atualizado com Sucesso!\n\n");
                        system("pause");
                        break;

                    case 5:
                        printf("\nDigite o novo No: ");
                        scanf("%d", &cli.end_cad.num);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\nRegistro Atualizado com Sucesso!\n\n");
                        system("pause");
                        break;

                    case 6:
                        printf("\nDigite o novo Bairro: "); fflush(stdin);
                        gets(cli.end_cad.bairro);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\nRegistro Atualizado com Sucesso!\n\n");
                        system("pause");
                        break;

                    case 7:
                        printf("\nDigite a nova Cidade: "); fflush(stdin);
                        gets(cli.end_cad.cidade);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("Registro Atualizado com Sucesso!\n\n");
                        system("pause");
                        break;

                    case 8:
                        printf("\nDigite o novo Estado: "); fflush(stdin);
                        gets(cli.end_cad.estado);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\nRegistro Atualizado com Sucesso!\n\n");
                        system("pause");
                        break;

                    case 9:
                        printf("\nDigite o novo CEP: "); fflush(stdin);
                        gets(cli.end_cad.cep);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\nRegistro Atualizado com Sucesso!\n");
                        system("pause");
                        break;

                    case 10:
                        printf("\nDigite o novo E-mail: "); fflush(stdin);
                        gets(cli.ctt_cad.email);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\nRegistro Atualizado com Sucesso!\n");
                        system("pause");
                        break;

                    case 11:

                        printf("\nDigite o novo Telefone: "); fflush(stdin);
                        gets(cli.ctt_cad.tel);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\nRegistro Atualizado com Sucesso!\n");
                        system("pause");
                        break;

                    case 0:
                        break;

                    default:
                        printf("\nOpcao Invalida!!!");
                        break;
                }
            }
            system("cls");
            printf("\nDigite o CPF do Cliente: "); fflush(stdin);
            gets(cli.cpf);
        }
        fclose(fp);
    }
}

//Consultar Cliente
void consul_cli() {

    CADASTRO cli;
    int pos;
    
    FILE *fp;
    fp = fopen("cadastros.bin", "rb");
    if(fp == NULL){
        
        printf("Erro na ABERTURA do arquivo.");
        
    } else {
        
        printf("\n========================================================\n");
        printf("          CORTE IMPERIAL - CONSULTAR CLIENTE            \n");
        printf("========================================================\n");

        printf("\nDigite o CPF do Cliente: "); fflush(stdin);
        gets(cli.cpf);

        pos = busca(fp, cli.cpf);
        if(pos == -1){

            printf("\nCliente Nao Encontrado.");

        } else {

            fseek(fp, pos, 0);
            fread(&cli, sizeof(CADASTRO), 1, fp);
            printf("\nNome Completo: %s", cli.nome);
            printf("\nCPF: %s", cli.cpf);
            printf("\nRG: %s", cli.rg);
            printf("\nData de Nascimento: %d/%d/%d", cli.nasc.dia, cli.nasc.mes, cli.nasc.ano);
            printf("\nRua: %s", cli.end_cad.rua);
            printf("\nNo: %d", cli.end_cad.num);
            printf("\nBairro: %s", cli.end_cad.bairro);
            printf("\nCidade: %s", cli.end_cad.cidade);
            printf("\nEstado: %s", cli.end_cad.estado);
            printf("\nCEP: %s", cli.end_cad.cep);
            printf("\nE-mail: %s", cli.ctt_cad.email);
            printf("\nTelefone: %s", cli.ctt_cad.tel);
            printf("\n----------------------------------------------\n");
            printf("\n");
            system("pause");
        }
    }
    fclose(fp);
    system("cls");
}

//Excluir Cliente
void excl_cli() {

    CADASTRO cli;
    int pos;
    char cpf_busca[100];

    FILE *fp, *aux;
    fp = fopen("cadastros.bin", "rb");
    if(fp == NULL) {

        printf("Erro na ABERTURA do arquivo");

    } else {

        system("cls");
        printf("\nDigite o CPF do cliente que deseja excluir: "); fflush(stdin);
        gets(cpf_busca);
        pos = busca(fp, cpf_busca);
        if(pos == -1){

            printf("Cliente Nao Encontrado.");

        } else {

            fseek(fp, pos, 0);
            fread(&cli, sizeof(CADASTRO), 1, fp);
            printf("\nNome Completo: %s", cli.nome);
            printf("\nCPF: %s", cli.cpf);
            printf("\nRG: %s", cli.rg);
            printf("\nData de Nascimento: %d/%d/%d", cli.nasc.dia, cli.nasc.mes, cli.nasc.ano);
            printf("\nRua: %s", cli.end_cad.rua);
            printf("\nNº: %d", cli.end_cad.num);
            printf("\nBairro: %s", cli.end_cad.bairro);
            printf("\nCidade: %s", cli.end_cad.cidade);
            printf("\nEstado: %s", cli.end_cad.estado);
            printf("\nCEP: %s", cli.end_cad.cep);
            printf("\nE-mail: %s", cli.ctt_cad.email);
            printf("\nTelefone: %s", cli.ctt_cad.tel);
            printf("----------------------------------------------\n");
            printf("\nDeseja excluir esse cliente? (S/N): ");
            if(toupper(getche()) == 'S'){

                aux = fopen("auxiliar.bin", "wb");
                rewind(fp);
                while(fread(&cli, sizeof(CADASTRO), 1, fp) == 1) {
                    
                    if(strcmp(cli.cpf, cpf_busca) != 0){
                        fwrite(&cli, sizeof(CADASTRO), 1, aux);
                    }
                }
                fclose(aux);
                fclose(fp);
                remove("cadastros.bin");
                rename("auxiliar.bin", "cadastros.bin");
                printf("O cadastro foi excluido com sucesso!!! <ENTER para voltar ao menu");
                getchar();
                system("cls");

            } else {

                fclose(fp);
                printf("\nOperacao Cancelada.");
            }
        }
        
    }
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

void gerenciarMarcas() { // ok~
    int op, vazio = 1;
    PRODUTO p; // struct
    if (arc == NULL) printf("\nErro\n");
    else {
        printf("\n-------------------MARCAS---------------------\n");
        while (fread(&p, sizeof(PRODUTO), 1, arc)==1) {
            vazio = 0;
            printf("%s", p.marca);
        }
        if (vazio == 1) {
        printf("\n[Nenhuma marca cadastrada]\n");
        }
        printf("--------------------------------------------\n");
        printf("\n[0] Sair\n");
        scanf("%d", &op);
        }
}

void gerenciarCategorias() { //ok~
    int op, vazio = 1;
    PRODUTO p; //struct
    FILE *arc = fopen("produtos.bin", "rb");
    if (arc == NULL) printf("\nErro\n");
    else {
        printf("\n--------------CATEGORIAS----------------\n");
        while (fread(&p, sizeof(PRODUTO), 1, arc)==1) {
            vazio = 0;
            printf("%s", p.categoria);
        }
        if (vazio == 1) {
        printf("\n[Nenhuma categoria cadastrada]\n");
        }
        printf("--------------------------------------------\n");
        printf("\n[0] Sair\n");
        scanf("%d", &op);
        }
}

/* FUNCOES ASSINATURAS */
typedef struct {// estarei deixando aqui por enquanto, depois vou mover la pra cima
    int idCliente;
    DATA d;
    char plano[TF], status[20];
} ASSINATURA;

void criarAssinatura() { // ok~
    int op, b;
    ASSINATURA a;
    CADASTRO c;
    FILE *cli, *arc = fopen("assinatura.bin", "ab+");
    if (arc == NULL) printf("\nErro\n");
    else {
        cli = fopen("cliente.bin", "rb");
        printf("\n---------CRIAR ASSINATURA PARA CLIENTE-----------\n");
        printf("Informe o ID do cliente que recebera a assinatura: ");
        scanf("%d", &c.id);
        b = buscarAssinatura(arc, &c.id);
        if (b == -1) printf("\n[ID de cleinte nao cadastrado]\n");
        else {
            a.idCliente = c.id; // vinculando
            getchar();
            printf("Informe o plano da assinatura: ");
            fgets(a.plano, sizeof(a.plano), stdin);
            a.plano[strcspn(a.plano, "\n")] = '\0';

            printf("Informe a data de vencimento da assinatura (dia mes ano): ");
            scanf("%d %d %d", &a.d.dia, &a.d.mes, &a.d.ano);

            getchar();
            printf("Informe o status da assinatura (Ativo/Teste/Inativo): \n");
            fgets(a.status, sizeof(a.status), stdin);
            a.status[strcspn(a.status, "\n")] = '\0';

            fwrite(&a, sizeof(ASSINATURA), 1, arc);
            printf("\n[Assinatura para o cliente [%d] criada!]\n", c.id);

            printf("\n[0] Sair\n");
            scanf("%d", &op);
        }
        fclose(arc);
        fclose(cli);
    }
}

void renovarAssinatura() { // ok~
    int op, b;
    ASSINATURA a;
    FILE *arc = fopen("assinatura.bin", "rb+");
    if (arc == NULL) printf("\nErro\n");
    else {
        printf("\n---------RENOVAR ASSINATURA-----------\n");

        printf("Informe o ID do cliente: ");
        scanf("%d", &a.idCliente);

        b = buscar(arc, a.idCliente);
        if (b == -1) printf("\n[ID nao cadastrado]\n");
        else {
            fseek(arc, b, SEEK_SET); 
            fread(&a, sizeof(ASSINATURA), 1, arc);
            if (stricmp(a.status, "Ativo") == 0) 
                printf("\n[Assinatura ja esta ativa. Nao precisa renovar!]\n");
            else {
                printf("\n--------------------------------------------\n");
                printf("Informe a nova data de vencimento da assinatura (dia mes ano): ");
                scanf("%d %d %d", &a.d.dia, &a.d.mes, &a.d.ano);
                strcpy(a.status, "Ativo");
                printf("--------------------------------------------\n");
                fseek(arc, b, SEEK_SET);
                fwrite(&a, sizeof(ASSINATURA), 1, arc);
                printf("\nAssinatura do cliente [%d] renovada com sucesso!\n", a.idCliente);
            }
            printf("\n[0] Sair\n");
            scanf("%d", &op);
        }
        fclose(arc);
    }
}

void consultarStatus() { // ok~
    int op;
    ASSINATURA a;
    FILE *arc = fopen("assinatura.bin", "rb");
    if (arc == NULL) printf("\nErro\n");
    else {
        printf("\n-----------CONSULTAR STATUS DA ASSINATURA-----------\n");
        while(fread(&a, sizeof(ASSINATURA), 1, arc)==1) 
            printf("Cliente [%d] | Plano: %s | Status: %s\n", a.idCliente, a.plano, a.status);
        printf("--------------------------------------------\n");
        printf("\n[0] Sair\n");
        scanf("%d", &op);
        fclose(arc);
    }
}

void consultarVencimento() { // ok~
    int op;
    int mes, ano;
    ASSINATURA a;
    FILE *arc = fopen("assinatura.bin", "rb");
    if (arc == NULL) printf("\nErro\n");
    else {
    printf("\n---------LISTAR PROXIMAS DO VENCIMENTO-----------\n");
        // pede apenas o mes e o ano que o usuario quer checar
        printf("\nDigite o mes e o ano que deseja consultar (Ex: 12 2026): ");
        scanf("%d %d", &mes, &ano);
        

        printf("\n--- ASSINATURAS QUE VENCEM EM %d/%d ---\n", mes, ano);
        int encontrou = 0;
        while (fread(&a, sizeof(ASSINATURA), 1, arc) == 1) {
            // verifica se o mes e o ano da assinatura forem iguais ao que o usuario digitou
            if (a.d.mes == mes && a.d.ano == ano) {
                printf("Cliente [%d] | Plano: %s | Vence em: %d/%d/%d\n", a.idCliente, a.plano, a.d.dia, a.d.mes, a.d.ano);
                encontrou = 1;
            }
        }

        if (!encontrou) {
            printf("\n[Nenhuma assinatura proxima do vencimento]\n");
        }

        printf("---------------------------------------------------\n");
        fclose(arc);
        
        printf("\n[0] Voltar ao menu principal\n");
        scanf("%d", &op);
        }
}

/* FUNCOES VENDAS */ 
typedef struct { // depois levo la pra cima
    int id;
    char descricao[100];
    float valorTotal;
    char status[20]; 
} PEDIDO;

int buscarPedido(FILE *arc, int cod) { // ok~
    PEDIDO p;
    rewind(arc); 
    while (!feof(arc)&&p.id == cod) 
        fread(&p, sizeof(PEDIDO), 1, arc)
    if (!feof(arc))
        return (ftell(arc)-sizeof(PEDIDO));
    return -1;
}

void cadastrarPedido() { // ok~
    int op;
    PEDIDO p;
    FILE *arc = fopen("pedidos.bin", "ab+");
    
    if (arc == NULL) printf("\nErro\n");
    else {
        printf("\n--- CADASTRAR PEDIDO ---\n");
        printf("Digite o id do pedido: ");
        scanf("%d", &p.id);

        int b = buscarPedido(arc, p.id);

        if (b != -1) {
            printf("\n[ID de pedido ja cadastrado!]\n");
        } else {
            getchar(); 
            printf("Descricao os itens: ");
            fgets(p.descricao, sizeof(p.descricao), stdin); // esta assim por enquanto, mas acho que vou mudar o jeito de colocar os itens
            p.descricao[strcspn(p.descricao, "\n")] = '\0';
            
            printf("Valor total: R$ ");
            scanf("%f", &p.valorTotal);
            
            strcpy(p.status, "Recebido");// pedido comecando com "Recebido"
            
            fwrite(&p, sizeof(PEDIDO), 1, arc);
            printf("\n[Pedido [%d] cadastrado com sucesso!]\n", p.id);
            
            printf("\n[0] Sair\n");
            scanf("%d", &op);
        }
        fclose(arc);
    }
}

void atualizarVenda() { // ok~
    int op, opStatus;
    int b;
    PEDIDO p;
    FILE *arc = fopen("pedidos.bin", "rb+");
    
    if (arc == NULL) printf("\nErro\n");
    else {
        printf("\n--- ATUALIZAR STATUS ---\n");
        printf("Digite o id de um pedido: ");
        scanf("%d", &p.id);
        
        b = buscarPedido(arc, p.id);
        if (b == -1) 
            printf("\n[Pedido nao cadastrado]\n");
        else {
            fseek(arc, b, 0);
            fread(&p, sizeof(PEDIDO), 1, arc);
            
            printf("\nStatus atual: %s\n", p.status);
            printf(" [1] Recebido\n");
            printf(" [2] Em Preparo\n");
            printf(" [3] Pronto (Retirada)\n");
            printf(" [4] Saiu para Entrega\n");
            printf(" [5] Finalizado\n");
            printf(" Selecione o novo status: ");
            scanf("%d", &opStatus);
            
            switch (opStatus) {
                case 1: strcpy(p.status, "Recebido"); break;
                case 2: strcpy(p.status, "Em Preparo"); break;
                case 3: strcpy(p.status, "Pronto (Retirada)"); break;
                case 4: strcpy(p.status, "Saiu para Entrega"); break;
                case 5: strcpy(p.status, "Finalizado"); break;
                default: printf("\n[Opcao invalida]\n"); break;
            }
            
            if (opStatus == 1 || opStatus == 2 || opStatus == 3 || opStatus == 4 || opStatus == 5) {
                fseek(arc, b, 0);
                fwrite(&p, sizeof(PEDIDO), 1, arc);
                printf("\n[Status atualizado com sucesso]\n");
            }
            
            printf("\n[0] Sair\n");
            scanf("%d", &op);
        }
        fclose(arc);
    }
}

void exibirStatusPedido() { // ok~
    int op, cod;
    int b;
    PEDIDO p;
    FILE *arc = fopen("pedidos.bin", "rb");
    
    if (arc == NULL) {
        printf("\nErro ao abrir o arquivo\n");
    } else {
        printf("\n--- EXIBIR STATUS ---\n");
        printf("Digite o id de um pedido: ");
        scanf("%d", &cod);
        
        b = buscarPedido(arc, cod);
        if (b == -1) {
            printf("\n[Pedido nao cadastrado]\n");
        } else {
            fseek(arc, b, 0);
            fread(&p, sizeof(PEDIDO), 1, arc);
            
            printf("\n Status do Pedido [%d]: %s\n", p.id, p.status);
            printf("--------------------------------------------\n");
            
            printf("\n[0] Sair\n");
            scanf("%d", &op);
        }
        fclose(arc);
    }
}

void confirmarRetirada() { // ok~
    int op, cod;
    int b;
    PEDIDO p;
    FILE *arc = fopen("pedidos.bin", "rb+");
    
    if (arc == NULL) {
        printf("\nErro ao abrir o arquivo\n");
    } else {
        printf("\n--- CONFIRMAR RETIRADA ---\n");
        printf("Digite o id de um pedido: ");
        scanf("%d", &cod);
        
        b = buscarPedido(arc, cod);
        if (b == -1) {
            printf("\n[Pedido nao cadastrado]\n");
        } else {
            fseek(arc, b, 0);
            fread(&p, sizeof(PEDIDO), 1, arc);
            
            printf("\n Dados do pedido: \n");
            printf("--------------------------------------------\n");
            printf("Itens: %s | Valor: R$ %.2f | Status: %s\n", p.descricao, p.valorTotal, p.status);
            printf("--------------------------------------------\n");
            
            printf("\n [1] Confirmar a retirada\n [0] Voltar\n");
            scanf("%d", &op);
            
            if (op == 1) {
                strcpy(p.status, "Finalizado");
                fseek(arc, b, 0);
                fwrite(&p, sizeof(PEDIDO), 1, arc);
                printf("\n[Retirada confirmada com sucesso]\n");
            }
            
            printf("\n[0] Sair\n");
            scanf("%d", &op);
        }
        fclose(arc);
    }
}

void confirmarEntrega() { // ok~
    int op, cod;
    int b;
    PEDIDO p;
    FILE *arc = fopen("pedidos.bin", "rb+");
    
    if (arc == NULL) {
        printf("\nErro ao abrir o arquivo\n");
    } else {
        printf("\n--- CONFIRMAR ENTREGA ---\n");
        printf("Digite o id de um pedido: ");
        scanf("%d", &cod);
        
        b = buscarPedido(arc, cod);
        if (b == -1) {
            printf("\n[Pedido nao cadastrado]\n");
        } else {
            fseek(arc, b, 0);
            fread(&p, sizeof(PEDIDO), 1, arc);
            
            printf("\n Dados do pedido: \n");
            printf("--------------------------------------------\n");
            printf("Itens: %s | Valor: R$ %.2f | Status: %s\n", p.descricao, p.valorTotal, p.status);
            printf("--------------------------------------------\n");
            
            printf("\n [1] Confirmar a entrega\n [0] Voltar\n");
            scanf("%d", &op);
            
            if (op == 1) {
                strcpy(p.status, "Finalizado");
                fseek(arc, b, 0);
                fwrite(&p, sizeof(PEDIDO), 1, arc);
                printf("\nEntrega confirmada com sucesso!\n");
            }
            
            printf("\n[0] Sair\n");
            scanf("%d", &op);
        }
        fclose(arc);
    }
}

void finalizarPedido() { // pedido esta com umas funcoes que talvez sejam redundantes, depois eu ajeito, vou finalizar os outros primeiro
    int op;
    PEDIDO p;
    FILE *arc = fopen("pedidos.bin", "rb");
    
    if (arc == NULL) {
        printf("\nErro ao abrir o arquivo\n");
    } else {
        printf("\n----------- TODOS OS PEDIDOS FINALIZADOS -----------\n");
        int encontrou = 0;
        while(fread(&p, sizeof(PEDIDO), 1, arc) == 1) {
            if (strcmp(p.status, "Finalizado") == 0) {
                printf("Pedido [%d] | Itens: %s | Total: R$ %.2f\n", p.id, p.descricao, p.valorTotal);
                encontrou = 1;
            }
        }
        if (!encontrou) {
            printf("\n[Nenhum pedido finalizado encontrado]\n");
        }
        printf("----------------------------------------------------\n");
        printf("\n[0] Sair\n");
        scanf("%d", &op);
        fclose(arc);
    }
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
