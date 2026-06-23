
#include <stdio.h>
#include <stdlib.h>
#include "dlistas.h"



DNodo *dnodo_crear(int dato){
    DNodo *nuevo = malloc(sizeof(DNodo));
    if (nuevo) {nuevo -> dato = dato; nuevo -> next = NULL; nuevo -> prev = NULL; }
    return nuevo;
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


void dlista_insertar(DNodo **head, int dato, int p){
    DNodo *nuevo = dnodo_crear(dato);
    DNodo *cur = *head;

    if(p == 0){
        nuevo -> next = *head;
        (*head) -> prev = nuevo;
        *head = nuevo;
        return;
    }

    for(int i = 0; i <= p; i++){

        if(!cur->next&&i!=p){
            printf("Error: posicion invalida elemento no añadido\n");
            return; 
        }

        if(i==p){
            //puntero de nuevo
            nuevo->prev = cur->prev;
            nuevo->next = cur;

            //puntero de prev
            (cur->prev)->next = nuevo;
            

            //puntero de cur
            cur->prev=nuevo;
            return;

        }
        cur = cur->next;
    }


}


DNodo *dlista_buscar(DNodo **head, int dato){
    DNodo *cur = *head;
    // busqueda lineal
    while(cur){
        if(cur -> dato == dato) return cur;
        else if (!cur -> dato) return NULL;
        cur = cur -> next;
    }
    return NULL;
}

void dlista_eliminar_nodo(DNodo **head, DNodo *nodo){
    // nodo es primer elemento
    if(!nodo -> prev){
        (nodo -> next) -> prev = NULL;
        *head = nodo -> next;
    } 

    // nodo es ultimo
    else if(!nodo ->next){
        (nodo -> prev) -> next = NULL;
    }

    // cualquier otra posicion

    else {
        (nodo -> prev) -> next = nodo -> next;
        (nodo -> next) -> prev = nodo -> prev;
    }

    free(nodo);


}

void dlista_liberar(DNodo **head){
    DNodo *cur = *head;
    while(cur){
        if(cur->next){
            cur = cur->next;
            free(cur->prev);
        }
        else {free(cur); break;}
    } 

}

