/*
    Programador: Martinez Ramírez José Ángel
    Date: 11/03/21
*/

#include <stdio.h>
#include<stdlib.h>
//En este espacio se declaran las variables y los apuntadores
int *a,l;
char *b,i;
double *c,f;
long *d,g;
float *z,h;
short *x,y;
//Aquí podemos ver la asignación de los punteros a la variable
int main(){
    a=&l;
    b=&i;
    c=&f;
    d=&g;
    z=&h;
    x=&y;
 //*imprimimos los espacios de memorias de los punteros y variables igualadas para demostrar 
 //que es igual la memoria en la que se almacena

    printf("La dirección de memoria en int en variable l es %p\n", &l);
    printf("La dirección de memoria int en apuntador a es %p\n", a);
    printf("\n\n");
    printf("La dirección de memoria en  en variable b es %p\n", &i);
    printf("La dirección de memoria en apuntador char es %p\n", b);
    printf("\n\n");
    printf("La dirección de memoria en double en variable f es %p\n", &f);
    printf("La dirección de memoria en apuntador double es %p\n", c);
    printf("\n\n");
    printf("La dirección de memoria en long en variable g es %p\n", &g);
    printf("La dirección de memoria en apuntador long es %p\n", d);
    printf("\n\n");
    printf("La dirección de memoria en float en variable h es %p\n", &h);
    printf("La dirección de memoria en apuntador float es %p\n", z);
    printf("\n\n");
    printf("La dirección de memoria en short en variable y es %p\n", &y);
    printf("La dirección de memoria en apuntador short es %p\n", x);
    printf("\n\n");
    //Le asignamos un valor a la variable
    l=1;
    i=2;
    f=3;
    g=4;
    h=5;
    y=6;
    //Se imprime el valor de la variable por medio del puntero
    printf("A continuación a las variables les asignaremos un dato\n");
    printf("El valor de la variable l por medio del apuntador es %d ", *a);
    printf("\n\n");
    printf("El valor de la variable i por medio del apuntador es %d ", *b);
    printf("\n\n");
    printf("El valor de la variable f por medio del apuntador es %f ", *c);
    printf("\n\n");
    printf("El valor de la variable g por medio del apuntador es %d ", *d);
    printf("\n\n");
    printf("El valor de la variable h por medio del apuntador es %f ", *z);
    printf("\n\n");
    printf("El valor de la variable y por medio del apuntador es %d ", *x);
    printf("\n\n");
    //Asignamos el valor a el puntero para así cambiar el valor de la variable
    *a=7;
    *b=8;
    *c=9;
    *d=10;
    *z=11;
    *x=12;
    //Imprimimos el nuevo valor de la variable afectada por el puntero
    printf(" A continuación se mostraran los resultados cambiando el valor directamente en el apuntador");
    printf("\n\n");
    printf("El nuevo valor de l es %d", *a);
    printf("\n\n");
    printf("El nuevo valor de i es %d", *b);
    printf("\n\n");
    printf("El nuevo valor de f es %d", *c);
    printf("\n\n");
    printf("El nuevo valor de g es %d", *d);
    printf("\n\n");
    printf("El nuevo valor de h es %d", *z);
    printf("\n\n");
    printf("El nuevo valor de y es %d", *x);
    

    
    return 0;
}

