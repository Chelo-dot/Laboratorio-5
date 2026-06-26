#ifndef ARREGLOS_H
#define ARREGLOS_H

typedef struct {
    int *data;
    size_t size;
    size_t capacidad;
} DinaArray;

DinaArray crear_arreglo(int n);

void imprimir_arreglo(DinaArray a);

DinaArray agregar_elemento(DinaArray a, int valor, int indice);

DinaArray eliminar_elemento(DinaArray a, int indice);

void liberar_arreglo(DinaArray a);

#endif