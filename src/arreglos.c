#include <stdio.h>
#include <stdlib.h>
#include "arreglos.h"

Array crear_arreglo(int n){

    int *ptr = (int *)malloc(sizeof(int)*n);
    Array arreglo;

    arreglo.puntero = ptr;
    arreglo.tamaño = n;

    return arreglo;
}

void imprimir_arreglo(Array a){

    for (int i = 0; i < a.tamaño; i++){
        printf("%d", *(a.puntero + i));
    }

}



