#include <stdio.h>
#include <string.h>
#include <math.h>
#include "pila.h"
#include "cola.h"
#include "nodo.h"

INFO conversion (INFO *c, char *a, int b);

void expresion_postfija (INFO *c, pila *p, cola *co, int b);

void evaluar_postfija(INFO *c, pila *p, cola *co, int b);

int main(int argc, char *argv[]){

    pila *p;
    p = crear_pila();

    cola *co;
    co = crear_cola();

    FILE* archivo = fopen("archivo.txt","r");

    char caracter;

    if(archivo == NULL){

        printf("No se enconto ningun archivo\n");
        return 1;

    }
    
    fseek (archivo, 0, SEEK_END);
    int num = ftell (archivo);
    rewind (archivo);

    char* a = (char *) calloc(sizeof(char), num);

    if (a == NULL){

        perror ("Error en la reserva de memoria");
        return 2;

    }

    int tam = fread (a, sizeof(char), num, archivo);

    if (tam != num){

        perror ("Error al leer el archivo");
        return 3;

    }

    printf ("\nLa expresion del archivo es: %s", a);

    fclose (archivo);

    INFO* c = (INFO *) calloc(sizeof(INFO), num);

    conversion (c, a, num);

    free (a);

    expresion_postfija (c, p, co, num);

    evaluar_postfija(c, p, co, num);

    free (c);

    vaciar_cola (co);
    vaciar_pila (p);

    eliminar_cola (co);
    eliminar_pila (p);
    
    int numero;
    char cadena[50];
    printf("Ingrese tu expresion posfija: ");
    scanf("%s", cadena);
    printf("Ingrese 1 si desea guardar de lo contrario presione cualquier letra");
    scanf("%d", &numero);  
    FILE *barchivo;
    
    switch (numero)
    {
    case 1:
            barchivo=fopen("barchivo.txt","w+t");
            fputs(cadena,barchivo);
            fclose(barchivo);
        break;
    
    default:printf("Has decidido no guardar \n");
        break;
    }
    printf("Programa exitoso, regrese pronto");
    return 0;
}

NODO *crear_nodo(INFO info){
    NODO *t = (NODO *)malloc(sizeof(NODO));
    t->sig = NULL;
    t->info = info;
    return t;
}

pila *crear_pila(){
    pila *p = (pila *)malloc(sizeof(pila));
    p->head = p->tail = NULL;
    p->num = 0;
    return p;
}

cola *crear_cola(){
    cola *co = (cola *)malloc(sizeof(cola));
    co->head = co->tail = NULL;
    co->num = 0;
}

void eliminar_pila(pila *p){
    if(p == NULL) return;
    if(!es_vacia_pila(p))
    {
        vaciar_pila(p);
    }
    free(p);
    p = NULL;
}

void eliminar_nodo(NODO *n){
    if (n->sig == NULL)
    {
        free(n);
        n = NULL;
    }
}

void eliminar_cola(cola *co){
    if(co == NULL) return;
    if(!es_vacia_cola(co))
    {
        vaciar_cola(co);
    }
    free(co);
    co = NULL;
}

bool es_vacia_pila(pila *p){
    if(p->head == NULL && p->tail == NULL) return true;
    return false;
}

bool es_vacia_cola(cola *co){
    if(co->head == NULL && co->tail == NULL) return true;
    return false;
}

bool vaciar_cola(cola *co){
    if(es_vacia_cola(co)) return false;
    NODO* temporal = co->head;
    co->tail->sig = NULL;
    while(temporal != NULL)
    {
        co->head = co->head->sig;
        temporal->sig = NULL;
        eliminar_nodo(temporal);
        temporal = co->head;
    }
    return true;
}

bool vaciar_pila(pila *p){
    if(es_vacia_pila(p)) return false;
    NODO* temporal = p->head;
    p->tail->sig = NULL;
    while(temporal != NULL)
    {
        p->head = p->head->sig;
        temporal->sig = NULL;
        eliminar_nodo(temporal);
        temporal = p->head;
    }
    return true;
}

bool push(pila *p, INFO info){
    NODO *nuevo = crear_nodo(info);
    if(es_vacia_pila(p)){
        p->head = p->tail = nuevo;
        p->num++;
        return true;
    }
    else{
        nuevo->sig = p->head;
        p->head = nuevo;
        p->num++;
        return true;
    }
    return false;
}

bool enqueue(cola *co, INFO info){
    NODO *nuevo = crear_nodo(info);
    if(es_vacia_cola(co)){
        co->head = co->tail = nuevo;
        co->num++;
        return true;
    }
    else{
        co->tail->sig = nuevo;
        co->tail = nuevo;
        co->num++;
        return true;
    }
    return false;
}

void imprimir_pila(pila *p){
    for(NODO* t = p->head; t != NULL; t = t->sig)
    {
        printf("%c ", t->info.c);
    }

    printf("\n");
}

