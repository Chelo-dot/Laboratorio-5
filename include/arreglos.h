#ifndef ARREGLOS_H
#define ARREGLOS_H

typedef struct {
    int *data;
    size_t size;
    size_t capacidad;
} DinaArray;

DinaArray crear_arreglo(int n);

void imprimir_arreglo(DinaArray a);

#endif