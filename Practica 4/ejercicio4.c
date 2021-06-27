#include "ejercicio4.h"
#include <stdio.h>
#include <stdlib.h>
 
nodo* crear_nodo (INFO info){ // La función crear_nodo trabaja con malloc
 
    nodo* t = (nodo*)malloc(sizeof(nodo));
 
    t->sig = NULL;
    t->info = info;
 
    return t;
 
}
 
nodo* crear_nodo2 (INFO info){ // La función crear_nodo2 trabaja con calloc
 
    nodo* t = (nodo*)calloc(1, sizeof(nodo));
 
    t->sig = NULL;
    t->info = info;
 
    return t;
 
}
 
bool insertar_inicio (lista *l, INFO info){
 
    nodo* nuevo = crear_nodo(info);
 
    if (l->head == NULL && l->tail == NULL){
 
        l->head = l->tail = nuevo;
 
        l->num++;
        
        return true;
 
    }
    
    else{
 
        nuevo->sig = l->head;
 
        l->head = nuevo;
 
        l->num++;
 
        return true;
 
    }
 
    return false;
 
}
 
bool insertar_fin (lista *l, INFO info){
 
    nodo* nuevo = crear_nodo(info);
 
    if (l->head == NULL && l->tail == NULL){
 
        l->head = l->tail = nuevo;
        l->num++;
        
        return true;
 
    }
 
    else{
 
        l->tail->sig = nuevo;
        l->tail = nuevo; // l->tail = l->tail->sig;
        l->num++;
        return true;
 
    }
 
    return false;
 
}
 
bool insertar(lista* l, INFO info, int pos){ //La función insertar manda a llamar a malloc
 
    if (pos == 0) return insertar_inicio(l, info);
 
    else if (pos == l->num) return insertar_fin(l, info);
 
    else if (pos > 0 && pos < l->num){
 
        nodo* nuevo = crear_nodo(info);
        nodo* temporal = l->head;
        int tpos = 0;
 
        for (int tpos = 0; tpos < pos-1; tpos++)
            temporal = temporal->sig;
 
        nuevo->sig = temporal->sig;
        temporal->sig = nuevo;
        l->num++;
 
        return true;
 
    }
 
    return false;
 
}
 
bool insertar2 (lista* l, INFO info, int pos){ // La función insertar2 manda a llamar a calloc
 
    if (pos == 0) return insertar_inicio(l, info);
 
    else if (pos == l->num) return insertar_fin(l, info);
 
    else if (pos > 0 && pos < l->num){
 
        nodo* nuevo = crear_nodo2 (info);
        nodo* temporal = l->head;
        int tpos = 0;
 
        for (int tpos = 0; tpos < pos-1; tpos++)
            temporal = temporal->sig;
 
        nuevo->sig = temporal->sig;
        temporal->sig = nuevo;
        l->num++;
 
        return true;
 
    }
 
    return false;
 
}
 
lista *crear_lista(){
 
    lista* l = (lista*)malloc(sizeof(lista));
    l->head = l->tail = NULL;
    l->num = 0;
 
    return l;
 
}
 
bool es_vacia(lista *l){
 
    if (l->head == NULL && l->tail == NULL) return true;
 
    return false;
}
 
bool vaciar (lista *l){
 
    if (es_vacia(l)) return false;
 
    nodo* temporal = l->head;
    while (temporal != NULL){
 
        l->head = temporal->sig;
        free(temporal);
        temporal = l->head;
 
    }
 
    l->head = l->tail = NULL;
    l->num = 0;
 
    return true;
 
}
 
void imprimir_lista(lista *l){
 
    for (nodo* t = l->head; t != NULL; t = t->sig){
 
        printf("%d ->", t->info);
 
    }
 
    printf ("\n");
 
}
 
nodo* crear_nodoa (INFO info){ 
 
    nodo* t = (nodo*)malloc(sizeof(nodo));
 
    printf ("%d\t%p\n\n",t->info, t);
 
    t->sig = NULL;
    t->info = info;
 
    return t;
 
}
 
 
nodo* crear_nodob (INFO info){ 
 
    nodo* t = (nodo*)calloc(1, sizeof(nodo));
 
    printf ("%d\t%p\n\n",t->info, t);
 
    t->sig = NULL;
    t->info = info;
 
    return t;
}
