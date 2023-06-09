#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

lista inserir_inicio(lista l, int valor) {
    lista novo = (lista) malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = l;
    return novo;
}

void exibir_lista(lista l){
    lista aux = l;

    if(aux == NULL){
        printf("Lista vaiza!\n");
    }
    while(aux != NULL) {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void exibir_lista_r(lista l){
    if(l == NULL) {
        printf("Lista vaiza!\n");
        return;
    }

    exibir_lista_r(l->proximo);
    printf("[%d]", l->valor);


}

lista inserir_fim(lista l, int valor) {
    lista aux = l;
    if(l == NULL) {
        return inserir_inicio(l, valor);
    }
    while(aux->proximo != NULL) {
        aux = aux->proximo;
        }
    lista novo = (lista) malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;
    aux->proximo = novo;
    return l;
}

lista remover_inicio(lista l) {

    lista aux = l;

    if(aux==NULL){
        printf("Lista ja esta vazia!\n");
        return 0;
    } else {
        aux = l->proximo;
        free(l);
    }
    return aux;
}

lista remover_fim(lista l) {
    if(l==NULL)
        return NULL;

    if(l->proximo == NULL)
       return remover_inicio(l);

    lista aux = l;
    while(aux->proximo->proximo != NULL) {
        aux = aux->proximo;
    }
    free(aux->proximo);
    aux->proximo = NULL;
    return l;
}

lista inserir_posicao(lista l, int valor, int posicao){

    if(posicao < 0){
        printf("A posicao digitada eh invalida. Digite novamente!\n");
        return 0;
    }

    if(l == NULL){
        printf("Impossivel adicionar em uma posicao maior que (1) pois a lista esta vazia\n");
    }

    lista novo = (lista)malloc(sizeof(no));
    novo->valor = valor;

    if(posicao == 1){
        novo->proximo = l;
        l = novo;
        return l;
    }

    lista atual = l;
    lista anterior = NULL;
    int cont = 0;

    while(atual != NULL && cont < posicao){
        anterior = atual;
        atual = atual->proximo;
        cont++;
    }

    if(cont != posicao){
        printf("Posicao invalida!\n");
        free(novo);
        return 0;
    }
    return l;
}

lista remover_posicao(lista l, int posicao){
    struct no *atual = l;
    struct no *anterior = l;

    if(posicao > 0){
        printf("Posicao invalida. Tente novamente!\n");
        return l;
    } else if(posicao == 1){
        return remover_inicio(l);

    } else if(l == NULL){
        printf("A lista ja esta vazia!\n");
        return NULL;
    } else {

    while(posicao != 1){
        anterior = atual;
        atual = atual->proximo;
        posicao--;
    }
    anterior->proximo = atual->proximo;
    free(atual);
    atual = NULL;
    }
    return l;
}

void somador (lista l){
    lista aux = l;
    int soma = 0;

    while(aux != NULL){
            soma+=aux->valor;
            aux = aux->proximo;

    }
    if(soma == 0){
        printf("A lista esta vazia!\n");
        return 0;
    }
    printf("Soma de todos os itens da lista: (%d)", soma);
    printf("\n");
}

void tamanho_lista(lista l){
    lista aux = l;
    int cont = 0;

    while(aux!= NULL){
        cont++;
        aux = aux->proximo;
    }
    if(cont == 0){
        printf("Lista esta vazia!\n");
        return 0;
    }

    printf("O tamanho da lista eh: (%d)", cont);
    printf("\n");
}

lista elevar_quadrado(lista l){

    lista aux = l;

    while(aux != NULL){
            aux->valor = aux->valor * aux->valor;
            aux = aux->proximo;
    }
    return l;
}

int eh_primo(int numero) {
    if (numero <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }

    return 1;
}

void qtd_primo(lista l){
    lista aux = l;
    int cont_primo = 0;

    while(aux != NULL){
        if(eh_primo(aux->valor) == 1){
            cont_primo++;
        }
        aux = aux->proximo;
    }
    printf("Quantidade de numeros primos na lista eh: (%d)", cont_primo);
    printf("\n");
}

lista procurar(lista l, int valor){
    lista aux = l;
    int cont = 1;

    if(aux == NULL){
        printf("Lista esta vazia!\n");
        return -1;
    }

   while(aux->valor != valor){
            cont++;
            aux = aux->proximo;
        if(aux->proximo == NULL){
        printf("Valor nao esta na lista!\n");
        return -1;
        }

    }




    printf("Posicao na lista: (%d)",cont);
    printf("\n");
}

lista remove_valor(lista l, int val){

    if(l == NULL){
        printf("lista vaiza!\n");
        return 0;
    }

    lista atual = l;
    lista temp = NULL;

    while(atual != NULL && atual->valor != val){
        temp = atual;
        atual= atual->proximo;
    }

    if(atual == NULL){
        printf("Numero nao existe na lista!\n");
        return 0;

    }
    if(temp == NULL){
        l = atual->proximo;
    } else {
        temp->proximo = atual->proximo;
    }
    free(atual);

    return l;
}

lista inserir_ordem(lista l, int num) {
    lista novo = (lista)malloc(sizeof(no));

    novo->valor = num;
    novo->proximo = NULL;

    if (l == NULL) {
        l = novo;
        return l;
    }

    lista atual = l;
    lista anterior = NULL;

    while (atual != NULL && atual->valor < num) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && atual->valor == num) {
        printf("O n�mero j� est� na lista\n");
        free(novo);
    } else {
        if (anterior == NULL) {
            novo->proximo = l;
            l = novo;
        } else {
            anterior->proximo = novo;
            novo->proximo = atual;
        }
    }

    return l;
}
