#ifndef DLISTAS_H
#define DLISTAS_H

typedef struct DNodo {
    int dato;
    struct DNodo *next;
    struct DNodo *prev;
} DNodo;

DNodo *dnodo_crear(int dato);

void dlista_imprimir(DNodo *head);

void dlista_insertar_inicio(DNodo **head, int dato);

void dlista_insertar_final(DNodo **head, int dato);

void dlista_insertar(DNodo **head, int dato, int p);

DNodo *dlista_buscar(DNodo **head, int dato);

void dlista_eliminar_nodo(DNodo **head, DNodo *nodo);

void dlista_liberar(DNodo **head);

#endif