#ifndef COLA_H
#define COLA_H
#include "nodo.h"

typedef struct _cola cola;

struct _cola
{
    NODO *head;
    NODO *tail;
    int num;
};

cola *crear_cola();
void eliminar_cola(cola *co);
bool enqueue(cola *co, INFO info); //Insertar fin
void dequeue(cola *co); //Eliminar inicio
bool es_vacia_cola(cola *co);
bool vaciar_cola(cola *co);
void imprimir_cola(cola *co);

#endif //cola_H