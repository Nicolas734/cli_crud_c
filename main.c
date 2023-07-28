#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char nome[20];
    int preco;
} Produto_t;

typedef struct{
    char nome[20];
    char email[50];
    char senha[20];
    Produto_t compras[10];
} Usuario_t;

typedef struct{
    Produto_t produtos[20];
    Usuario_t clientes[20];
} Loja_t;


void opcoesClientes(void);
void opcoesProdutos(void);

Loja_t loja;
int qtd_clientes = 0;
int qtd_produtos = 0;

void main(void){
    int option;

    for(;;){
        printf("1 - Interface dos clientes\n");
        printf("2 - Interface dos produtos\n");
        printf("0 - Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            opcoesClientes();
            break;

        case 2:
            opcoesProdutos();
            break;

        case 0:
            printf("Saindo...\n");
            exit(0);
            break;

        default:
            break;
        }
    }

}


void opcoesClientes(void){
    int option;
    int execucao = 1;

    do{
        printf("1 - Cadastrar Clientes\n");
        printf("2 - Listar Clientes\n");
        printf("0 - Voltar\n");

        printf("Escolha uma opção: ");
        scanf("%d", &option);


        switch (option){
            case 1:
                Usuario_t cliente;
                printf("\nEscreva o nome: ");
                scanf("%s", cliente.nome);
                printf("\nEscreva o seu email: ");
                scanf("%s", cliente.email);
                printf("\nEscreva a sua senha: ");
                scanf("%s", cliente.senha);
                memcpy(&loja.clientes[qtd_clientes], &cliente, sizeof(Usuario_t));
                qtd_clientes++;
                break;

            case 2:
                printf("\n*** Clientes cadastrados no sistema ***\n");
                if(qtd_clientes > 0){
                    for (int i = 0; i < qtd_clientes; i++) {
                        printf("Nome: %s\n", loja.clientes[i].nome);
                        printf("Email: %s\n", loja.clientes[i].email);
                    }
                }else{
                    printf("\nNão possui clientes cadastrados\n");
                }
                break;

            case 0:
                return;
                !execucao;
                break;

            default:
                break;
        }

    }while(execucao);
}



void opcoesProdutos(){
    int option;
    int execucao = 1;

    do{
        printf("1 - Cadastrar Produtos\n");
        printf("2 - Mostrar Produtos\n");
        printf("0 - Voltar\n");

        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                Produto_t produto;
                printf("\nEscreva o nome do produto: ");
                scanf("%s", produto.nome);
                printf("\nEscreva o preço do produto: ");
                scanf("%d", &produto.preco);
                memcpy(&loja.produtos[qtd_produtos], &produto, sizeof(Produto_t));
                qtd_produtos++;
                break;
            case 2:
                printf("\n*** Produtos em estoque ***\n");
                if(qtd_produtos > 0){
                    for(int i = 0; i < qtd_produtos; i++){
                        printf("Nome: %s\n", loja.produtos[i].nome);
                        printf("Preço: $ %d\n", loja.produtos[i].preco);
                    }
                }else{
                    printf("\nNenhum produto em estoque\n");
                }
                break;
            case 0:
                return;
                break;
            default:
                break;
        }
    }while(execucao);

}
