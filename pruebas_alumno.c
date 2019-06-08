#include "testing.h"
#include "heap.h"
#include <stdio.h>

#define ELEMENTOS 30000

void pruebas_heap_vacio(void);
void pruebas_heap_un_elemento(void);
void pruebas_heap_pocos_elementos(void);
void pruebas_heap_muchos_elementos(void);
void pruebas_heap_sort(void);

void pruebas_heap_alumno(void){
	pruebas_heap_vacio();
	pruebas_heap_un_elemento();
	pruebas_heap_pocos_elementos();
	pruebas_heap_muchos_elementos();
	pruebas_heap_sort();
}
int maximo_(const int* a,const int* b){
	if(*a > *b) return 1;
	if(*a < *b) return -1;
	return 0;
}
int maximo(const void* a, const void* b){
	return maximo_(a,b);
}
void pruebas_heap_vacio(){
	printf("\n\nPRUEBAS HEAP VACIO:\n\n");

	heap_t* heap = heap_crear(maximo);

	print_test("La heap esta vacio: ", heap_esta_vacio(heap) == true);

	print_test("El primero de la heap vacio es NULL: ", heap_ver_max(heap) == NULL);

	print_test("Desencolar un elemento da NULL", heap_desencolar(heap)==NULL);

	heap_destruir(heap, NULL);
}

void pruebas_heap_un_elemento(){
	heap_t* heap=heap_crear(maximo);
	int elemento[1]={4};

	printf("\n\nPRUEBAS HEAP UN ELEMENTO:\n\n");

	print_test("Encolo el elemento: ", heap_encolar(heap,elemento) == true);

	print_test("El heap ya no esta vacio: ", heap_esta_vacio(heap) == false);

	print_test("El max del heap es el elemento: ", heap_ver_max(heap) == elemento);

	print_test("Desencolar el elemento devuelve el elemento: ", heap_desencolar(heap) == elemento);

	print_test("La heap ahora esta vacio: ", heap_esta_vacio(heap) == true);

	print_test("Desencolar ahora devuelve NULL: ", heap_desencolar(heap) == NULL);

	print_test("El primero de la heap ahora es NULL: ", heap_ver_max(heap) == NULL);	

	heap_destruir(heap, NULL);
}

void pruebas_heap_pocos_elementos(void){
	heap_t* heap=heap_crear(maximo);
	int arr_elementos[5] = {0,9,2,6,4};

	printf("\n\nPRUEBAS heap CON POCOS ELEMENTOS :\n\n");

	print_test("La heap esta vacio", heap_esta_vacio(heap) == true);

	for(int i=0;i<5;i++){
		print_test("Encolo los 5 elementos", heap_encolar(heap,&arr_elementos[i]) == true);
	}

	print_test("El primero sigue siendo arr_elementos[0]: ", heap_ver_max(heap) == &arr_elementos[1]);

	print_test("Desencolo los 5 elementos y me dan el valor que deben dar: ", heap_desencolar(heap) == &arr_elementos[1]);
	print_test("Desencolo los 5 elementos y me dan el valor que deben dar: ", heap_desencolar(heap) == &arr_elementos[3]);
	print_test("Desencolo los 5 elementos y me dan el valor que deben dar: ", heap_desencolar(heap) == &arr_elementos[4]);
	print_test("Desencolo los 5 elementos y me dan el valor que deben dar: ", heap_desencolar(heap) == &arr_elementos[2]);
	print_test("Desencolo los 5 elementos y me dan el valor que deben dar: ", heap_desencolar(heap) == &arr_elementos[0]);

	print_test("La heap esta vacio: ", heap_esta_vacio(heap) == true);

	heap_destruir(heap, NULL);
}

void pruebas_heap_muchos_elementos(void){

	heap_t* heap=heap_crear(maximo);
	int arr_elementos[ELEMENTOS];

	printf("\n\nPRUEBAS heap CON MUCHOS ELEMENTOS :\n\n");

	for(int i=0;i<ELEMENTOS;i++){
		arr_elementos[i]=i;
	}

	bool se_encolaron=true;

	for(int i=0;i<ELEMENTOS;i++){
		if(!heap_encolar(heap,&arr_elementos[i])) se_encolaron=false;
	}

	print_test("Se encolaron correctamente los elementos: ", se_encolaron == true);

	print_test("El primero sigue siendo arr_elementos[0]: ", heap_ver_max(heap) == &arr_elementos[ELEMENTOS-1]);

	print_test("La heap no esta vacio: ", heap_esta_vacio(heap) == false);

	bool se_desencolaron=true;

	for(int j=0;j<ELEMENTOS;j++){
		if(heap_desencolar(heap)!=&arr_elementos[ELEMENTOS - j -1]) se_desencolaron=false;
	}

	print_test("Se desencolaron todos los elementos de forma correcta: ", se_desencolaron == true);

	print_test("La heap esta vacio: ", heap_esta_vacio(heap) == true);

	print_test("Desencolar una vez mas da NULL: ", heap_desencolar(heap) == NULL);

	heap_destruir(heap, NULL);

}
void heap_sort_(void* array, int n, cmp_func_t cmp){
	heap_sort(array, n, cmp);
}
void pruebas_heap_sort(){
	int arreglo[10] = {9,8,5,2,7,6,4,3,1,0};
	int *array[10];
	for(int i = 0; i <10; i++) array[i] = &arreglo[i];
	int ordenado[] = {0,1,2,3,4,5,6,7,8,9};

	heap_sort_(&array, 10, maximo);
	bool ok = true;
	for(int j = 0; j<10; j++){
		ok = (ordenado[j] = *array[j]);	
	}
	print_test("El arreglo se ordeno de menor a mayor", ok);
}