void imprimir_cola(cola *co){
    for(NODO* t = co->head; t != NULL; t = t->sig)
    {
        printf("%c ", t->info.c);
    }

    printf("\n");
}

void pop(pila *p){
    if(es_vacia_pila(p)) return;
    NODO *temporal = p->head;
    p->head = p->head->sig;
    temporal->sig = NULL;
    eliminar_nodo(temporal);
    p->num--;
}

void dequeue(cola *co){
    if(es_vacia_cola(co))return;
    NODO *temporal = co->head;
    co->head = co->head->sig;
    temporal->sig = NULL;
    eliminar_nodo(temporal);
    co->num--;
}

INFO *top(pila *p){
	if(es_vacia_pila(p)) return NULL;
	return &p->head->info;
}


INFO conversion (INFO *c, char *a, int b){

    for (int i = 0; i < b; i++){

        c[i].c = a[i];

        switch (c[i].c){

            case '+':{ c[i].op = true;
                c[i].prio = 1;
            }
            break;

            case '-':{ c[i].op = true;
                c[i].prio = 1;
            }
                break;

            case '*':{ c[i].op = true;
                c[i].prio = 2;
            }
                break;

            case '/':{ c[i].op = true;
                c[i].prio = 2;
            }
                break;

            case '%':{ c[i].op = true;
                c[i].prio = 2;
            }
                break;

            case '^':{ c[i].op = true;
                c[i].prio = 3;
            }
                break;

            case '(':{ c[i].op = true;
                c[i].prio = 0;   
            }
                break;

            case ')':{ c[i].op = true;
                c[i].prio = -1;   
            }
                break;
            
            default:{ c[i].op = false;

                printf ("\nEscriba el valor de %c: ", c[i].c);

                scanf ("%d", &c[i].value);

            }
                break;
        }

    }

    return c[b];

}


void expresion_postfija (INFO *c, pila *p, cola *co, int b){
    
    for (int i = 0; i < b; i++){

        if (c[i].op == false){

            enqueue (co, c[i]);

        }

        else{

            switch (c[i].prio){

                case 0:{

                    push (p, c[i]);

                }
                    break;

                case -1:{

                    do{

                        enqueue (co, *top(p));

                        pop (p);

                    }while (top(p)->prio != 0);

                    if (top (p)->prio == 0){

                        pop (p);

                    }

                }
                    break;
                
                default:{

                    if (es_vacia_pila (p)){

                        push (p, c[i]);

                    }

                    else{

                        if (c[i].prio > top(p)->prio){

                            push (p, c[i]);

                        }

                        else{

                            enqueue (co, *top(p));

                            pop (p);

                            push (p, c[i]);

                        }

                    }

                }
                    break;
            }

        }

    }   

    if (top(p) != NULL){

        do{

            enqueue (co, *top(p));

            pop (p);

        }while (top(p) != NULL);

    }

    imprimir_pila(p);

    printf ("\nLa conversion a expresion postfija es: ");

    imprimir_cola(co);

}


void evaluar_postfija (INFO *c, pila *p, cola *co, int b){

    NODO *temporal = co->head;

    INFO res, res1, res2;

    res.c = '#';
    res.value = 0;
    res.op = false;

    res1.c = '$';
    res1.value = 0;
    res1.op = false;

    res2.c = '!';
    res2.value = 0;
    res2.op = false;


    for (int i = 0; i < co->num; i++){

        if (temporal->info.op == false){

            push (p, temporal->info);

        }

        else{

            switch (temporal->info.c){

                case '+':{

                    res = *top(p);
                    
                    pop (p);

                    res1 = *top(p);

                    pop (p);

                    res2.value = res1.value + res.value;

                    push (p, res2);

                }
                
                break;

                case '-':{

                    res = *top(p);
                    
                    pop (p);

                    res1 = *top(p);

                    pop (p);

                    res2.value = res1.value - res.value;

                    push (p, res2);

                }

                break;

                case '*':{

                    res = *top(p);
                    
                    pop (p);

                    res1 = *top(p);

                    pop (p);

                    res2.value = res1.value * res.value;

                    push (p, res2);

                }

                break;

                case '/':{

                    res = *top(p);
                    
                    pop (p);

                    res1 = *top(p);

                    pop (p);

                    res2.value = res1.value / res.value;

                    push (p, res2);

                }

                break;

                case '%':{

                    res = *top(p);
                    
                    pop (p);

                    res1 = *top(p);

                    pop (p);

                    res2.value = res1.value % res.value;

                    push (p, res2);

                }

                break;

                case '^':{

                    res = *top(p);
                    
                    pop (p);

                    res1 = *top(p);

                    pop (p);

                    res2.value = pow(res1.value, res.value);

                    push (p, res2);

                }

                break;
            
                default:
                    printf ("\nOcurrio un error");
                break;
            }

        }

        temporal = temporal->sig;

    }

    printf ("\nEl resultado de la expresion es: %d\n\n", res2.value);

    free (temporal);

}