/*
	Programador: Rabadan Gradanos Jesus Sebastian
	Date: 04/03/21 
*/


#include <stdio.h>
int main (){

int k[3][2][4], a, j, m; //Se define el tama�o del arreglo y las variables para el ciclo for
for (a=0; a<=2; a++){
    for (j=0; j<=1; j++){
        for (m=0; m<=3; m++){ //Se hace el uso del if para imprimir el arreglo de 3 dimensiones como si fueran de dos dimensiones

if (m==0 && j==0 && a==0) 
printf ("Matriz %d\n", a+1);//Se imprime la primera matriz de 4x2
if (m==0 && j==0 && a==1)
printf ("Matriz %d\n", a+1); //Se imprime la segunda matriz de 4x2
if (m==0 && j==0 && a==2)
printf ("Matriz %d\n", a+1); //Se imprime la tercera matriz de 4x2
            printf ("%p   ", &k[a][j][m]); //Aqu� se imprime la direcci�n de memoria de cada elemento de la matriz de 4x2

        }
        printf ("\n");
    }
    printf ("\n\n\n\n");
}

printf ("Direcci�n de memoria del arreglo: %p", &k); //Se imprime la direcci�n de memoria de la variable de tipo arreglo
printf ("\nDirecci�n de memoria del primer elemento del arreglo: %p", &k[0][0][0]); //Se imprime la direcci�n de memoria del primer elemento del arreglo

return 0;

}

