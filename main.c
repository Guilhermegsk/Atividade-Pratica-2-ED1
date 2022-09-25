#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"
#define true 1
#define false 0

typedef struct _aluno_{
    char nome[30];
    int nchamada;
    float notas;
} Aluno;

int main(){
    Colecao *col;
    Aluno *va;//vetor para endereço da struct
    char nome[30];//variavel recebe o valor para nome
    float vnotas;//recebe o valor desejado pra notas
    int Escolha, opcao;// variaveis de escolha;
    int Key, n, indice;//N sendo o tamanho da colecao e tipo parametro para switch
    while(1){
        printf("\n\n 1-Criar colecao\n 2-Inserir na colecao\n 3-Remover da colecao\n 4-Verificar na colecao\n 5-Listar elementos da colecao\n 6-Destruir colecao\n 7-Esvaziar colecao\n 8-Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &Escolha);

        switch(Escolha){
            case 1:
                printf("\nO usuario escolheu criar a colecao.");
                printf("\nDefina o tamanho da colecao: ");
                scanf("%d", &n);
                col = colcreate(n);//cria a colecao
                if (colcreate(n)!=NULL){
                    printf("\n\nA colecao foi criada com %d de tamanho", n);
                } else{
                    printf("\n\nNao foi possivel criar a colecao!");
                }
                printf("\nPressione Enter para continuar!");
                while(getchar() != '\n');
                getchar();//espera o enter do usuario
                break;
            case 2:
                printf("\nO usuario escolheu inserir algo na colecao.");
                if(col == NULL){
                    printf("\nAloque primeiro a colecao!");
                    printf("\nPressione Enter para continuar!");
                    while(getchar() != '\n');
                    getchar();//espera o enter do usuario
                    break;
                }
                if(col->maxItens == col->numItens){//se a colecao esta cheia
                    printf("\nA colecao ja esta cheia!");
                    printf("\nPressione Enter para continuar!");
                    while(getchar() != '\n');
                    getchar();//espera o enter do usuario
                    break;
                }
                if(col!=NULL){
                    va = (Aluno *)malloc(sizeof(Aluno));// eh um endereco da struct
                    if(va!=NULL){
                    //armazena nos respectivos itens
                        printf("\nDigite o nome do aluno: ");
                        scanf("%s", va->nome);

                        printf("\nDigite o numero de chamada do aluno: ");
                        scanf("%d", &va->nchamada);

                        printf("\nDigite a nota do aluno: ");
                        scanf("%f", &va->notas);
                        colInsert(col, (void*)va);//va entrando na colecao disfacado de void*
                        printf("\nAluno %s, com identificacao %d e nota %.1f inserido com sucesso", va->nome, va->nchamada, va->notas);
                    }
                }
                printf("\n\nPressione Enter para continuar!");
                while(getchar() != '\n');
                getchar();//espera o enter do usuario
                break;
            case 3:
                printf("\nO usuario escolheu remover algo da colecao.");
                if(col == NULL){
                    printf("\nAloque primeiro a colecao!");
                    printf("\nPressione Enter para continuar!");
                    while(getchar() != '\n');
                    getchar();//espera o enter do usuario
                    break;
                }
                if(col->numItens<=0){//se ha algo
                    printf("\nA colecao esta vazia!");
                    break;
                }
                printf("Voce deseja procurar por: \n");
                printf("1 - Nome\n 2 - Numero de chamada \n 3 - Nota");
                printf("\n\nOpcao: ");
                scanf("%d", &opcao);

                switch(opcao){

                    case 1:
                        printf("\nDigite o nome a ser procurado: ");
                        scanf("%s", nome);
                        va = colQuery(col, (void*)nome, cmpString);//chamo a funcao colquery usando nome como chave
                        break;
                    case 2:
                        printf("\nDigite o numero de chamada do aluno: ");
                        scanf("%d", &Key);
                        va = colQuery(col, (void*)&Key, cmpInt);
                        break;
                    case 3:
                        printf("\n Digite a nota a procurar: ");
                        scanf("%f", &vnotas);
                        va = colQuery(col, (void*)&vnotas, cmpFloat);
                        break;
                    default:
                        printf("Digite uma opcao valida!");
                        break;
                }
                if(va != NULL){
                    printf("\n\nVoce deseja remover esse elemento da colecao:");
                    printf("\nNome: %s", va->nome);
                    printf("\nNumero da chamada: %d", va->nchamada);
                    printf("\nNota: %.1f", va->notas);
                    printf("\nDigite 1 para apagar o elemento ou 2 para retroceder!");
                    scanf("%d", &opcao);
                    switch(opcao){
                        case 1:
                            colRemove(col, (void*)va);
                            printf("\nElemento removido com sucesso!");
                            break;
                        case 2:
                            printf("\n\nO usuario escolheu retroceder");
                            break;
                        default:
                            printf("\n Digite uma opcao valida");
                    }
                } else{
                    printf("Aluno nao encontrado");
                }
                printf("\nPressione Enter para continuar!");
                while(getchar() != '\n');
                getchar();//espera o enter do usuario
                break;
            case 4:
                printf("O usuario escolheu verificar algo na colecao.");
                if(col == NULL){
                    printf("\nAloque primeiro a colecao!");
                    printf("\nPressione Enter para continuar!");
                    while(getchar() != '\n');
                    getchar();//espera o enter do usuario
                    break;
                }

                if(col->numItens<=0){
                    printf("\nA colecao esta vazia!");
                    break;
                }
                printf("Voce deseja procurar por: \n");
                printf("1 - Nome\n 2 - Numero de chamada \n 3 - Nota");
                printf("\n\nOpcao: ");
                scanf("%d", &opcao);

                switch(opcao){
                    case 1:
                        printf("\nDigite o nome a ser procurado: ");
                        scanf("%s", nome);
                        va = colQuery(col, (void*)nome, cmpString);
                        break;
                    case 2:
                        printf("\nDigite o numero de chamada do aluno: ");
                        scanf("%d", &Key);
                        va = colQuery(col, (void*)&Key, cmpInt);
                        break;
                    case 3:
                        printf("\n Digite a nota a procurar: ");
                        scanf("%f", &vnotas);
                        va = colQuery(col, (void*)&vnotas, cmpFloat);
                        break;
                    default:
                        printf("\n\nDigite uma opcao valida!");
                        break;
                }
                if(va != NULL){
                printf("\nAluno encontrado!");
                printf("\nNome: %s  ", va->nome);
                printf("\nNumero de chamada: %d ", va->nchamada);
                printf("\nNota:  %.1f", va->notas);
                } else{
                    printf("Aluno nao encontrado");
                }
                printf("\nPressione Enter para continuar!");
                while(getchar() != '\n');
                getchar();//espera o enter do usuario
                break;
            case 5:
                printf("\nO usuario escolheu listar a colecao.");
                if(col == NULL){
                    printf("\nAloque primeiro a colecao!");
                    printf("\nPressione Enter para continuar!");
                    while(getchar() != '\n');
                    getchar();//espera o enter do usuario
                    break;
                }
                if(col->numItens<=0){
                    printf("\nA colecao esta vazia!");
                    break;
                }

                for(indice=0; indice<col->numItens; indice++){
                    va = col->Item[indice];
                    printf("\nIndice[%d]\n Nome: %s \nNumero de chamada: %d \nNota: %.1f ", indice, va->nome, va->nchamada, va->notas);
                }
                printf("\nPressione Enter para continuar!");
                while(getchar() != '\n');
                getchar();//espera o enter do usuario
                break;
            case 6:
                printf("O usuario escolheu Destruir a colecao.");
                if(colDestroy(col)== false){
                    printf("\n\nNao eh possivel destruir a colecao, verifique se ela esta vazia!");
                } else{
                    colDestroy(col);
                    printf("\n\nColecao destruida com sucesso");
                }
                printf("\nPressione Enter para continuar!");
                while(getchar() != '\n');
                getchar();//espera o enter do usuario
                break;
            case 7:
                colClear(col);
                printf("\nColecao esvaziada com Sucesso!\n");
                printf("\nPressione Enter para continuar!");
                while(getchar() != '\n');
                getchar();//espera o enter do usuario
                break;
            case 8:
                printf("\nO usuario escolheu sair do programa.");
                exit(1);
                break;
            default:
                printf("\nDigite uma opcao valida!");
                break;
        }
    }
}

