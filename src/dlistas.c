
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

void dlista_insertar_final(DNodo **head, int dato){
    DNodo * nuevo = dnodo_crear(dato);

    DNodo *cur = *head;
    while(cur){
        if(cur -> next) cur = cur -> next;
        else {
            cur -> next = nuevo;
            nuevo -> prev = cur;
            return;
        }
    }
}

int main(void){

    DNodo ** head = malloc(sizeof(DNodo **));
    *head = dnodo_crear(1);
    dlista_insertar_final(head, 2);
    dlista_insertar_final(head, 3);
    dlista_imprimir(*head); 

}