#ifndef STACK_ARR_H
#define STACK_ARR_H

#include "arreglos.h"

typedef struct {
    DinaArray arr;
} StackArr;

void sa_init (StackArr *s, int cap_inicial);
void sa_push(StackArr *s, int valor);
int sa_pop(StackArr *s); /*retorna el valor extraido*/
int sa_peek(StackArr *s); /*retorna el tope sin extraer*/
int sa_empty(StackArr *s); /*retorna 1 si está vacío*/
void sa_free(StackArr *s);

#endif