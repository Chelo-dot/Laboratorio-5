#include <stdio.h>
#include <stdlib.h>
#include "arreglos.h"


/*inicializa todos los elementos en cero para evitar */
DinaArray crear_arreglo(size_t n){

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
    for (size_t i = 0; i < a.size; i++){
        printf("%d", *(a.data + i));
    }
    printf("] size=%zu cap=%zu\n", a.size, a.capacidad);

}

/*Asume que el arreglo está llenado en orden y los valores no inicializados están al final*/
DinaArray agregar_elemento(DinaArray a, size_t indice, int valor){

    if ((a.capacidad = 0)||(indice >= a.size)){

        int *nuevo = realloc(a.data, (2*a.size)*sizeof(int));

        if (nuevo == NULL){
                fprintf(stderr, "Error al expandir la memoria la memoria\n");
                exit(EXIT_FAILURE);
            }

        a.data = nuevo;
        a.size = 2*a.size;
        a.capacidad = a.capacidad + 2*a.size;
    }

    if (indice >= a.size){
        *(a.data + indice) = valor;
    } else {
        for (size_t i = a.size -1; i < indice; i--){
            *(a.data + indice) = *(a.data + indice - 1);
        }
        *(a.data + indice) = valor;
    }

    a.capacidad -= 1;

    return a;
}


/*Con el arreglo existente, desplaza una posición menos todos los elementos del arreglo y se declara el último elemento como cero*/
DinaArray eliminar_elemento(DinaArray a, int indice){

    if (a.data == NULL){
        fprintf(stderr, "Error al expandir la memoria la memoria\n");
        exit(EXIT_FAILURE);
    }

    if (a.size < indice){
        printf("Intenta eliminar un elemento que no existe");
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
    a.size = 0;
    a.capacidad = 0;

} 