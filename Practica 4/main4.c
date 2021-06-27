#include <stdio.h> 
#include <stdlib.h>
#include "ejercicio4.h"
 
int main (){
 
    lista *l1;
    nodo *n1, *n2;
 
    l1 = crear_lista();
 
    n1 = crear_nodoa(1);
 
    n2 = crear_nodob(2);
 
 
 
    insertar(l1, 4, 0); // Las funciones con "insertar" llaman a malloc
    insertar2 (l1, 12, 1);  //Las funciones con "insertar2" llaman a calloc
    insertar(l1, 1, 2);
    insertar2 (l1, 3, 3);
    insertar(l1, 10, 4);
    imprimir_lista(l1);
 
 
    vaciar (l1);
 
    free (l1);
 
    return 0;
}