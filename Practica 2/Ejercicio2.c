/*
    Programador: Solis González Alan David
    Date: 11/03/21
*/

#include <stdio.h>
#include <stdlib.h>

int *a = NULL;//Se declaran los apuntadores y apuntan a nulo
char *b = NULL;
double *c = NULL;
long *d = NULL;
float *e = NULL;
short *f = NULL;


int main(){

    int g = 4; //Se declaran las variables anónimas
    char h = 'A';
    double i = 27;
    long j = 97;
    float k = 12;
    short l = 9;
    
    a = (int *)malloc(sizeof(int)); //Se manda llamar a malloc para reservar memoria de cada tipo de apuntador
    b = (char *)malloc(sizeof(char));
    c = (double *)malloc(sizeof(double));
    d = (long *)malloc(sizeof(long));
    e = (float *)malloc(sizeof(float));
    f = (short *)malloc(sizeof(short));

    a = &g; //Hacemos que los apuntadores apunten a las direcciones de memoria de las variables anónimas
    b = &h;
    c = &i;
    d = &j;
    e = &k;
    f = &l;


    printf("Dirección de memoria de int: %p\n", &g); //Se imprime las direcciones de memoria para ver si son contiguas
    printf("Dirección de memoria de char: %p\n", &h);
    printf("Dirección de memoria de double: %p\n", &i);
    printf("Dirección de memoria de long: %p\n", &j);
    printf("Dirección de memoria de float: %p\n", &k);
    printf("Dirección de memoria de short: %p\n\n\n", &l);

    printf ("Datos almacenados en g: %i\n", *a); //Se imprime el valor de las variables anónimas mediante apuntadores
    printf ("Datos almacenados en h: %c\n", *b);
    printf ("Datos almacenados en i: %lf\n", *c);
    printf ("Datos almacenados en j: %ld\n", *d);
    printf ("Datos almacenados en k: %f\n", *e);
    printf ("Datos almacenados en l: %i\n\n\n", *f);

    *a = 9; //Se cambia el valor de las variables anónimas por medio de apuntadores
    *b = 'B';
    *c = 723.918413;
    *d = 4913;
    *e = 41.31;
    *f = 16;    

    printf("Nuevo dato almacenado en g: %i\n", *a); //Se imprime el nuevo valor de las variables anónimas para ver si cambiaron
    printf("Nuevo dato almacenado en h: %c\n", *b);
    printf("Nuevo dato almacenado en i: %lf\n", *c);
    printf("Nuevo dato almacenado en j: %ld\n", *d);
    printf("Nuevo dato almacenado en k: %f\n", *e);
    printf("Nuevo dato almacenado en l: %i\n", *f);


    free(a); //Se libera la memoria reservada por malloc anteriormente
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);

    return 0;
}

