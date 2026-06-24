#ifndef ARREGLOS_H
#define ARREGLOS_H

typedef struct Array {
    int *puntero;
    int tamaño;
} Array;

Array crear_arreglo(int n);

void imprimir_arreglo(Array a);

#endif