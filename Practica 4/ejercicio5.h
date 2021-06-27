#ifndef EJERCICIO_5_H
#define EJERCICIO_5_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _nodo nodo;
typedef int INFO;

struct _nodo
{
    INFO info;
    nodo *sig;
};

typedef struct _lista lista;

struct _lista
{
    nodo *head;
    nodo *tail;
    int num;
};

nodo* crear_nodo(INFO info);
void eliminar_nodo(nodo *n);

lista *crear_lista();
bool insertar_inicio(lista *l, INFO info);
bool insertar_fin(lista *l, INFO info);
bool insertar(lista *l, INFO info, int pos);
bool es_vacia(lista *l);
void eliminar_lista(lista *l);
bool vaciar(lista *l);
void imprimir_lista(lista *l);
void imprimir_dic(lista *l);
void eliminar_inicio(lista *l);
void eliminar_fin(lista *l);
void eliminar(lista *l, int pos);
void eliminar_lista(lista *l);

#endif //EJERCICIO_5_H