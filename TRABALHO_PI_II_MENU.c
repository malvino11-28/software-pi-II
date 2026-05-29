#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

#define TF 100
#define TFR 15
#define TS 1000

//STRUCTS GERAIS

typedef struct {

    int dia, mes, ano;

} DATA;

typedef struct {
    
    char rua[100], bairro[50], cidade[100], estado[3], cep[10];
    int num;
    
} ENDERECO;

typedef struct {
    
    char email[100], tel[20];
    
} CONTATO;

//STRUCTS CADASTRO PESSOAS (cli) / FORNECEDOR (forn)
typedef struct {
    
    DATA nasc;
    ENDERECO end_cad;
    CONTATO ctt_cad;
    char nome[100], cpf[15], rg[12];
    char razaoSoc[200], nomeFant[200], cnpj[18];
    
} CADASTRO;

// struct Produto -  id, nome, medida, marca, categoria
typedef struct {
	int id, qtd;
	char nome[TF], medida[TFR], marca[TF], categoria[TF]; 
    float valor;
} PRODUTO;

void exibirMenuInicial() {
    system("cls");
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
    system("cls");
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
    system("cls");
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
    system("cls");
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
    system("cls");
    printf("\n==============================================\n");
    printf("           CORTE IMPERIAL - PRODUTOS          \n");
    printf("==============================================\n");
    printf("  [1] Cadastrar Produto\n");
    printf("  [2] Alterar Produto\n");
    printf("  [3] Listar Todos os Produtos\n");
    printf("  [4] Consultar Produto\n");
    printf("  [5] Excluir Produto\n");
    printf("  [6] Gerenciar Marcas\n");
    printf("  [7] Gerenciar Categorias\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------------\n");
    printf(" Selecione uma opcao: ");
}

void exibirMenuAssinaturas() {
    system("cls");
    printf("\n==============================================\n");
    printf("          CORTE IMPERIAL - ASSINATURAS        \n");
    printf("==============================================\n");
    printf("  [1] Criar Assinatura para Cliente\n");
    printf("  [2] Renovar Assinatura\n");
    printf("  [3] Consultar Status da Assinatura\n");
    printf("  [4] Listar Todas as Assinaturas\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------------\n");
    printf(" Selecione uma opcao: ");
}

void exibirMenuVendas() {
    system("cls");
    printf("\n==============================================\n");
    printf("            CORTE IMPERIAL - VENDAS           \n");
    printf("==============================================\n");
    printf("  [1] Cadastrar Pedido\n");
    printf("  [2] Visualizar Status do Pedido\n");
    printf("  [3] Atualizar Status do Pedido\n");
    printf("  [4] Confirmar Retirada\n");
    printf("  [5] Confirmar Entrega\n");
    printf("  [6] Listar todos os produtos\n");
    printf("  [7] Listar Pedidos Finalizados\n");
    printf("  [0] Voltar\n");
    printf("----------------------------------------------\n");
    printf(" Selecione uma opcao: ");
}

