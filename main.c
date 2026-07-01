#include <stdio.h>
#include "arreglos.h"
#include "listas.h"
#include "dlistas.h"

int main(void){
    printf("========== ARREGLOS DINAMICOS ==========\n");
    DinaArray a = crear_arreglo(3);
    agregar_elemento(&a, 0, 10);
    agregar_elemento(&a, 1, 20);
    agregar_elemento(&a, 2, 30);
    imprimir_arreglo(a);
    eliminar_elemento(&a, 1);
    imprimir_arreglo(a);
    liberar_arreglo(&a);

    printf("\n========== LISTA ENLAZADA ==========\n");
    Nodo *l = NULL;
    lista_insertar_final(&l, 10);
    lista_insertar_final(&l, 20);
    lista_insertar_final(&l, 30);
    lista_insertar_inicio(&l, 5);
    lista_insertar(&l, 15, 2);
    lista_imprimir(l);
    printf("buscar 20 -> %s\n", lista_buscar(&l, 20) ? "encontrado" : "no");
    lista_eliminar_nodo(&l, lista_buscar(&l, 15));
    lista_imprimir(l);
    lista_liberar(&l);

    printf("\n========== LISTA DOBLE ==========\n");
    DNodo *d = dnodo_crear(10);
    dlista_insertar_final(&d, 20);
    dlista_insertar_final(&d, 30);
    dlista_insertar_inicio(&d, 5);
    dlista_imprimir(d);
    dlista_eliminar_nodo(&d, dlista_buscar(&d, 20));
    dlista_imprimir(d);
    dlista_liberar(&d);
    return 0;
}
