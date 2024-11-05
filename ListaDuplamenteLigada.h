//
// Created by nava on 05/11/24.
//

#ifndef LISTADUPLAMENTELIGADA_H
#define LISTADUPLAMENTELIGADA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// constantes
struct no {
    struct no *anterior;
    int dado;
    struct no* proximo;
};

// variáveis
extern struct no* inicio;
extern struct no* novo;
extern struct no* aux;
extern struct no* anterior;
extern struct no* proximo;
extern struct no* noCorrente;

// protótipos
struct no *novoNo(int dado);
void adicionar(int dado);
void adicionarNoInicio();
void adicionarNoFim();
void adicionarNoMeio();
void excluir(int dado);
void excluirNoInicio();
void excluirNoFim();
void excluirNoMeio();
void inicializar();
void finalizar(struct no *quem);

void paraInicio();
void paraFinal();

bool paraProximo();
bool paraAnterior();

bool getCorrente(int *dado);

#endif //LISTADUPLAMENTELIGADA_H
