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

void danglingPointer(int *ptr) {
    int temp = 10;
    // apuntando a una variable en stack
    ptr = &temp;
    // El valor se puede acceder mediante los dos punteros
    printf("Si se asigna a una direccion de una variable en stack: ptr(%d) = temp(%d) = %d\n", *ptr, temp, *ptr);
    return;
}

void danglingPointer2() {
    int *ptr; 
    printf("------ Dangling Pointer 2 --------\n");
    danglingPointer(ptr);
    // ptr es un puntero huerfano
    printf("Luego se intenta acceder desde la funcion invocante: indefinido -> %d\n", *ptr);
    printf("------ Dangling Pointer 2 --------\n\n");
}

int main() {
    danglingPointer1();
    danglingPointer2();
    return 0;
}