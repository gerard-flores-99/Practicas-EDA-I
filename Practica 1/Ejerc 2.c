/*
	Programador: Solis Gonzales Alan David
	Date: 04/03/21 
*/


#include <stdio.h>
int main (){

    int k[3][3], a, j; //aquí se define el tamaño del arreglo, además de las variables contador para el ciclo for

    for (a=0; a<=2; a++){

        for (j=0; j<=2; j++){
            printf ("%p\n", &k[a][j]); //se imprimen las direcciones de memoria de cada elemento del arreglo
        }
        printf ("\n");
    }
    printf ("\n\n");
    printf ("Dirección de memoria del arreglo: %p", &k); //se imprime la dirección de memoria de la variable de tipo arreglo
    printf ("\nDirección de memoria del primer elemento: %p", &k[0][0]); //se imprime la dirección de memoria del primer elemento del arreglo
    return 0;
}

