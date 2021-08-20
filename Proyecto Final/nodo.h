#ifndef NODO_H
#define NODO_H
#include <stdbool.h>

struct item{
    char c;
    bool op; //True = operador ; False = operando
    int prio;
    float value;
};

typedef struct item INFO;
typedef struct nodo NODO;

struct nodo
{
    INFO info;
    NODO *sig;
};

NODO* crear_nodo(INFO info);
void eliminar_nodo(NODO *n);
INFO crear_item (INFO info);

#endif
