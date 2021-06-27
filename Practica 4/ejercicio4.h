/*
    Programador: Solis González Alan David
    Date: 25/06/2021 
*/
 
#ifndef EJERCICIO_4_H 
#define EJERCICIO_4_H
#include <stdbool.h>
 
typedef struct _nodo nodo;
typedef int INFO;
 
struct _nodo{
    
    INFO info;
    nodo *sig;
 
};
 
typedef struct _lista lista;
 
struct _lista{
 
    nodo *head;
    nodo *tail;
    int num;
 
};
 
nodo* crear_nodo (INFO info);
 
nodo* crear_nodo2 (INFO info);
 
 
lista *crear_lista();
 
bool insertar_inicio (lista *l, INFO info);
 
bool insertar_fin (lista *l, INFO info);
 
bool insertar (lista* l, INFO info, int pos);
 
bool insertar2 (lista* l, INFO info, int pos);
 
bool es_vacia (lista *l);
 
bool vaciar (lista *l);
 
void imprimir_lista(lista *l);
 
void imprimir_nodo (nodo* nodo, INFO info);
 
nodo* crear_nodoa (INFO info);
 
nodo* crear_nodob (INFO info);
 
#endif 