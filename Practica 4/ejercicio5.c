#include "ejercicio5.h"
#include <stdio.h>

nodo *crear_nodo(INFO info)
{
    nodo *t = (nodo *)malloc(sizeof(nodo));
    t->sig = NULL;
    t->info = info;
    return t;
}

bool insertar_inicio(lista *l, INFO info)
{
    nodo *nuevo = crear_nodo(info);
    if (l->head == NULL && l->tail == NULL)
    {
        l->head = l->tail = nuevo; //l->head = nuevo; l->tail = nuevo;
        l->num++;
        return true;
    }
    else
    {
        nuevo->sig = l->head;
        l->head = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool insertar_fin(lista *l, INFO info)
{
    nodo *nuevo = crear_nodo(info);
    if (l->head == NULL && l->tail == NULL)
    {
        l->head = l->tail = nuevo;
        l->num++;
        return true;
    }
    else
    {
        l->tail->sig = nuevo;
        l->tail = nuevo; // l->tail = l->tail->sig;
        l->num++;
        return true;
    }
    return false;
}

bool insertar(lista *l, INFO info, int pos)
{
    if (pos == 0)
        return insertar_inicio(l, info);
    else if (pos == l->num)
        return insertar_fin(l, info);
    else if (pos > 0 && pos < l->num)
    {
        nodo *nuevo = crear_nodo(info);
        nodo *temporal = l->head;
        for (int tpos = 0; tpos < pos - 1; tpos++)
            temporal = temporal->sig;
        nuevo->sig = temporal->sig;
        temporal->sig = nuevo;
        l->num++;
        return true;
    }
    return false;
}

lista *crear_lista()
{
    lista *l = (lista *)malloc(sizeof(lista));
    l->head = l->tail = NULL;
    l->num = 0;
    return l;
}

bool es_vacia(lista *l)
{
    if (l->head == NULL && l->tail == NULL)
        return true;
    return false;
}

bool vaciar(lista *l)
{
    nodo *temporal = l->head;
    while (temporal != NULL)
    {
        l->head = temporal->sig;
        free(temporal);
        temporal = l->head;
    }
}

void imprimir_lista(lista *l)
{
    for (nodo *t = l->head; t != NULL; t = t->sig)
    {
        printf("%d -> ", t->info);
    }
    printf("\n");
}

void imprimir_dic(lista *l)
{
    for (nodo *t = l->head; t != NULL; t = t->sig)
    {
        printf("%p -> ", &t->info);
    }
    printf("\n");
}

void eliminar_nodo(nodo *n)
{
    if (n->sig == NULL)
    {
        free(n);
        n = NULL;
    }
}

void eliminar_inicio(lista *l)
{
    if (es_vacia(l))
        return;
    nodo *temporal = l->head;
    l->head = l->head->sig;
    temporal->sig = NULL;
    eliminar_nodo(temporal);
    l->num--;
}

void eliminar_fin(lista *l)
{
    if (es_vacia(l))
        return;
    nodo *temporal;
    for (temporal = l->head; temporal->sig != l->tail; temporal = temporal->sig)
        ;
    temporal->sig = NULL;
    eliminar_nodo(l->tail);
    l->tail = temporal;
    l->num--;
}

void eliminar(lista *l, int pos)
{
    if (pos == 0)
        eliminar_inicio(l);
    else if (pos == l->num - 1)
        eliminar_fin(l);
    else if (pos > 0 && pos < l->num - 1)
    {
        nodo *temporal = l->head, *temporal2;
        for (int i = 0; i < pos - 1; i++)
            ;
        temporal = temporal->sig;
        temporal2 = temporal->sig;
        temporal->sig = temporal->sig->sig;
        temporal2->sig = NULL;
        eliminar_nodo(temporal2);
        l->num--;
    }
}

void eliminar_lista(lista *l)
{
    if(l == NULL) return;
    if(!es_vacia(l))
    {
        vaciar(l);
    }
    free(l);
    l = NULL;
}

