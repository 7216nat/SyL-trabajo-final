#include <stdio.h>
#include <stdlib.h>
 
void danglingPointer1() {
    int *ptr = (int *)malloc(sizeof(int)); // normal pointer
 
    *ptr = 15;
    printf("Variable definida a: %d\n", *ptr);
 
    // memory block deallocated using free() function
    free(ptr);

    // here ptr acts as a dangling pointer
    printf("Puntero liberado, entonces valor se queda indefinido: %d\n", *ptr);
}

void danglingPointer(int *ptr) {
    int temp = 10;
    ptr = &temp; // acting as normal pointer
    // now ptr is a dangling pointer
    printf("Si se asigna a una direccion de una variable en stack: ptr = temp = %d\n", *ptr);
    return;
}

void danglingPointer2() {
    int *ptr; 

    danglingPointer(ptr);

    printf("Luego se intenta acceder desde la funcion invocante: indefinido -> %d\n", *ptr);
}

int main() {
    danglingPointer1();
    danglingPointer2();
    return 0;
}