#ifndef LISTAS_H
#define LISTAS_H

typedef struct Nodo {
    int dato;
    struct Nodo *next;
} Nodo;

Nodo *nodo_crear(int dato);

void lista_imprimir(Nodo *head);

void lista_insertar_inicio(Nodo **head, int dato);

void lista_insertar_final(Nodo **head, int dato);

void lista_insertar(Nodo **head, int dato, int p);

Nodo *lista_buscar(Nodo **head, int dato);

void lista_eliminar_nodo(Nodo **head, Nodo *nodo);

void lista_liberar(Nodo **head);

#endif