void exibirMenuRelatorios() { 
    system("cls");	
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

// Esta orndenando os clientes por nome
void ordenar_cli() {
    CADASTRO vet[100];
    CADASTRO aux;
    int total = 0, i, j;

    FILE *fp;
    fp = fopen("cadastros.bin", "rb");
    if(fp == NULL) return;
    while(fread(&vet[total], sizeof(CADASTRO), 1, fp) == 1)
        total++;
    fclose(fp);

    for(i = 0; i < total - 1; i++) {
        for(j = 0; j < total - 1 - i; j++) {
            if(stricmp(vet[j].nome, vet[j+1].nome) > 0) {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }

    fp = fopen("cadastros.bin", "wb");
    for(i = 0; i < total; i++)
        fwrite(&vet[i], sizeof(CADASTRO), 1, fp);
    fclose(fp);
}

//Cadastro Clientes
void cad_cli() {
    
    CADASTRO cli;
    int pos;
    int fechou = 0;
    
    FILE *fp;
    fp = fopen("cadastros.bin", "ab+");
    if(fp == NULL){
        
        printf("\n[Erro ao carregar o arquivo]\n");
        
    } else {
        
        do{
            fechou = 0;
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
                fclose(fp);
                fechou = 1;
                ordenar_cli();
                fp = fopen("cadastros.bin", "ab+");
                printf("\n----------------------------------------------\n");
                printf("\n[Cadastro realizado com sucesso]\n");
                
            } else {

                fseek(fp, pos, 0);
                fread(&cli, sizeof(CADASTRO), 1, fp);
                printf("\n[CPF ja cadastrado no sistema]");
                system("pause");
            }
            
            printf("\nDeseja continuar S/N ");

        } while(toupper(getche()) == 'S');
        
        if(!fechou) fclose(fp);
    }
}
//perguntar pra prof se podemos fazer uma funcao que receba como parametro a posicao da info no arquivo binario afim de exibir direto as info
//Para buscar o cliente que sera alterado / Colocar dentro da funcao alterar_forc*
// void exibir_cli() {
    
//     CADASTRO cli;
    
//     FILE *fp;
//     fp = fopen("cadastros.bin", "rb");
//     if(fp == NULL){
        
//         printf("\n[Erro ao carregar o arquivo]\n");
        
//     } else {
        
//         system("cls");
//         while(fread(&cli, sizeof(CADASTRO), 1, fp) == 1) {

//             printf("\nNome Completo: %s", cli.nome);
//             printf("\nCPF: %s", cli.cpf);
//             printf("\nRG: %s", cli.rg);
//             printf("\nData de Nascimento: %d/%d/%d", cli.end_cad.dia, cli.end_cad.mes, cli.end_cad.ano);
//             printf("\nRua: %s", cli.end_cad.rua);
//             printf("\nNo: %d", cli.end_cad.num);
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

        printf("\n[Erro ao carregar o arquivo]\n");

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

                printf("\n[Cliente nao cadastrado]");
            
            } else {

                fseek(fp, pos, 0);
                fread(&cli, sizeof(CADASTRO), 1, fp);
                printf("\nNome Completo: %s", cli.nome);
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
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 2:
                        printf("\nDigite o novo RG: "); fflush(stdin);
                        gets(cli.rg);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 3:
                        printf("\nDigite a nova Data de Nascimento: ");
                        scanf("%d%d%d", &cli.nasc.dia, &cli.nasc.mes, &cli.nasc.ano);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 4:
                        printf("\nDigite a nova Rua: "); fflush(stdin);
                        gets(cli.end_cad.rua);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 5:
                        printf("\nDigite o novo No: ");
                        scanf("%d", &cli.end_cad.num);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 6:
                        printf("\nDigite o novo Bairro: "); fflush(stdin);
                        gets(cli.end_cad.bairro);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 7:
                        printf("\nDigite a nova Cidade: "); fflush(stdin);
                        gets(cli.end_cad.cidade);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 8:
                        printf("\nDigite o novo Estado: "); fflush(stdin);
                        gets(cli.end_cad.estado);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 9:
                        printf("\nDigite o novo CEP: "); fflush(stdin);
                        gets(cli.end_cad.cep);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 10:
                        printf("\nDigite o novo E-mail: "); fflush(stdin);
                        gets(cli.ctt_cad.email);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 11:

                        printf("\nDigite o novo Telefone: "); fflush(stdin);
                        gets(cli.ctt_cad.tel);
                        fseek(fp, pos, 0);
                        fwrite(&cli, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 0:
                        break;

                    default:
                        printf("\n[Opcao invalida]");
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
    
    ordenar_cli();
    
    fp = fopen("cadastros.bin", "rb");
    if(fp == NULL){
        
        printf("\n[Erro ao carregar o arquivo]\n");
        
    } else {
        
        printf("\n========================================================\n");
        printf("          CORTE IMPERIAL - CONSULTAR CLIENTE            \n");
        printf("========================================================\n");

        printf("\nDigite o CPF do Cliente: "); fflush(stdin);
        gets(cli.cpf);

        pos = busca(fp, cli.cpf);
        if(pos == -1){

            printf("\n[Cliente nao encontrado]");

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

        printf("\n[Erro ao carregar o arquivo]\n");

    } else {

        system("cls");
        printf("\nDigite o CPF do cliente que deseja excluir: "); fflush(stdin);
        gets(cpf_busca);
        pos = busca(fp, cpf_busca);
        if(pos == -1){

            printf("\n[Cliente nao encontrado]");
            fclose(fp);

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
                printf("\n[Cadastro excluido com sucesso]\n<ENTER para voltar ao menu");
                getchar();
                system("cls");

            } else {

                fclose(fp);
                printf("\n[Operacao cancelada]");
            }
        }
        
    }
}

// FUNCOES PESSOAS - FORNECEDORES
int busca_forn(FILE *fp, char cnpj[]) {
    
    CADASTRO forn;
    
    rewind(fp);
    fread(&forn, sizeof(CADASTRO), 1, fp);
    while(!feof(fp) && stricmp(cnpj, forn.cnpj) != 0){
        
        fread(&forn, sizeof(CADASTRO), 1, fp);
    }
    if(!feof(fp)){
        
        return (ftell(fp) - sizeof(CADASTRO));
        
    } else {
        
        return -1;
    }
}

//Esta ordenando por razao social
void ordenar_forn() {
    CADASTRO vet[100];
    CADASTRO aux;
    int total = 0, i, j;

    FILE *fp;
    fp = fopen("cadastrosForn.bin", "rb");
    if(fp == NULL) return;
    while(fread(&vet[total], sizeof(CADASTRO), 1, fp) == 1)
        total++;
    fclose(fp);

    for(i = 0; i < total - 1; i++) {
        for(j = 0; j < total - 1 - i; j++) {
            if(stricmp(vet[j].razaoSoc, vet[j+1].razaoSoc) > 0) {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }

    fp = fopen("cadastrosForn.bin", "wb");
    for(i = 0; i < total; i++)
        fwrite(&vet[i], sizeof(CADASTRO), 1, fp);
    fclose(fp);
}

//Cadastro Fornecedores
void cad_forn() {

    CADASTRO forn;
    int pos;
    int fechou = 0;
    
    FILE *fp;
    fp = fopen("cadastrosForn.bin", "ab+");
    if(fp == NULL){
        
        printf("\n[Erro ao carregar o arquivo]\n");
        
    } else {
        
        do{
            fechou = 0;
            printf("\n========================================================\n");
            printf("         CORTE IMPERIAL - CADASTRAR FORNECEDORES            \n");
            printf("========================================================\n");
        
            printf("\nDigite o CNPJ: "); fflush(stdin);
            gets(forn.cnpj);
            
            pos = busca_forn(fp, forn.cnpj);
            if(pos == -1) {
                
                printf("\nDigite a Razao Social: "); fflush(stdin);
                gets(forn.razaoSoc);
                printf("\nDigite a Rua: "); fflush(stdin);
                gets(forn.end_cad.rua);
                printf("\nDigite o No: ");
                scanf("%d", &forn.end_cad.num);
                printf("\nDigite o Bairro: "); fflush(stdin);
                gets(forn.end_cad.bairro);
                printf("\nDigite a Cidade: "); fflush(stdin);
                gets(forn.end_cad.cidade);
                printf("\nDigite o Estado (SP): "); fflush(stdin);
                gets(forn.end_cad.estado);
                printf("\nDigite o CEP: "); fflush(stdin);
                gets(forn.end_cad.cep);
                printf("\nDigite o E-mail: "); fflush(stdin);
                gets(forn.ctt_cad.email);
                printf("\nDigite o Telefone: "); fflush(stdin);
                gets(forn.ctt_cad.tel);
                fwrite(&forn, sizeof(CADASTRO), 1, fp);
                fclose(fp);
                fechou = 1;
                ordenar_forn();
                fp = fopen("cadastrosForn.bin", "ab+");
            	printf("\n----------------------------------------------\n");
                printf("\n[Cadastro realizado com sucesso]\n");
                
            } else {

                fseek(fp, pos, 0);
                fread(&forn, sizeof(CADASTRO), 1, fp);
                printf("\n[CNPJ ja cadastrado no sistema]");
                system("pause");
            }
            
            printf("\nDeseja continuar S/N ");

        } while(toupper(getche()) == 'S');

        if(!fechou) fclose(fp); 
    }
}

// //Para buscar o CNPJ que sera alterado / Colocar dentro da funcao alterar_forc*
// void exibir_forn() {
//     printf("\nRazao Social: -------------SAIDA--------------\n");
//     printf("Nome Fantasia: ------------SAIDA--------------\n");
//     printf("Cidade: -------------------SAIDA--------------\n");
//     printf("Estado: -------------------SAIDA--------------\n");
//     printf("E-mail: -------------------SAIDA--------------\n");
//     printf("Telefone: -----------------SAIDA--------------\n");
// }

//Alterar Cadastro Fornecedor
void alterar_forn() {

    CADASTRO forn;
    int pos, op;

    FILE *fp;
    fp = fopen("cadastrosForn.bin", "rb+");
    if(fp == NULL){

        printf("\n[Erro ao carregar o arquivo]\n");

    } else {

        system("cls");
        printf("\n========================================================\n");
        printf("           CORTE IMPERIAL - ALTERAR FORNECEDOR             \n");
        printf("========================================================\n");

        printf("\nDigite o CNPJ do Cliente: "); fflush(stdin);
        gets(forn.cnpj);
        while(stricmp(forn.cnpj, "") != 0) {
            
            pos = busca_forn(fp, forn.cnpj);
            if(pos == -1){

                printf("\n[Fornecedor nao cadastrado]");
            
            } else {

                fseek(fp, pos, 0);
                fread(&forn, sizeof(CADASTRO), 1, fp);
                printf("\nRazao Social: %s", forn.razaoSoc);
                printf("\nNome Fantasia: %s", forn.nomeFant);
                printf("\nRua: %s", forn.end_cad.rua);
                printf("\nNo: %d", forn.end_cad.num);
                printf("\nBairro: %s", forn.end_cad.bairro);
                printf("\nCidade: %s", forn.end_cad.cidade);
                printf("\nEstado: %s", forn.end_cad.estado);
                printf("\nCEP: %s", forn.end_cad.cep);
                printf("\nE-mail: %s", forn.ctt_cad.email);
                printf("\nTelefone: %s", forn.ctt_cad.tel);
                printf("\n----------------------------------------------\n");

                printf("\nQual informacao voce deseja alterar?\n\n");
                printf("  [1] Razao Social     [2] Nome Fantasia     [3] Rua\n");
                printf("  [4] Numero           [5] Bairro            [6] Cidade\n");
                printf("  [7] Estado           [8] CEP               [9] E-mail\n");
                printf("  [10] Telefone        [0] Voltar\n");
                printf("\n----------------------------------------------\n");
                printf("Selecione uma opcao: ");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        printf("\nDigite a nova Razao Social: "); fflush(stdin);
                        gets(forn.razaoSoc);
                        fseek(fp,pos,0);
                        fwrite(&forn, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 2:
                        printf("\nDigite o novo Nome Fantasia: "); fflush(stdin);
                        gets(forn.nomeFant);
                        fseek(fp, pos, 0);
                        fwrite(&forn, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 3:
                        printf("\nDigite a nova Rua: "); fflush(stdin);
                        gets(forn.end_cad.rua);
                        fseek(fp, pos, 0);
                        fwrite(&forn, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 4:
                        printf("\nDigite o novo No: ");
                        scanf("%d", &forn.end_cad.num);
                        fseek(fp, pos, 0);
                        fwrite(&forn, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 5:
                        printf("\nDigite o novo Bairro: "); fflush(stdin);
                        gets(forn.end_cad.bairro);
                        fseek(fp, pos, 0);
                        fwrite(&forn, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 6:
                        printf("\nDigite a nova Cidade: "); fflush(stdin);
                        gets(forn.end_cad.cidade);
                        fseek(fp, pos, 0);
                        fwrite(&forn, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 7:
                        printf("\nDigite o novo Estado: "); fflush(stdin);
                        gets(forn.end_cad.estado);
                        fseek(fp, pos, 0);
                        fwrite(&forn, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 8:
                        printf("\nDigite o novo CEP: "); fflush(stdin);
                        gets(forn.end_cad.cep);
                        fseek(fp, pos, 0);
                        fwrite(&forn, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 9:
                        printf("\nDigite o novo E-mail: "); fflush(stdin);
                        gets(forn.ctt_cad.email);
                        fseek(fp, pos, 0);
                        fwrite(&forn, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 10:
                        printf("\nDigite o novo Telefone: "); fflush(stdin);
                        gets(forn.ctt_cad.tel);
                        fseek(fp, pos, 0);
                        fwrite(&forn, sizeof(CADASTRO), 1, fp);
                        printf("\n[Registro atualizado com sucesso]\n");
                        system("pause");
                        break;

                    case 0:
                        break;

                    default:
                        printf("\n[Opcao invalida]");
                        break;
                }
            }
            system("cls");
            printf("\nDigite o CNPJ do Fornecedor: "); fflush(stdin);
            gets(forn.cnpj);
        }
        fclose(fp);
    }
}

//Consultar Fornecedor
void consul_forn() {

    CADASTRO forn;
    int pos;
    
    FILE *fp;

    ordenar_forn(); 

    fp = fopen("cadastrosForn.bin", "rb");
    if(fp == NULL){
        
        printf("\n[Erro ao carregar o arquivo]\n");
        
    } else {
        
        printf("\n========================================================\n");
        printf("          CORTE IMPERIAL - CONSULTAR FORNECEDOR            \n");
        printf("========================================================\n");

        printf("\nDigite o CNPJ do Fornecedor: "); fflush(stdin);
        gets(forn.cnpj);

        pos = busca_forn(fp, forn.cnpj);
        if(pos == -1){

            printf("\n[Fornecedor nao encontrado]");

        } else {

            fseek(fp, pos, 0);
            fread(&forn, sizeof(CADASTRO), 1, fp);
            printf("\nRazao Social: %s", forn.razaoSoc);
            printf("\nNome Fantasia: %s", forn.nomeFant);
            printf("\nRua: %s", forn.end_cad.rua);
            printf("\nNo: %d", forn.end_cad.num);
            printf("\nBairro: %s", forn.end_cad.bairro);
            printf("\nCidade: %s", forn.end_cad.cidade);
            printf("\nEstado: %s", forn.end_cad.estado);
            printf("\nCEP: %s", forn.end_cad.cep);
            printf("\nE-mail: %s", forn.ctt_cad.email);
            printf("\nTelefone: %s", forn.ctt_cad.tel);
            printf("\n----------------------------------------------\n");
            printf("\n");
            system("pause");
        }
    }
    fclose(fp);
    system("cls");
}

//Excluir Fornecedor
void excl_forn() {

    CADASTRO forn;
    int pos;
    char cnpj_busca[100];

    FILE *fp, *aux;
    fp = fopen("cadastrosForn.bin", "rb");
    if(fp == NULL) {

        printf("\n[Erro ao carregar o arquivo]\n");

    } else {

        system("cls");
        printf("\nDigite o CNPJ do fornecedor que deseja excluir: "); fflush(stdin);
        gets(cnpj_busca);
        pos = busca_forn(fp, cnpj_busca);
        if(pos == -1){

            printf("\n[Fornecedor nao encontrado]");

        } else {

            fseek(fp, pos, 0);
            fread(&forn, sizeof(CADASTRO), 1, fp);
            printf("\nRazao Social: %s", forn.razaoSoc);
            printf("\nNome Fantasia: %s", forn.nomeFant);
            printf("\nRua: %s", forn.end_cad.rua);
            printf("\nNo: %d", forn.end_cad.num);
            printf("\nBairro: %s", forn.end_cad.bairro);
            printf("\nCidade: %s", forn.end_cad.cidade);
            printf("\nEstado: %s", forn.end_cad.estado);
            printf("\nCEP: %s", forn.end_cad.cep);
            printf("\nE-mail: %s", forn.ctt_cad.email);
            printf("\nTelefone: %s", forn.ctt_cad.tel);
            printf("----------------------------------------------\n");
            printf("\nDeseja excluir esse fornecedor? (S/N): ");
            if(toupper(getche()) == 'S'){

                aux = fopen("auxiliarForn.bin", "wb");
                rewind(fp);
                while(fread(&forn, sizeof(CADASTRO), 1, fp) == 1) {
                    
                    if(strcmp(forn.cnpj, cnpj_busca) != 0){
                        fwrite(&forn, sizeof(CADASTRO), 1, aux);
                    }
                }
                fclose(aux);
                fclose(fp);
                remove("cadastrosForn.bin");
                rename("auxiliarForn.bin", "cadastrosForn.bin");
                printf("\n[Cadastro excluido com sucesso]\n<ENTER para voltar ao menu");
                getchar();
                system("cls");

            } else {

                fclose(fp);
                printf("\n[Operacao cancelada]");
            }
        }
        
    }
}


/* FUNCOES PRODUTOS */

/* FUNCOES PRODUTOS */
// typedef struct {
// 	int id, qtd;
// 	char nome[TF], medida[TFR], marca[TF], categoria[TF]; 
//  float valor;
// } PRODUTO;

int buscarProduto(FILE *arc, int b) {
    PRODUTO p;
    rewind(arc);
    fread(&p, sizeof(PRODUTO), 1, arc);
    while (!feof(arc)&&b!=p.id)
        fread(&p, sizeof(PRODUTO), 1, arc);
    if (!feof(arc))
        return (ftell(arc)-sizeof(PRODUTO));
    else return -1;
}

void cadastrarProduto() {
    PRODUTO p;
    FILE *arc = fopen("produtos.bin", "ab+");
    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    else {
        printf("\n---------CADASTRO DE PRODUTO-----------\n");
        printf("\nDigite o ID do produto a ser cadastrado: ");
        scanf("%d", &p.id);
        int b = buscarProduto(arc, p.id);
        
        if (b != -1) printf("\n[ID do produto ja cadastrado]\n");
        else {
            getchar();

            printf("Nome do produto: ");
            fgets(p.nome, sizeof(p.nome), stdin);

            printf("Unidade de medida (ex: UN, KG, MC, LT): ");
            fgets(p.medida, sizeof(p.medida), stdin);

            printf("Marca do produto: ");
            fgets(p.marca, sizeof(p.marca), stdin);

            printf("Categoria do produto: ");
            fgets(p.categoria, sizeof(p.categoria), stdin);

            printf("Valor do produto: ");
            scanf("%f", &p.valor);

            printf("Quantidade de produto: ");
            scanf("%d", &p.qtd);

            fwrite(&p, sizeof(PRODUTO), 1, arc);
            printf("\n[Produto cadastrado]\n[Codigo do produto: %d]\n", p.id);
        }
        fclose(arc);
    }
}

void exibirProduto() {
    PRODUTO p;
    FILE *arc = fopen("produtos.bin", "rb");
    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    else {
        int prod = 0;
        while (fread(&p, sizeof(PRODUTO), 1, arc)==1) {
            printf("\n--------------------[%d]---------------------", p.id);
            printf("\nNome do Produto: %s", p.nome);
            printf("\nUnidade de medida: %s", p.medida);
            printf("\nMarca do Produto: %s", p.marca);
            printf("\nCategoria do Produto: %s", p.categoria);
            printf("\nValor do produto: %.2f", p.valor);
            printf("\nQuantidade em estoque: %d", p.qtd);
            printf("\n--------------------------------------------\n");
            prod = 1;
        }
        if (prod == 0) printf("\n[Sem produtos cadastrados]");
        fclose(arc);
    }
}

void alterarProduto() {
    int id, op, b;
    PRODUTO p; 
    FILE *arc = fopen("produtos.bin", "rb+"); 
    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    else {
        printf("\n---------ALTERAR PRODUTO-----------\n");
        printf("\nInforme o ID do produto a ser alterado: \n");
        scanf("%d", &id);
  
        b = buscarProduto(arc, id); 
        if (b == -1) printf("\n[ID nao cadastrado]\n");
        else {
            fseek(arc, b, 0); 
            fread(&p, sizeof(PRODUTO), 1, arc);
                printf("\n--------------------[%d]---------------------", p.id);
                printf("\nNome do Produto: %s", p.nome);
                printf("\nUnidade de medida: %s", p.medida);
                printf("\nMarca do Produto: %s", p.marca);
                printf("\nCategoria do Produto: %s", p.categoria); 
                printf("\nValor do produto: %.2f", p.valor);
                printf("\nQuantidade em estoque: %d", p.qtd);
                printf("\n--------------------------------------------\n");
                    
            do {
                printf("\nDeseja alterar alguma informacao?\n");
                printf("[1] Alterar nome\n[2] Alterar unidade de medida\n");
                printf("[3] Alterar marca\n[4] Alterar quantidade\n[5] Alterar categoria\n[6] Alterar valor\n[0] Salvar e Voltar\n");
                printf("Selecione uma opcao: ");
                scanf("%d", &op);

                    switch (op) {
                        case 1:
                            getchar();
                            printf("Novo nome: ");
                            fgets(p.nome, sizeof(p.nome), stdin);
                            printf("\n[Nome alterado localmente com sucesso]\n");
                        break;

                        case 2:
                            getchar();
                            printf("Nova unidade de medida: ");
                            fgets(p.medida, sizeof(p.medida), stdin);
                            printf("\n[Unidade de medida alterada localmente com sucesso]\n");
                        break;

                        case 3:
                            getchar();
                            printf("Nova marca: ");
                            fgets(p.marca, sizeof(p.marca), stdin);
                            printf("\n[Marca alterada com sucesso]\n");
                        break;

                        case 4:
                            printf("Nova quantidade em estoque: ");
                            scanf("%d", &p.qtd);
                            printf("\n[Quantidade alterada com sucesso]\n");
                        break;

                        case 5:
                        getchar(); // a mudar
                            printf("Nova categoria do produto: \n");
                            fgets(p.categoria, sizeof(p.categoria), stdin);
                            printf("\n[Categoria alterada com sucesso]\n");
                        break;

                        case 6:
                            printf("Novo valor do produto: ");
                            scanf("%f", &p.valor);
                            printf("\n[Valor alterado com sucesso]\n");
                        break;

                        case 0:
                            // Grava as alteracoes de volta no arquivo binario antes de sair
                            fseek(arc, b, 0);
                            fwrite(&p, sizeof(PRODUTO), 1, arc);
                            printf("\n[Alteracoes salvas no arquivo com sucesso]\n");
                        break;

                        default:
                            printf("\n[Opcao invalida]\n");
                            break;
                    }
                } while (op != 0);
            }

            printf("\n[0] Sair");
            scanf("%d", &op);
        }
        fclose(arc);
}

void consultarProduto() {
    int op, prod;
    PRODUTO p; 
    char busca[TS];
    
    FILE *arc = fopen("produtos.bin", "rb");
    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
   
    do {
    	rewind(arc); // voltando para o comeco do arquivo a cada nova busca
        printf("\n---------CONSULTAR PRODUTO-----------\n");
        printf("Selecione uma opcao de busca.\n");
        printf("[1] Buscar pelo nome\n[2] Buscar pela categoria\n[0] Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);
        
        while(getchar() != '\n'); 
        
        prod = 0; 
        switch (op) {
            case 1:
                printf("\nDigite o nome do produto: ");
                fgets(busca, sizeof(busca), stdin);

                printf("\n--- RESULTADOS DA BUSCA (NOME) ---");
                while (fread(&p, sizeof(PRODUTO), 1, arc) == 1) {
                    if (stricmp(p.nome, busca) == 0) { 
                        printf("\n--------------------[%d]---------------------", p.id);
                        printf("\nNome do Produto: %s", p.nome);
                        printf("\nUnidade de medida: %s", p.medida);
                        printf("\nMarca do Produto: %s", p.marca);
                        printf("\nCategoria do Produto: %s", p.categoria); 
                        printf("\nValor do produto: %.2f", p.valor);
                        printf("\nQuantidade em estoque: %d", p.qtd);
                        printf("\n--------------------------------------------\n");
                        prod = 1;
                    }
                }
                if (!prod) printf("\n[Nenhum produto encontrado com esse nome]\n");
                break;

            case 2:
                printf("\nDigite a categoria do produto: ");
                fgets(busca, sizeof(busca), stdin);

                printf("\n--- RESULTADOS DA BUSCA (CATEGORIA) ---");
                while (fread(&p, sizeof(PRODUTO), 1, arc) == 1) {
                    if (stricmp(p.categoria, busca) == 0) {
                        printf("\n--------------------[%d]---------------------", p.id);
                        printf("\nNome do Produto: %s", p.nome);
                        printf("\nUnidade de medida: %s", p.medida);
                        printf("\nMarca do Produto: %s", p.marca);
                        printf("\nCategoria do Produto: %s", p.categoria); 
                        printf("\nValor do produto: %.2f", p.valor);
                        printf("\nQuantidade em estoque: %d", p.qtd);
                        printf("\n--------------------------------------------\n");
                        prod = 1;
                    }
                }
                if (!prod) printf("\n[Nenhum produto cadastrado nesta categoria]\n");
                break;

            case 0:
                printf("\n[Voltando ao menu principal]\n");
                break;

            default:
                printf("\n[Opcao invalida]\n");
                break;
        }
        
    } while (op != 0);

    fclose(arc); 
}

void excluirProduto() {
    FILE *arc, *temp;
    PRODUTO p;
    int op, id, b;

    arc = fopen("produtos.bin", "rb");
    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    else {
        printf("\n---------EXCLUIR PRODUTO-----------\n");
        
        printf("\nInforme o ID do produto a ser alterado: \n");
        scanf("%d", &id);

        b = buscarProduto(arc, id); 
        if (b == -1) 
            printf("\n[ID nao cadastrado]\n");
        else {
            fseek(arc, b, 0);
            fread(&p, sizeof(PRODUTO), 1, arc);

            printf("\n--------------------[%d]---------------------", p.id);
            printf("\nNome do Produto: %s", p.nome);
            printf("\nUnidade de medida: %s", p.medida);
            printf("\nMarca do Produto: %s", p.marca);
            printf("\nCategoria do Produto: %s", p.categoria); 
            printf("\nValor do produto: %.2f", p.valor);
            printf("\nQuantidade em estoque: %d", p.qtd);
            printf("\n--------------------------------------------\n");

            printf("\nRealmente deseja excluir o produto?\n");
            printf("[1] Excluir\n[0] Voltar\n");
            printf("Opcao: ");
            scanf("%d", &op);

            if (op == 1) {
                temp = fopen("auxiliar.bin", "wb");
                if (temp == NULL) printf("\n[Erro ao carregar o arquivo]\n");
                else {
                    rewind(arc);
                    while (fread(&p, sizeof(PRODUTO), 1, arc) == 1) {
                        if (p.id!= id) { 
                            fwrite(&p, sizeof(PRODUTO), 1, temp);
                        }
                    }
                }
                fclose(temp);
                fclose(arc);

                remove("produtos.bin");
                rename("auxiliar.bin", "produtos.bin");

                printf("\n[Produto deletado com sucesso]\n");
            } 
            else 
                fclose(arc); 
        }
        printf("\n[0] Sair\n");
        scanf("%d", &op);
    }
}

// // // //

void gerenciarMarcas() { // ok~
    int op, vazio = 1;
    PRODUTO p; // struct
    FILE *arc = fopen("produtos.bin", "rb");
    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
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
            fclose(arc);
        }
}

void gerenciarCategorias() { //ok~
    int op, vazio = 1;
    PRODUTO p; //struct
    FILE *arc = fopen("produtos.bin", "rb");
    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
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
        fclose(arc);
        }
}

/* FUNCOES ASSINATURAS */
typedef struct {// estarei deixando aqui por enquanto, depois vou mover la pra cima
    char cpfCliente[15];
    DATA d;
    char plano[TF], status[20];
} ASSINATURA;

int buscarAssinatura(FILE *fp, char cpf[]) {
    
    ASSINATURA a;
    
    rewind(fp);
    fread(&a, sizeof(ASSINATURA), 1, fp);

    while(!feof(fp) && stricmp(cpf, a.cpfCliente) != 0){
        fread(&a, sizeof(ASSINATURA), 1, fp);
    }

    if(!feof(fp)){
        return (ftell(fp) - sizeof(ASSINATURA));
    } else {
        return -1;
    }
}

void criarAssinatura() { // ok~
    int op, b;
    ASSINATURA a;
    CADASTRO c;
    FILE *cli, *arc = fopen("assinatura.bin", "ab+");

    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    else {
        cli = fopen("cadastros.bin", "rb");
        if (cli == NULL) {
            printf("\n[Erro ao carregar o arquivo]\n");
            fclose(arc);
            return;
        }
        printf("\n---------CRIAR ASSINATURA PARA CLIENTE-----------\n");

        printf("Informe o CPF do cliente que recebera a assinatura: ");
        fflush(stdin);
        gets(c.cpf);

        b = busca(cli, c.cpf);

        if (b == -1) {
            printf("\n[CPF de cliente nao cadastrado]\n");
        } else {
            b = buscarAssinatura(arc, c.cpf);

            if (b != -1) {
                printf("\n[Cliente ja possui assinatura cadastrada]\n");
            } else {
                strcpy(a.cpfCliente, c.cpf);

                printf("Informe o plano da assinatura: ");
                fflush(stdin);
                gets(a.plano);

                printf("Informe a data de vencimento da assinatura (dia mes ano): ");
                scanf("%d %d %d", &a.d.dia, &a.d.mes, &a.d.ano);

                printf("Informe o status da assinatura (Ativo/Teste/Inativo): ");
                fflush(stdin);
                gets(a.status);

                fwrite(&a, sizeof(ASSINATURA), 1, arc);

                printf("\n[Assinatura para o cliente CPF %s criada]\n", a.cpfCliente);

                printf("\n[0] Sair\n");
                scanf("%d", &op);
            }
        }

        fclose(arc);
        fclose(cli);
    }
}

void renovarAssinatura() {
    int op, b;
    ASSINATURA a;
    FILE *arc = fopen("assinatura.bin", "rb+");

    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    else {
        printf("\n---------RENOVAR ASSINATURA-----------\n");

        printf("Informe o CPF do cliente: ");
        fflush(stdin);
        gets(a.cpfCliente);

        b = buscarAssinatura(arc, a.cpfCliente);

        if (b == -1) printf("\n[CPF nao cadastrado em assinatura]\n");
        else {
            fseek(arc, b, 0);
            fread(&a, sizeof(ASSINATURA), 1, arc);

            if (stricmp(a.status, "Ativo") == 0) {
                printf("\n[Assinatura ja esta ativa nao precisa renovar]\n");
            } else {
                printf("\n--------------------------------------------\n");
                printf("Informe a nova data de vencimento da assinatura (dia mes ano): ");
                scanf("%d %d %d", &a.d.dia, &a.d.mes, &a.d.ano);
                strcpy(a.status, "Ativo");
                printf("--------------------------------------------\n");

                fseek(arc, b, 0);
                fwrite(&a, sizeof(ASSINATURA), 1, arc);

                printf("\n[Assinatura do cliente CPF %s renovada com sucesso]\n", a.cpfCliente);
            }

            printf("\n[0] Sair\n");
            scanf("%d", &op);
        }

        fclose(arc);
    }
}
void consultarStatus() {
    int op;
    ASSINATURA a;
    FILE *arc = fopen("assinatura.bin", "rb");

    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    else {
        printf("\n-----------CONSULTAR STATUS DA ASSINATURA-----------\n");

        while(fread(&a, sizeof(ASSINATURA), 1, arc) == 1) {
            printf("Cliente CPF: %s | Plano: %s | Status: %s\n", 
                   a.cpfCliente, a.plano, a.status);
        }
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
    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
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
                printf("Cliente CPF: %s | Plano: %s | Vence em: %d/%d/%d\n", a.cpfCliente, a.plano, a.d.dia, a.d.mes, a.d.ano);
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

void ordenarAssinaturas() {
    int qtd = 0, i;
    ASSINATURA a, ax;
    FILE *arc = fopen("assinatura.bin", "rb+");
    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    else {
        fseek(arc, 0, 2);
        qtd = ftell(arc) / sizeof(ASSINATURA);

        while (qtd > 1){ // bubble sort
            for (i=0;i<qtd-1;i++) {
                fseek(arc, i * sizeof(ASSINATURA), 0); // lendo struct no arquivo na posicao I
                fread(&a, sizeof(ASSINATURA), 1, arc);

                fseek(arc, (i+1) * sizeof(ASSINATURA), 0);
                fread(&ax, sizeof(ASSINATURA), 1, arc);

                int dataInt1 = (a.d.ano * 10000) + (a.d.mes * 100) + a.d.dia;
                int dataInt2 = (ax.d.ano * 10000) + (ax.d.mes * 100) + ax.d.dia;
                if (dataInt1 < dataInt2) { // se a data atual for menor, inverter as posicoes 
                    fseek(arc, i * sizeof(ASSINATURA), 0);
                    fwrite(&ax, sizeof(ASSINATURA), 1, arc);

                    fseek(arc, (i+1) * sizeof(ASSINATURA), 0);
                    fwrite(&a, sizeof(ASSINATURA), 1, arc);
                }
            }
            qtd--;
        }
        fclose(arc);
    }
}


void listarAssinaturas() { // ok~
    int op;
    ASSINATURA a;
    FILE *arc;
    
    // ordena antes de exibir
    ordenarAssinaturas();
    
    arc = fopen("assinatura.bin", "rb");
    if (arc == NULL) {
        printf("\n[Erro ao carregar o arquivo]\n");
    } else {
        printf("\n-----------LISTA DE ASSINATURAS-----------\n");
        int assi = 0;
        
        while (fread(&a, sizeof(ASSINATURA), 1, arc) == 1) {
            assi = 1;
            printf("CPF Cliente: %s | Plano: %s | Vencimento: %02d/%02d/%04d | Status: %s\n", a.cpfCliente, a.plano, a.d.dia, a.d.mes, a.d.ano, a.status);
        }
        
        if (assi == 0) {
            printf("[Nenhuma assinatura encontrada para listagem]\n");
        }
        
        printf("-----------------------------------------------------\n");
        fclose(arc);
        
        printf("\n[0] Voltar ao menu principal\n");
        scanf("%d", &op);
    }
}


/* FUNCOES VENDAS */ 
typedef struct { // depois levo la pra cima
    int id;
    char descricao[TS], status[20], periodo[30]; // ex: carnaval
    char cpfCliente[15];
    float valorTotal; 
} PEDIDO;

int buscarPedido(FILE *arc, int cod) {
    PEDIDO p;
    rewind(arc);
    fread(&p, sizeof(PEDIDO), 1, arc);

    while (!feof(arc) && p.id != cod) 
        fread(&p, sizeof(PEDIDO), 1, arc);
    
    if (!feof(arc)) 
        return ftell(arc) - sizeof(PEDIDO);
    else return -1;
    
}

void cadastrarPedido() { // ok~
    int op, qtdItens, i;
    char item[200];
    PEDIDO p;
    PRODUTO prod;
    ASSINATURA c;
    FILE *arcC = fopen("assinatura.bin", "rb");
    FILE *arc = fopen("pedidos.bin", "ab+");
    FILE *arcP = fopen("produtos.bin", "rb");

    if (arcC == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    if (arcP == NULL) printf("\n[Erro ao carregar o arquivo]\n");
    else {
        if (arcC != NULL && arc != NULL) {
            printf("\n--- CADASTRAR PEDIDO ---\n");
            printf("Digite o id do pedido: ");
            scanf("%d", &p.id);
            
            int b = buscarPedido(arc, p.id);    
            if (b != -1) {
                printf("\n[ID de pedido ja cadastrado]\n");
            } else {
                getchar();
                printf("Digite o CPF do cliente do pedido: ");
                fflush(stdin);
                gets(p.cpfCliente);
                int bC = buscarAssinatura(arcC, p.cpfCliente);
                if (bC == -1) 
                    printf("\n[Cliente nao encontrado]\n");
                else {
                    fseek(arcC, bC, 0);
                    fread(&c, sizeof(ASSINATURA), 1, arcC);
                    if (stricmp(c.status, "Ativo")!=0 && stricmp(c.status, "Teste")!=0)
                        printf("\n[Cliente sem assinatura valida]\n");
                    else {
                        printf("\n---------------- PRODUTOS CADASTRADOS ----------------\n");
                        rewind(arcP);
                        while (fread(&prod, sizeof(PRODUTO), 1, arcP) == 1) {
                            printf("Produto: %s", prod.nome);
                            printf("Estoque: R$ %.2f | Marca: %s | Valor: %.2f\n", prod.valor, prod.marca prod.qtd);
                            printf("-------------------------------------------------------\n");
                        }

                        printf("\nInforme a quantidade de itens do pedido: ");
                        scanf("%d", &qtdItens);
                        getchar();

                        for (i = 0; i < qtdItens; i++) {
                            printf("Descricao do item %d (Produto: | QTD: | Marca: | Valor: ): ", i + 1);
                            fgets(item, sizeof(item), stdin);

                            if (strlen(p.descricao) + strlen(item) < sizeof(p.descricao)) {
                                strcat(p.descricao, item);
                            } else {
                                printf("\n[Limite da descricao atingido]\n");
                                i = qtdItens;
                            }
                        }
                        
                        printf("\nSelecione um dos periodos.\n");
                        printf(" [1] Carnaval\n");
                        printf(" [2] Pascoa\n");
                        printf(" [3] Copa do mundo 2026\n");
                        printf(" [4] Natal\n");
                        printf(" [5] Reveillon\n");
                        printf(" [0] Sem periodo\n");
                        scanf("%d", &op);
            
                        if (op == 1) strcpy(p.periodo, "Carnaval");
                        if (op == 2) strcpy(p.periodo, "Pascoa");
                        if (op == 3) strcpy(p.periodo, "Copa do mundo 2026");
                        if (op == 4) strcpy(p.periodo, "Natal");
                        if (op == 5) strcpy(p.periodo, "Reveillon");
                        if (op >= 6 || op <= 0) strcpy(p.periodo, "Sem periodo");
            
                        printf("Valor total: R$ ");
                        scanf("%f", &p.valorTotal);
                        
                        strcpy(p.status, "Recebido");
                        
                        fwrite(&p, sizeof(PEDIDO), 1, arc);
                        printf("\n[Pedido [%d] cadastrado com sucesso]\n", p.id);
                        
                        printf("\n[0] Sair\n");
                        scanf("%d", &op);
                    }
                }
            }
        }
    }

    if (arc != NULL) fclose(arc);
    if (arcC != NULL) fclose(arcC);
    if (arcP != NULL) fclose(arcP);
}

void atualizarVenda() { // ok~
    int op, opStatus;
    int b;
    PEDIDO p;
    FILE *arc = fopen("pedidos.bin", "rb+");

    if (arc == NULL) printf("\n[Erro ao carregar o arquivo]\n");
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
        printf("\n[Erro ao carregar o arquivo]\n");
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
        printf("\n[Erro ao carregar o arquivo]\n");
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
        printf("\n[Erro ao carregar o arquivo]\n");
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
                printf("\n[Entrega confirmada com sucesso]\n");
            }

            printf("\n[0] Sair\n");
            scanf("%d", &op);
        }
        fclose(arc);
    }
}

void ordenarPedidos() {
    PEDIDO p, px;
    int qtde = 0, i;
    
    FILE *arc = fopen("pedidos.bin", "rb+");
    if (arc == NULL) 
        printf("\n[Erro ao carregar o arquivo]\n");
    else {
        fseek(arc, 0, 2);
        qtde = ftell(arc) / sizeof(PEDIDO);
        
        while (qtde > 1) {
            for (i=0;i<qtde-1;i++) {
                
                fseek(arc, i * sizeof(PEDIDO), 0); 
                fread(&p, sizeof(PEDIDO), 1, arc);
                
                fseek(arc, (i + 1) * sizeof(PEDIDO), 0); // lendo elemento na posicao i + 1
                fread(&px, sizeof(PEDIDO), 1, arc);
                
                if (p.id > px.id) { // id crescente
                    fseek(arc, i * sizeof(PEDIDO), 0);
                    fwrite(&px, sizeof(PEDIDO), 1, arc);

                    fseek(arc, (i + 1) * sizeof(PEDIDO), 0);
                    fwrite(&p, sizeof(PEDIDO), 1, arc);
                }
            }
            qtde--;
        }
        fclose(arc);
    }
}

void listarPedidos() {
	ordenarPedidos(); // ordenando por ID
    int op;
    PEDIDO p;
    FILE *arc = fopen("pedidos.bin", "rb");
    if (arc == NULL) 
        printf("\n[Erro ao carregar o arquivo]\n");
    else {


        
            printf("\n-----------LISTA DE PEDIDOS-----------\n");
            int pedido = 0;
            
            while (fread(&p, sizeof(PEDIDO), 1, arc) == 1) {
                pedido = 1;
                printf("ID: [%d] | Itens: %s | Total: R$ %.2f | Status: %s\n", 
                        p.id, p.descricao, p.valorTotal, p.status);
            }
            
            if (!pedido) {
                printf("[Nenhum pedido encontrado no sistema]\n");
            }
            
            printf("--------------------------------------------------\n");
            fclose(arc);
            
            printf("\n[0] Voltar\n");
            scanf("%d", &op);
        }
    
}


void finalizarPedido() { // pedido esta com umas funcoes que talvez sejam redundantes, depois eu ajeito, vou finalizar os outros primeiro
    int op;
    PEDIDO p;
    FILE *arc = fopen("pedidos.bin", "rb");
    
    if (arc == NULL) {
        printf("\n[Erro ao carregar o arquivo]\n");
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


void exibirVendasPeriodo() { // ok?
    int op;
    PEDIDO p;
    FILE *arc;
    char periodo[30];
    
    do {
        printf("\n--- VENDAS POR PERIODO ---\n");
        printf(" [1] Carnaval\n");
        printf(" [2] Pascoa\n");
        printf(" [3] Copa do mundo 2026\n");
        printf(" [4] Natal\n");
        printf(" [5] Reveillon\n");
        printf(" [0] Voltar\n");
        printf("Selecione um dos periodos: ");
        scanf("%d", &op);

        switch (op) {
            case 1: strcpy(periodo, "Carnaval"); break;
            case 2: strcpy(periodo, "Pascoa"); break;
            case 3: strcpy(periodo, "Copa do mundo 2026"); break;
            case 4: strcpy(periodo, "Natal"); break;
            case 5: strcpy(periodo, "Reveillon"); break;
            case 0: break;
            default:
                printf("\n[Opcao invalida]\n");
            break;
        }
		if (op >= 1 && op <= 5) {
	        arc = fopen("pedidos.bin", "rb");
	        if (arc == NULL) 
	            printf("\n[Erro ao carregar o arquivo]\n");
	        else {
	            printf("\n--------------------------------------------\n");
	            printf("Vendas do periodo: %s\n",  periodo);
	            printf("--------------------------------------------\n");
	            ordenarPedidos();
	            int pedido = 0;
	            while (fread(&p, sizeof(PEDIDO), 1, arc) == 1) {
	                // compara o periodo com o periodo do pedido no arquivo, e verifica se ja foi finalizado/vendido
	                if (strcmp(p.status, "Finalizado") == 0 && strcmp(p.periodo, periodo) == 0) {
	                        printf("Pedido Cod: %d | Itens: %s | Total: R$ %.2f\n", p.id, p.descricao, p.valorTotal);
	                        pedido = 1;
	                    }
	            }
	            
	            if (!pedido) {
	                printf("[Nenhuma venda finalizada neste periodo]\n");
	            }
	            printf("--------------------------------------------\n");
	            fclose(arc);
	        }
    	}
    } while(op != 0);
}

void ordenarProdutos() {
    PRODUTO p, px;
    int qtde = 0, i;
    
    FILE *arc = fopen("produtos.bin", "rb+");
    if (arc == NULL) 
        printf("\n[Erro ao carregar o arquivo]\n");
    else {
        fseek(arc, 0, 2);
        qtde = ftell(arc) / sizeof(PRODUTO);
        
        while (qtde > 1) {
            for (i=0;i<qtde-1;i++) {
                
                fseek(arc, i * sizeof(PRODUTO), 0); 
                fread(&p, sizeof(PRODUTO), 1, arc);
                
                fseek(arc, (i + 1) * sizeof(PRODUTO), 0); // lendo elemento na posicao i + 1
                fread(&px, sizeof(PRODUTO), 1, arc);
                
                if (p.id > px.id) { // id crescente
                    fseek(arc, i * sizeof(PRODUTO), 0);
                    fwrite(&px, sizeof(PRODUTO), 1, arc);

                    fseek(arc, (i + 1) * sizeof(PRODUTO), 0);
                    fwrite(&p, sizeof(PRODUTO), 1, arc);
                }
            }
            qtde--;
        }
        fclose(arc);
    }
}

void exibirProdutosQTDBaixo() {
    int op;
    PRODUTO p;
    FILE *arc = fopen("produtos.bin", "rb");
    int baixo = 5; // a partir de 5 sera estoque baixo
    int prod = 0;
    
    printf("\n--- PRODUTOS COM ESTOQUE BAIXO (Abaixo de %d unidades) ---\n", baixo);
    
    if (arc == NULL) {
        printf("\n[Erro ao carregar o arquivo]\n");
    } else {
        printf("\n--------------------------------------------\n");
        while (fread(&p, sizeof(PRODUTO), 1, arc) == 1) {
            if (p.qtd <= baixo) {
                printf("ID: %d | Produto: %s -- QTD em Estoque: %d\n", p.id, p.nome, p.qtd);
                prod = 1;
            }
        }
        if (!prod) 
            printf("[Sem produto com estoque baixo]\n");

        printf("--------------------------------------------\n");

        fclose(arc);
    }
    printf("\n[0] Voltar\n");
    scanf("%d", &op);
}

void ordenarTicket() {
    PEDIDO p, px;
    int qtde = 0, i;
    
    FILE *arc = fopen("pedidos.bin", "rb+");
    if (arc == NULL) 
        printf("\n[Erro ao carregar o arquivo]\n");
    else {
        fseek(arc, 0, 2);
        qtde = ftell(arc) / sizeof(PEDIDO);
        
        while (qtde > 1) {
            for (i=0;i<qtde-1;i++) {
                
                fseek(arc, i * sizeof(PEDIDO), 0); 
                fread(&p, sizeof(PEDIDO), 1, arc);
                
                fseek(arc, (i + 1) * sizeof(PEDIDO), 0); // lendo elemento na posicao i + 1
                fread(&px, sizeof(PEDIDO), 1, arc);
                
                if (p.id > px.id) { // id crescente
                    fseek(arc, i * sizeof(PEDIDO), 0);
                    fwrite(&px, sizeof(PEDIDO), 1, arc);

                    fseek(arc, (i + 1) * sizeof(PEDIDO), 0);
                    fwrite(&p, sizeof(PEDIDO), 1, arc);
                }
            }
            qtde--;
        }
        fclose(arc);
    }
}

void exibirTicket() {
    int op;
    CADASTRO c; 
    PEDIDO p;
    FILE *arcC, *arcP;
    
    printf("\n--- TICKET MEDIO POR CLIENTE ---\n");
    printf("\n--------------------------------------------\n");

    arcC = fopen("cadastros.bin", "rb");
    if (arcC == NULL) 
        printf("\n[Erro ao carregar o arquivo]\n");
    else {
    	ordenarTicket();
        while (fread(&c, sizeof(CADASTRO), 1, arcC) == 1) {
            arcP = fopen("pedidos.bin", "rb");

            float totalGasto = 0;
            int qtdCompras = 0;
            
            if (arcP == NULL) 
                printf("\n[Erro ao carregar o arquivo]\n");
            else {
                while (fread(&p, sizeof(PEDIDO), 1, arcP) == 1) {
                    // caso o pedido seja do cliente (comparando id), e esteja finalizado
                    if (stricmp(p.cpfCliente, c.cpf) == 0 && strcmp(p.status, "Finalizado") == 0) {
                        totalGasto += p.valorTotal;
                        qtdCompras++;
                    }
                }
                fclose(arcP);
            }
            
            if (qtdCompras > 0) {
                float ticketMedio = totalGasto / qtdCompras;
                printf("Cliente CPF [%s]: %s\n", c.cpf, c.nome);
                printf("  Total gasto: R$ %.2f\n", totalGasto);
                printf("  Quantidade de compras: %d\n", qtdCompras);
                printf("  Ticket medio: R$ %.2f\n\n", ticketMedio);
            }
        }
    }
    fclose(arcC);

    printf("--------------------------------------------\n");
    printf("\n[0] Voltar\n");
    scanf("%d", &op);
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
                                        printf("\n[Opcao invalida]\n");
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
                                        printf("\n[Opcao invalida]\n");
                                }

                            } while (op_forn != 0);
                            break;

                        case 0:
                            break;

                        default:
                            printf("\n[Opcao invalida tente novamente]\n");
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
                exibirProduto();
                break;

            case 4:
                consultarProduto();
                break;

            case 5:
                excluirProduto();
                break;

            case 6:
                gerenciarMarcas();
                break;

            case 7:
                gerenciarCategorias();
                break;

            case 0:
                break;

            default:
                printf("\n[Opcao invalida tente novamente]\n");
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

            case 4:
                listarAssinaturas();
                break;

            case 0:
                break;

            default:
                printf("\n[Opcao invalida tente novamente]\n");
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
                cadastrarPedido();
                break;

            case 2:
                exibirStatusPedido();
                break;

            case 3:
                atualizarVenda();
                break;

            case 4:
                confirmarRetirada();
                break;

            case 5:
                confirmarEntrega();
                break;

			 case 6:
                listarPedidos();
                break;

            case 7:
                finalizarPedido();
                break;

            case 0:
                break;

            default:
                printf("\n[Opcao invalida tente novamente]\n");
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
                            printf("\n[Opcao invalida]\n");
                            break;
                    }

                } while (subOpcoes != 0);
                break;

            case 0:
                printf("\n\n[Saindo do sistema]\n\n");
                break;

            default:
                printf("\n[Opcao invalida tente novamente]\n");
                break;
        }

    } while (opcoes != 0);

    return 0;
}