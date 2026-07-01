#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


Nodo *nodo_crear(int dato){
    Nodo *nuevo = malloc(sizeof(Nodo));
    if (nuevo) { nuevo -> dato = dato; nuevo -> next = NULL; }
    return nuevo;
}

void lista_imprimir(Nodo *head){

    Nodo *cur = head;
    printf("FWD: ");
    while(cur){
        printf("%d ", cur -> dato);
        cur = cur -> next;
    }
    printf("\n");

}

void lista_insertar_inicio(Nodo **head, int dato){

    Nodo *nuevo = nodo_crear(dato);

    nuevo -> next = *head;
    *head = nuevo;

}

void lista_insertar_final(Nodo **head, int dato){

    Nodo *nuevo = nodo_crear(dato);

    if(!*head){
        *head = nuevo;
        return;
    }

    Nodo *cur = *head;
    while(cur -> next) cur = cur -> next;
    cur -> next = nuevo;

}

void lista_insertar(Nodo **head, int dato, int p){

    if(p == 0){
        lista_insertar_inicio(head, dato);
        return;
    }

    Nodo *cur = *head;
    // avanza hasta el nodo previo a la posicion p
    for(int i = 0; i < p - 1; i++){
        if(!cur){
            printf("Error: posicion invalida elemento no anadido\n");
            return;
        }
        cur = cur -> next;
    }

    if(!cur){
        printf("Error: posicion invalida elemento no anadido\n");
        return;
    }

    Nodo *nuevo = nodo_crear(dato);
    nuevo -> next = cur -> next;
    cur -> next = nuevo;

}

Nodo *lista_buscar(Nodo **head, int dato){

    Nodo *cur = *head;
    // busqueda lineal
    while(cur){
        if(cur -> dato == dato) return cur;
        cur = cur -> next;
    }
    return NULL;

}

void lista_eliminar_nodo(Nodo **head, Nodo *nodo){

    if(!*head || !nodo){
        printf("Error: puntero no valido\n");
        return;
    }

    // nodo es primer elemento
    if(*head == nodo){
        *head = nodo -> next;
        free(nodo);
        return;
    }

    // cualquier otra posicion
    Nodo *cur = *head;
    while(cur -> next && cur -> next != nodo) cur = cur -> next;

    if(cur -> next == nodo){
        cur -> next = nodo -> next;
        free(nodo);
    }

}

void lista_liberar(Nodo **head){

    Nodo *cur = *head;
    while(cur){
        Nodo *tmp = cur;
        cur = cur -> next;
        free(tmp);
    }
    *head = NULL;

}
