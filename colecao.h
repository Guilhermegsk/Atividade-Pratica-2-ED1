#ifndef _COLECAO_H_
#define _COLECAO_H_

typedef struct _colecao_{
    int numItens;
    int maxItens;
    int cur;
    void* *Item;// vetor do tipo void
    } Colecao;// eh a struct

Colecao *colcreate(int maxItens);
int colInsert(Colecao *c, void* Item);
void* colRemove(Colecao *c, void* Key);
void* colQuery(Colecao *c, void* Key, int(*cmp)(void*, void*));
void* colClear(Colecao *c);
int colDestroy(Colecao *c);
int cmpString(void* Item, void * Key);
int cmpInt(void* Item, void * Key);
int cmpFloat(void* Item, void * Key);

#endif // COLECAO_H_
