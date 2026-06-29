#include <stdio.h>
#include <stdlib.h>
#include "arreglos.h"


/*inicializa todos los elementos en cero para no tener errores*/
DinaArray crear_arreglo(size_t n){

    int *ptr = (int *)calloc(n, sizeof(int));
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
    printf("] size=%zu cap=%zu\n", a.size, a.capacidad);

}

/* Sobreescribe el valor si ya había sido asignado y amplia el tamaño del arreglo uno más del índice indicado */
DinaArray agregar_elemento(DinaArray a, int indice, int valor){

    if (a.data == NULL){
        return a;
    }

    if (a.size < indice){
        int *nuevo = realloc(a.data, (indice + 1)*sizeof(int));
        a.data = nuevo;
        a.size = 2*a.size;
        a.capacidad = a.capacidad + 2*a.size;
    }

    *(a.data + indice) = valor;

    a.capacidad -= 1;

    return a;
}


/*Con el arreglo existente, desplaza una posición menos todos los elementos del arreglo y se declara el último elemento como cero*/
DinaArray eliminar_elemento(DinaArray a, int indice){

    if ((a.data == NULL)||(a.size < indice)){
        return a;
    }


    if (indice == (a.size-1)){
        *(a.data + indice) = 0;
    } else {
        for (int i = indice; i < (a.size-2); i++){
            *(a.data + i) = *(a.data + i + 1);
            *(a.data + (a.size-1)) = 0;
        }
    }

    a.capacidad += 1;
 
    return a;
}

void liberar_arreglo(DinaArray a){

    free(a.data);
    a.data = NULL;
}