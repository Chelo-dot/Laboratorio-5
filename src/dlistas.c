
#include <stdio.h>
#include <stdlib.h>
//#include "dlista.h"

typedef struct DNodo {
    int dato;
    struct DNodo *next;
    struct DNodo *prev;
} DNodo;

DNodo *dnodo_crear(int dato){
    DNodo *n = malloc(sizeof(DNodo));
    if (n) {n -> dato = dato; n -> next = NULL; n -> prev = NULL; }
    return n;
}

void dlista_imprimir(DNodo *head){
    DNodo *cur = head;
    DNodo *ultimo = NULL;
    printf("FWD: ");
    while(cur){
        printf("%d ", cur -> dato);
        ultimo = cur;
        cur = cur -> next;
    }
    printf("\nBWD: ");
    cur = ultimo;
    while(cur){
        printf("%d ", cur -> dato);
        cur = cur -> prev;
    }

    printf("\n");

}

void dlista_insertar_inicio(DNodo **head, int dato){
    DNodo *nuevo = dnodo_crear(dato);

    nuevo -> next = *head;
    (*head) -> prev = nuevo;
    *head = nuevo;
    
}
