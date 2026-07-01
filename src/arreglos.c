#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arreglos.h"

/*inicializa todos los elementos en cero para evitar */
DinaArray crear_arreglo(int n){

    int *ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL){
        fprintf(stderr, "Error al inicializar la memoria\n");
        exit(EXIT_FAILURE);
    }

    DinaArray arreglo;

    arreglo.data = ptr;
    arreglo.size = n;
    arreglo.capacidad = n;

    return arreglo;
}

void imprimir_arreglo(DinaArray a){

    if (a.data == NULL){
        fprintf(stderr, "Error con el arreglo dinámico\n");
        exit(EXIT_FAILURE);
    }

    printf("[");
    for (int i = 0; i < a.size; i++){
        printf("%d ", *(a.data + i));
    }
    printf("] size=%d cap=%d\n", a.size, a.capacidad);

}

/*Asume que el arreglo está llenado en orden y los valores no declarados están al final*/
void agregar_elemento(DinaArray *a, int indice, int valor){

    int nuevo_tamaño = indice + 2;
    int tamaño_original = indice;

    if ((a->capacidad == 0)||(indice >= a->size)){

        int *nuevo = realloc(a->data, nuevo_tamaño*sizeof(int));

        if (nuevo == NULL){
                fprintf(stderr, "Error al expandir la memoria la memoria\n");
                exit(EXIT_FAILURE);
            }

        int sin_declarar = nuevo_tamaño - a->size;

        memset(nuevo + a->size, 0, sin_declarar * sizeof(int));

        a->data = nuevo;
        a->size = nuevo_tamaño;
        a->capacidad += nuevo_tamaño;
    }


    if (indice >= tamaño_original){
        *(a->data + indice) = valor;
    } else {
        for (int i = a->size -1; i > indice; i--){
            *(a->data + i) = *(a->data + i - 1);
        }
        *(a->data + indice) = valor;
    }

    a->capacidad -= 1;
}


/*Con el arreglo existente, desplaza una posición menos todos los elementos del arreglo y se declara el último elemento como cero*/
void eliminar_elemento(DinaArray *a, int indice){

    if (a->data == NULL){
        fprintf(stderr, "Error al expandir la memoria la memoria\n");
        exit(EXIT_FAILURE);
    }

    if (indice >= a->size){
        printf("Intenta eliminar un elemento que no existe");
    } else if (indice == (a->size - 1)){
        *(a->data + indice) = 0;
    } else {
        for (int i = indice; i < (a->size - 1); i++){
            *(a->data + i) = *(a->data + i + 1);
        }
        *(a->data + (a->size - 1)) = 0;
    }

    a->capacidad += 1;
}

void liberar_arreglo(DinaArray *a){
    
    free(a->data);
    a->data = NULL;
    a->size = 0;
    a->capacidad = 0;

}