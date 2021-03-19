/*
    Programador: Rabadan Gradanos Jesús Sebastian
    Date: 11/03/21
*/

#include<stdio.h>
#include "operaciones.h"
int main(){
    //Declaramos y asignamos las variables a los auntadores
      int x, y, *a, *b, *c, r, op;

    a=&x;
    b=&y;
    c=&r;
    //pedimos los numeros a utilizar
    printf("Escriba su primer numero:\n ");
    scanf("%d", &x);
    printf("Escriba su segundo numero numero:\n ");
    scanf("%d", &y);
    // pedimos que opcion quiere el cliente para utilizar una estructura selectiva
    printf("Escriba 1 si quiere suma, 2 resta, 3 multiplicacion, 4 division: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        suma(a,b);
        break;
    case 2:
        resta(a,b);
        break;
    case 3:
        multi(a,b);
        break;
    case 4:
        div(a,b);
        break;
    default:
        printf("Esta opción no está disponible");
        break;   
    }


}
//Desarrollo de las funciones
void suma(int *a, int *b ){
    int *c,r;
    c=&r;
    r=*a+*b; 
    printf("Con la función suma tu resultado es: %d", *c);
}
void resta(int *a, int *b ){
    int *c,r;
    c=&r;
    r=(*a-*b);
    printf("Con la función resta tu resultado es: %d", *c); 

}
void multi(int *a, int *b ){
    int *c,r;
    c=&r;
    r=(*a**b);
    printf("Con la función multiplicación tu resultado es: %d", *c);
   
}
    
void div(int *a, int *b ){
int *c,r;
    c=&r;
    if( *b != 0){
    r=(*a / *b);
    printf("Con la función division tu resultado es: %d", *c);
    }else{  
        printf("SINTIAX ERROR");
    }

}

