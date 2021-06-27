#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    int *array = NULL, num, cont;
    char aa=160, spa=168;
    printf("%cCu%cntos elementos tiene el arreglo?\n", spa, aa);
    scanf("%d", &num); //Dirección de memoria
    array = (int*) calloc(num, sizeof(int));
    if(array != NULL)
    {
        for (cont = 0; cont < num; cont++)
        {
            printf("Ingresa el elemento %d\n", cont+1);
            scanf("%d", (array+cont));
        }
        
        printf("Vector reservado:\n\t[");
        for(cont = 0; cont < num; cont++)
        {
            printf("\tValor:%d dir:%p", *(array+cont),array+cont); //dar formato a las direcciones de memoria
        }
        printf("\t]\n");

        num += -1; //redude el tamaño del arreglo en quitandole uno
        array = (int*)realloc(array, num*sizeof(int)); //Permite cambiar el tamaño de la memoria reservada
        if(array != NULL)
        {
            for (; cont < num; cont++)
        {
            printf("Ingresa el elemento %d\n", cont+1);
            scanf("%d", (array+cont));
        }
        
        printf("Vector reservado:\n\t[");
        for(cont = 0; cont < num; cont++)
        {
            printf("\tValor:%d dir:%p", *(array+cont),array+cont); //dar formato a las direcciones de memoria
        }
        printf("\t]\n");
        }

        printf("La memoria será liberada\n");
        free(array);
    }
    return 0;
}