/*
	Programador: Solis Gonzales Alan David
	Date: 04/03/21 
*/


#include <stdio.h>
int main (){

    int k[3][3], a, j; //aqu� se define el tama�o del arreglo, adem�s de las variables contador para el ciclo for

    for (a=0; a<=2; a++){

        for (j=0; j<=2; j++){
            printf ("%p\n", &k[a][j]); //se imprimen las direcciones de memoria de cada elemento del arreglo
        }
        printf ("\n");
    }
    printf ("\n\n");
    printf ("Direcci�n de memoria del arreglo: %p", &k); //se imprime la direcci�n de memoria de la variable de tipo arreglo
    printf ("\nDirecci�n de memoria del primer elemento: %p", &k[0][0]); //se imprime la direcci�n de memoria del primer elemento del arreglo
    return 0;
}

