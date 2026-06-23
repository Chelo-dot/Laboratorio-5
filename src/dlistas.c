
#include <stdio.h>
#include <stdlib.h>
//#include "dlista.h"

typedef struct DNodo {
    int dato;
    struct DNodo *next;
    struct DNodo *prev;
} Dnodo;

DNodo *dnodo_crear(int dato){
    Dnodo *n = malloc(sizeof(Dnodo));
    if (n) {n -> dato = dato; n -> next = NULL; n -> prev = NULL; }
    return n;
}

void dlista_imprimir(Dnodo *head){
    Dnodo *cur = head;
    Dnodo *ultimo = NULL;
    printf("FWD: ");
    while(cur){
        printf("%d ", cur -> dato);
        ultimo = cur;
        cur = cur -> next;
    }
    printf("\nBWD: ");
    while(cur){
        printf("%d ", cur -> dato);
        cur = cur -> prev;
    }

    printf("\n");

}
