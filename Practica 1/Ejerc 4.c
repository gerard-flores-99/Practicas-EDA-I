/*
	Programador: Martinez Ramírez Jose Angel
	Date: 04/03/21
*/


#include<stdio.h>
void crearMensaje(); //Prototipo de la función
void descifrarMensaje(); //Prototipo de la función
int main(){
	short opcion=0; //Crea una variable tipo short de nombre opcion iniciada en el estado FALSO.
	while (1){ //Aquí se crea un ciclo con la condición MIENTRAS la variable opcion sea TRUE (o bien diferente de "0") para poder navegar a través del menú sin que el programa termine.
		printf("\n\t*** ESCÍTALA ESPARTANA ***\n");
		printf("¿Qué desea realizar?\n");
		printf("1) Crear mensaje cifrado.\n");
		printf("2) Descifrar mensaje.\n");
		printf("3) Salir.\n");
		scanf("%d", &opcion);
		switch(opcion){ //Inicia un seleccionador de casos utilizando el valor capturado en la instrucción anterior.
			case 1:
				crearMensaje(); //Llama a la función crearMensaje de tipo void.
				break; 
			case 2:
				descifrarMensaje(); //Llama a la función descifrarMensaje de tipo void.
				break;
				case 3:
				return 0; //Retorna el valor 0 para el ciclo while, el cual ocasiona que el ciclo se rompa y termine el programa.
			default:
				printf("Opción no válida.\n"); 
		}
	}
	return 0; //Retorna el valor 0 para la función main.
}

void crearMensaje(){
	int ren, col, i, j, k=0;
	printf("Ingresar el tamaño de la escítala:\n");
	printf("\nRenglones:");
	scanf("%i",&ren); //Captura el número de renglones de la escítala.
	printf("\nColumnas:"); 
	scanf("%i",&col); //Captura el número de columnas de la escítala.
	char escitala[ren][col]; //Crea una arreglo de caracteres llamada escitala del número de renglones y columnas de los valores capturados en las instrucciones anteriores.
	char texto[ren*col]; //Crea una cadena llamada texto, cuyo tamaño es determinado al calcular el producto del número de renglones por el número de columnas.
	printf("Escriba el texto a cifrar:\n");
	scanf("%s", texto); //Captura el mensaje sin espacios que se va a codificar.
	for (i=0 ; i<ren ; i++) 
		for (j=0 ; j<col ; j++)
			escitala[i][j] = texto[k++]; //El arreglo escítala va guardando en un ciclo for uno a uno los caracteres obtenidos en el mensaje.
	printf("El texto en la tira queda de la siguiente manera:\n");
	for (i=0 ; i<col ; i++)
		for (j=0 ; j<ren ; j++)
			printf("%c", escitala[j][i]); //Cambia el orden del arreglo para que se imprima el mensaje codificado.
	printf("\n");
}

void descifrarMensaje(){
	int ren, col, i, j, k=0;
	printf("Ingresar el tamaño de la escítala:\n");
	printf("\nRenglones:");
	scanf("%i",&ren); 
	printf("\nColumnas:");
	scanf("%i",&col);
	char escitala[ren][col]; 
	char texto[ren*col];
	printf("Escriba el texto a descifrar:\n");
	scanf("%s", texto); //Aquí se captura sin espacios el mensaje codificado.
	for (i=0 ; i<col ; i++) 
		for (j=0 ; j<ren ; j++)
			escitala[j][i] = texto[k++]; //El arreglo escítala va guardando en un ciclo for uno a uno los caracteres obtenidos en el mensaje codificado.
	printf("El texto descifrado es:\n");
	for (i=0 ; i<ren ; i++)
		for (j=0 ; j<col ; j++)
			printf("%c", escitala[i][j]); //Intercambia los valores de i y j para imprimir el mensaje decodificado.
}

