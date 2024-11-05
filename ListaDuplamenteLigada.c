//
// Created by nava on 05/11/24.
//

#include "ListaDuplamenteLigada.h"

// variáveis
struct no *inicio = NULL;
struct no *novo = NULL;
struct no *aux = NULL;
struct no *anterior = NULL;
struct no *proximo = NULL;
struct no *noCorrente = NULL;

// funções
void adicionar(int dado) {
    novo = novoNo(dado);

    if(inicio == NULL) {
        inicio = novo;
    }
    else {
        if(novo->dado < inicio->dado) {
            adicionarNoInicio();
        }
        else {
            aux = inicio;
            while(aux->dado < novo->dado &&
                aux->proximo != NULL) {
                aux = aux->proximo;
            }
            if(novo->dado > aux->dado) {
                adicionarNoFim();
            }
            else {
                adicionarNoMeio();
            }
        }
    }
}

struct no * novoNo(int dado) {
    struct no *p = malloc(sizeof(struct no));
    if(!p) {
        printf("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }

    p->anterior = NULL;
    p->dado = dado;
    p->proximo = NULL;

    return p;
}

void adicionarNoInicio() {
    novo->proximo = inicio;
    inicio->anterior = novo;
    inicio = novo;
}

void adicionarNoFim() {
    aux->proximo = novo;
    novo->anterior = aux;
}

void adicionarNoMeio() {
    anterior = aux->anterior;

    novo->proximo = aux;
    anterior->proximo = novo;
    aux->anterior = novo;
    novo->anterior = anterior;
}

void excluir(int dado) {
    if(inicio == NULL) {
        return;
    }
    if(inicio->dado == dado) {
        excluirNoInicio();
    }
    else {
        aux = inicio;
        while(aux->dado != dado &&
            aux->proximo != NULL) {
            aux = aux->proximo;
            }
        if(aux->dado == dado) {
            if(aux->proximo == NULL) {
                excluirNoFim();
            }
            else {
                excluirNoMeio();
            }
        }
    }
}

void excluirNoInicio() {
    if(inicio->proximo == NULL) {
        free(inicio);
        inicio = NULL;
    }
    else {
        aux = inicio;
        inicio = inicio->proximo;
        inicio->anterior = NULL;

        free(aux);
    }
}

void excluirNoFim() {
    anterior = aux->anterior;
    anterior->proximo = NULL;
    free(aux);
}

void excluirNoMeio() {
    proximo = aux->proximo;
    anterior = aux->anterior;

    anterior->proximo = proximo;
    proximo->anterior = anterior;

    free(aux);
}

void inicializar() {
    inicio = NULL;
}

void finalizar(struct no *quem) {
    if(quem == NULL) {
        return;
    }
    if(quem->proximo != NULL) {
        finalizar(quem->proximo);
    }
    printf("Excluindo %d\n", quem->dado);
    free(quem);
}

void paraInicio() {
    noCorrente = inicio;
}

void paraFinal() {
    noCorrente = inicio;
    while(noCorrente->proximo != NULL) {
        noCorrente = noCorrente->proximo;
    }
}

bool paraProximo() {
    if(noCorrente == NULL || noCorrente->proximo == NULL) {
        return false;
    }
    noCorrente = noCorrente->proximo;
    return true;
}

bool paraAnterior() {
    if(noCorrente == NULL || noCorrente->anterior == NULL) {
        return false;
    }
    noCorrente = noCorrente->anterior;
    return true;
}

bool getCorrente(int *dado) {
    if(noCorrente != NULL) {
        *dado = noCorrente->dado;
        return true;
    }
    return false;
}
