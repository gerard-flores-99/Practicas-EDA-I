#include <stdio.h>
#include <stdlib.h>
#include "ejercicio5.h"

int main (int argc, char ** argv)
{
    lista* l;

    l = crear_lista();
    insertar_inicio(l, 4);
    insertar_fin(l, 9);
    insertar_inicio(l, 2);
    insertar_fin(l, 15);

    imprimir_lista(l);
    imprimir_dic(l);

    vaciar(l);
    eliminar_lista(l);

    return (EXIT_SUCCESS);
}