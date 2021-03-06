#include "fila_prioridade.h"
#include <string.h>


/**************************************
* DADOS
**************************************/
typedef struct no{
    TipoElemento dado;
    struct no* prox;
}No;


struct _filaPrioridade{
    No* inicio;
    No* fim;
    int qtde;
};

/**************************************
* FUNÇÕES AUXILIARES
**************************************/
bool fila_ehValida(FilaPrioridade* f){
    return (f != NULL? true : false);
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/


/**
 * Desaloca todos os espaços que foram alocados dinâmicamente pelas 
 * funções criar e inserir
 * Parâmetro enderecoFila: Endereço da variável que armazena o endereço da Fila de Prioridade
 */
void filaP_destruir(FilaPrioridade** enderecoFila){
   if(enderecoFila == NULL) return;
   if(!fila_ehValida(*enderecoFila)) return;

   FilaPrioridade* f = *enderecoFila;
   No* aux;
   while (f->inicio != NULL)
   {
       aux = f->inicio;
       f->inicio = f->inicio->prox;
   }
    free(f);
    *enderecoFila = NULL;
}

/**
 * Insere o elemento da fila de acordo com sua prioridade
 * Quando maior o número, maior é sua prioridade
 * Parâmetro f: Endereço de memória da Fila de Prioridade
 * Parâmetro elemento: Elemento a ser inserido
 * RETORNO: true se inserção ocorrer com sucesso e false caso contrário
 */
bool filaP_inserir(FilaPrioridade* f, TipoElemento elemento){
    if(!fila_ehValida(f)) return false;

    No* novo = (No*) malloc(sizeof(No));
    No* aux;

    novo->dado = elemento;
    if (f->inicio == NULL)
    {
        novo->prox = NULL;
        f->inicio = novo;
    }
    else if (novo->dado > f->inicio->dado)
    {
        novo->prox = f->inicio;
        f->inicio = novo;
    }
    else
    {
        aux = f->inicio;
        while (aux->prox != NULL && novo->dado < aux->prox->dado)
        {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    f->qtde++;
}

/**
 * Remove o valor de maior prioridade da fila
 * A função devolve o elemento removido copiando-o no endereço (saida) recebido por parâmetro
 * Parâmetro f: Endereço de memória da Fila de Prioridade
 * Parâmetro saida: Endereço de memória no qual deve ser devolvido (copiado) o elemento removido
 * RETORNO: true se o elemento foi removido com sucesso e false caso contrário
 */
bool filaP_remover(FilaPrioridade* f, TipoElemento* saida){
    if(!fila_ehValida(f)) return false;
    if(filaP_vazia(f)) return false;
    if(saida == NULL) return false;

    *saida = f->inicio->dado;
    f->inicio = f->inicio->prox;
    f->qtde--;

    return true;
}

/****************************************************************************************/

FilaPrioridade* filaP_criar(){
    FilaPrioridade* f = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtde = 0;
    return f;
}


bool filaP_primeiro(FilaPrioridade* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(filaP_vazia(f)) return false;

    *saida = f->inicio->dado;
    return true;;
}

bool filaP_vazia(FilaPrioridade* f){
    if(!fila_ehValida(f)) return true;

    return (f->qtde == 0 ? true : false);
}

int filaP_tamanho(FilaPrioridade* f){
    if(!fila_ehValida(f)) return 0;

    return f->qtde;
}



bool filaP_toString(FilaPrioridade* f, char* str){
    if (!fila_ehValida(f)) return false;

    str[0] = '\0';
    strcat(str, "[");
    char elemento[20];

    No* aux = f->inicio;
    
    while(aux != NULL){
        sprintf(elemento,"%d", aux->dado);
        strcat(str, elemento);
        if (aux->prox != NULL) strcat(str, ",");
        aux = aux->prox;
    }
    strcat(str, "]");
    return true;
}
