#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef COLECAO_C_INCLUDED
#define COLECAO_C_INCLUDED
#include "colecao.h"
#define true 1
#define false 0

typedef struct _aluno_{
    char nome[30];
    int nchamada;
    float notas;
} Aluno;

Colecao *colcreate(int n){// criando colecao de tamanho n
    Colecao *c;
    if(n>0){//tamanho maior que zero
        c = (Colecao *)malloc(sizeof(Colecao));
        if(c != NULL){// teste alocacao
            c->Item =(void**)malloc(sizeof(void*)*n);//criando um vetor de n posicoes do tipo void*
            if(c->Item != NULL){
                c->numItens = 0;
                c-> cur = 0;
                c-> maxItens = n;
                return c;
            }
            free(c);// nao foi possivel alocar
        }
    }
    return NULL;
}

int colDestroy(Colecao *c){
    if(c!=NULL){
        if(c->numItens==0){//verificando se esta vazia
            free(c->Item);//libera o vetor de n posicoes
            free(c);//libera a estrutura da colecao
            return true;
            }
        }
        return false;//nao foi possivel destruir
    }

int colInsert(Colecao *c, void *Item){
    if(c!=NULL){
        if(c->numItens< c->maxItens){//verificando se cabe algo na colecao
            c->Item[c->numItens]= Item;//colocando no vetor de item o void*item recebido
            c->numItens++;// incrementa para o proximo item
            return true;
        }
    }
    return false;//deu erro(pode nao ter espaco na colecao)
}

void* colQuery(Colecao *c, void* Key, int(*cmp)(void*, void*)){//recebe a colecao, uma chave, e um ponteiro pra funcao(que recebe dois void* e retorna um int
    if(c!=NULL){// verificando se nao eh nula
        if(c->numItens>0){//verificando se ha algo
            for(int i=0; i< c->numItens; i++){//percorrer a colecao
                if (cmp(c->Item[i], Key)== true){//se achei o item
                    return c->Item[i];
                }
            }
        }
    }
    return NULL;
}

void* colRemove(Colecao *c, void* Key){
    void* data;
    if(c!= NULL){
        if(c->numItens>0){//se ha algo dentro da colecao para se tirar

            for(int i = 0; i < c->numItens; i++){
                if(c->Item[i]== Key){// procura se ha algo na colecao com valor da chave
                    data = c->Item[i];//atribui a variavel data para retornar
                    for(int j=i; j<c->numItens;j++){
                    c->Item[j] = c->Item[j+1];//copia  para a posicao j quem esta na j+1
                    c->numItens--;// decrementa a quantidade de itens no vetor
                    return data;
                    }
                }
            }
        }
    }

    return NULL;
}

void* colClear(Colecao *c){
    if(c == NULL){
        return NULL;
    }
    if(c->numItens <= 0){//se ha algo
        return NULL;
    } else{
        for (int i = 0; i <= c->numItens; i++){//percorre o vetor numItens
        colRemove(c, c->Item[0]);//remove o Item da posicao 0
        }
    }
}

int cmpString(void* Item, void* Key){
    Aluno* item_temp = (Aluno*)Item;

    if(strcmp(item_temp->nome, (char*)Key) == 0){//strcmp retorna 0 se as strings sao iguais
        return true;
    }
    return false;
}

int cmpInt(void* Item, void* Key){
    Aluno* item_temp = (Aluno*)Item;

    if(item_temp->nchamada == *(int*)Key){//se o Item na struct eh igual a chave
        return true;
    }
    return false;
}

int cmpFloat(void* Item, void* Key){
    Aluno* item_temp = (Aluno*)Item;

    if(item_temp->notas == *(float*)Key){//se o Item eh igual a chave
        return true;
    }
    return false;
}
#endif
