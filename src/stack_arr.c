#include <stdio.h>
#include "stack_arr.h"

void sa_init(StackArr *s, int cap){

    DinaArray arr = crear_arreglo(cap);
    &s->arr;

}

void sa_push(StackArr *s, int valor){

    agregar_elemento(&s->arr, s->arr.size - 1, valor);

}

int sa_pop(StackArr *s){

    int valor_arriba = *(s->arr.data + (s->arr.size - 1));
    eliminar_elemento(&s->arr, s->arr.size - 1);
    return valor_arriba;

}

int sa_peek(StackArr *s){

    int valor_arriba = *(s->arr.data + (s->arr.size - 1));
    return valor_arriba;

}

int sa_empty(StackArr *s){

    if (s->arr.capacidad = s->arr.size){
        return 1;
    } else {
        return 0;
    }

}

void sa_free(StackArr *s){

    liberar_arreglo(&s->arr);

}