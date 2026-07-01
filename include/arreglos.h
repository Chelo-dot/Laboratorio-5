#ifndef ARREGLOS_H
#define ARREGLOS_H

typedef struct {
    int *data;
    int size;
    int capacidad;
} DinaArray;

DinaArray crear_arreglo(int n);

void imprimir_arreglo(DinaArray a);

void agregar_elemento(DinaArray *a, int valor, int indice);

void eliminar_elemento(DinaArray *a, int indice);

void liberar_arreglo(DinaArray *a);

#endif