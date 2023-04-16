#include <stdio.h>
#include <stdlib.h>
 
void danglingPointer1() {
    // puntero a entero
    printf("------ Dangling Pointer 1 --------\n");
    int *ptr = (int *)malloc(sizeof(int));
 
    *ptr = 15;
    printf("Variable definida a: %d\n", *ptr);
 
    // liberar memoria
    free(ptr);

    // ptr es un puntero huerfano
    printf("Puntero liberado, entonces valor se queda indefinido: %d\n", *ptr);
    printf("------ Dangling Pointer 1 --------\n\n");
    return;
}

void danglingPointer2() {
    int *ptr;
    printf("------ Dangling Pointer 2 --------\n");
    printf("Se crea un puntero sin inicializar\n");
    if(ptr != NULL){
        printf("puntero no es null\n");
    }
    printf("\n");
    printf("si se intentar leer el puntero: indefinido -> %d\n",*ptr);
}

void danglingPointer3() {

    printf("------ Dangling Pointer 3 --------\n");
    int *ptr1;
    int *ptr2;

    ptr1 = (int *)malloc(sizeof(int));
    *ptr1 = 10;
    ptr2 = ptr1;
    printf("2 variables 1 direccion de memoria reservada --> ptr1: %d, ptr2: %d\n", *ptr1, *ptr2);

    printf("Libera la memoria de ptr1 \n");
    // liberar memoria de ptr1
    free(ptr1);

    // ptr es un puntero huerfano
    printf("Luego se intenta acceder a la direccion reservada que previamente ptr1 haya sido liberada: indefinido -> %d\n", *ptr2);
    printf("------ Dangling Pointer 3 --------\n\n");
}

int main() {
    danglingPointer1();
    danglingPointer2();
    danglingPointer3();
    return 0;
}
