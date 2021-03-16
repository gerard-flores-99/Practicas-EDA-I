/*
	Programador: Martinez Ram�rez Jose Angel
	Date: 04/03/21
*/


#include<stdio.h>
void crearMensaje(); //Prototipo de la funci�n
void descifrarMensaje(); //Prototipo de la funci�n
int main(){
	short opcion=0; //Crea una variable tipo short de nombre opcion iniciada en el estado FALSO.
	while (1){ //Aqu� se crea un ciclo con la condici�n MIENTRAS la variable opcion sea TRUE (o bien diferente de "0") para poder navegar a trav�s del men� sin que el programa termine.
		printf("\n\t*** ESC�TALA ESPARTANA ***\n");
		printf("�Qu� desea realizar?\n");
		printf("1) Crear mensaje cifrado.\n");
		printf("2) Descifrar mensaje.\n");
		printf("3) Salir.\n");
		scanf("%d", &opcion);
		switch(opcion){ //Inicia un seleccionador de casos utilizando el valor capturado en la instrucci�n anterior.
			case 1:
				crearMensaje(); //Llama a la funci�n crearMensaje de tipo void.
				break; 
			case 2:
				descifrarMensaje(); //Llama a la funci�n descifrarMensaje de tipo void.
				break;
				case 3:
				return 0; //Retorna el valor 0 para el ciclo while, el cual ocasiona que el ciclo se rompa y termine el programa.
			default:
				printf("Opci�n no v�lida.\n"); 
		}
	}
	return 0; //Retorna el valor 0 para la funci�n main.
}

void crearMensaje(){
	int ren, col, i, j, k=0;
	printf("Ingresar el tama�o de la esc�tala:\n");
	printf("\nRenglones:");
	scanf("%i",&ren); //Captura el n�mero de renglones de la esc�tala.
	printf("\nColumnas:"); 
	scanf("%i",&col); //Captura el n�mero de columnas de la esc�tala.
	char escitala[ren][col]; //Crea una arreglo de caracteres llamada escitala del n�mero de renglones y columnas de los valores capturados en las instrucciones anteriores.
	char texto[ren*col]; //Crea una cadena llamada texto, cuyo tama�o es determinado al calcular el producto del n�mero de renglones por el n�mero de columnas.
	printf("Escriba el texto a cifrar:\n");
	scanf("%s", texto); //Captura el mensaje sin espacios que se va a codificar.
	for (i=0 ; i<ren ; i++) 
		for (j=0 ; j<col ; j++)
			escitala[i][j] = texto[k++]; //El arreglo esc�tala va guardando en un ciclo for uno a uno los caracteres obtenidos en el mensaje.
	printf("El texto en la tira queda de la siguiente manera:\n");
	for (i=0 ; i<col ; i++)
		for (j=0 ; j<ren ; j++)
			printf("%c", escitala[j][i]); //Cambia el orden del arreglo para que se imprima el mensaje codificado.
	printf("\n");
}

void descifrarMensaje(){
	int ren, col, i, j, k=0;
	printf("Ingresar el tama�o de la esc�tala:\n");
	printf("\nRenglones:");
	scanf("%i",&ren); 
	printf("\nColumnas:");
	scanf("%i",&col);
	char escitala[ren][col]; 
	char texto[ren*col];
	printf("Escriba el texto a descifrar:\n");
	scanf("%s", texto); //Aqu� se captura sin espacios el mensaje codificado.
	for (i=0 ; i<col ; i++) 
		for (j=0 ; j<ren ; j++)
			escitala[j][i] = texto[k++]; //El arreglo esc�tala va guardando en un ciclo for uno a uno los caracteres obtenidos en el mensaje codificado.
	printf("El texto descifrado es:\n");
	for (i=0 ; i<ren ; i++)
		for (j=0 ; j<col ; j++)
			printf("%c", escitala[i][j]); //Intercambia los valores de i y j para imprimir el mensaje decodificado.
}

