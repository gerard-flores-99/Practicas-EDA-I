/*
	Programador: Flores Saavedra Jose Gerardo 
	Date: 04/03/21 
*/

#include <stdio.h>
int main(){
	int *p=NULL; //Se declara un apuntador y se iguala a nulo
	int a[10]; //Se declara un arreglo unidimensional de 10 elementos
	printf("Ingrese 10 números: \n"); //Se imprime un mensaje para pedir los no.
	for (int i=0; i<10; i++){ //La "i" es la posición e irá aumentando conforme se vayan ingresando los no.
			scanf("%d",&a[i]); //Guarda la posición del no. ingresado en el arreglo
		}
	printf("\nLos numeros que ingreso son: \n"); //Se imprimen los no. ingresados
	for (int i=0; i<10; i++){ //La "i" es la posición e irá aumentando conforme se vayan ingresando los no.
		printf("%d\t",a[i]); //Imprime el no. según la posición
	}
	p = &a[10]; //Se iguala el apuntador al arreglo
	printf("\n\nLas direcciones de memoria de los números son: ");
	for (int i=0; i<10; i++){ //La "i" es la posición e irá aumentando conforme se vayan ingresando los no.
		printf("\n%p",&a[i]); //Imprime la dirección de memoria de cada elemento del arreglo
	}

	return 0; //No devuelve nada
}


	
