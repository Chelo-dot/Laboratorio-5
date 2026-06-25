#include <stdio.h>
#include <stdlib.h>
#include "arreglos.h"

DinaArray crear_arreglo(int n){

    int *ptr = (int *)malloc(sizeof(int)*n);
    DinaArray arreglo;

    arreglo.data = ptr;
    arreglo.size = n;
    arreglo.capacidad = n;

    return arreglo;
}

void imprimir_arreglo(DinaArray a){

    for (int i = 0; i < a.size; i++){
        printf("%d", *(a.data + i));
    }
    printf("] size=%zu cap=%zu\n", a.size, a.capacidad)

}





