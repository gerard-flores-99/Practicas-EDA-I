/*
    Programador: Flores Saavedra José Gerardo
    Date: 11/03/21
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[10]; //se declara un arreglo de 10 elementos enteros
    int *ptr; //se crea un apuntador de tipo entero

    arr[1] = 5; //equivale a *(arr+1) = 5
    ptr = &arr[2];

    printf("%p\n",ptr); //valor almacenado por ptr
	printf("%d\n",*ptr); //valor de la variable apuntada por ptr
	printf("%p\n",ptr[0]); //valor almacenado por ptr en la primera posición
	printf("%d\n",*ptr+6); //valor de la variable apuntada por ptr
	printf("%d\n",*(ptr+6)); //valor de la variable apuntada por ptr
    /*printf ("%d\n",*ptr[-1]) Es un error de argumento al no existir una posición -1*/
    /*printf ("%d\n",*ptr[-1]) Es un error de argumento al no existir una posición -1*/
	printf("%d\n",ptr[9]); //valor almacenado por ptr en la última posición
	printf("%p\n",&arr); //dirección de memoria de arr
	printf("%d\n",&ptr); //dirección de memoria de ptr
	printf("%p\n",ptr); //dirección que apunta ptr

	return 0;
}
