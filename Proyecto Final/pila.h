#ifndef PILA_H
#define PILA_H

#include <stdbool.h>
#include <stdlib.h>
#include "nodo.h"

typedef struct _pila pila;

struct _pila
{
    NODO *head;
    NODO *tail;
    int num;
};

pila *crear_pila();
bool push(pila *p, INFO info);
void pop(pila *p);
bool es_vacia_pila(pila *p);
bool vaciar_pila(pila *p);
void imprimir_pila(pila *p);
void eliminar_pila(pila *p);
INFO *top(pila *p);

#endif