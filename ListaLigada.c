//
// Created by nava on 29/10/24.
//

#include "ListaLigada.h"

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
            anterior = inicio;
            while(aux->dado < novo->dado &&
                aux->proximo != NULL) {
                anterior = aux;
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

    p->dado = dado;
    p->proximo = NULL;

    return p;
}

void adicionarNoInicio() {
    novo->proximo = inicio;
    inicio = novo;
}

void adicionarNoFim() {
    aux->proximo = novo;
}

void adicionarNoMeio() {
    novo->proximo = aux;
    anterior->proximo = novo;
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
        anterior = inicio;
        while(aux->dado != dado &&
            aux->proximo != NULL) {
            anterior = aux;
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
        free(aux);
    }
}

void excluirNoFim() {
    anterior->proximo = NULL;
    free(aux);
}

void excluirNoMeio() {
    proximo = aux->proximo;

    anterior->proximo = proximo;
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

bool paraProximo() {
    if(noCorrente == NULL || noCorrente->proximo == NULL) {
        return false;
    }
    noCorrente = noCorrente->proximo;
    return true;
}

bool getCorrente(int *dado) {
    if(noCorrente != NULL) {
        *dado = noCorrente->dado;
        return true;
    }
    return false;
}
