#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"

#define TAM_MIN 100

struct heap{
    void** array;
    size_t cant;
    size_t cap;
    cmp_func_t cmp;
};
/**********************************************/
/* HEAP_SORT */
/*********************************************/

void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp){

}

/**********************************************/
/* FUNCIONES AUXILIARES */
/*********************************************/
bool heapify(void* arreglo, size_t n, cmp_func_t cmp);

/**********************************************/
/* FUNCIONES HEAP */
/*********************************************/
heap_t *heap_crear(cmp_func_t cmp){
    heap_t* nuevo = malloc(sizeof(heap_t));
    if(!nuevo) return NULL;
    nuevo->cant = 0;
    nuevo->cap = TAM_MIN;
    nuevo->array = malloc(sizeof(void*)*(nuevo->cap));
    if(!nuevo->array){
        free(nuevo);
        return NULL;
    }
    nuevo->cmp = cmp;
    return nuevo;
}

heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){
    heap_t* nuevo = malloc(sizeof(heap_t));
    if(!nuevo) return NULL;
    nuevo->cant = n;
    if(n < TAM_MIN){
        nuevo->cap = TAM_MIN;
    }
    //!FALTA HACERLO PARA CUANDO SON GRANDES
    nuevo->array = arreglo;
    //?Preguntar si hay que copiar el arreglo, o directamente meterlo
    nuevo->cmp = cmp;
    heapify(nuevo->array, n, cmp);
    return nuevo;
}

size_t heap_cantidad(const heap_t *heap){
    return heap->cant;
}

bool heap_esta_vacio(const heap_t *heap){
    return(!heap->cant);
}

void *heap_ver_max(const heap_t *heap){
    return heap->array[0];
}

bool heap_encolar(heap_t *heap, void *elem);

void *heap_desencolar(heap_t *heap);

void heap_destruir(heap_t *heap, void destruir_elemento(void *e));