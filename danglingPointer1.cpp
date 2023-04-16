#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
 
using namespace std;
void danglingPointer1() {
    std::unique_ptr<int> ptr(new int);
    // definir un valor a la variable
    *ptr = 15;
    printf("Variable definida a: %d\n", *ptr);
    
    // liberar el puntero con la funcion reset
    printf("Puntero liberado, entonces si se intenta acceder da un error de ejecución: \n");
    ptr.reset();    

    // intentar reproduri el error de dangling pointer
    printf("%d\n", *ptr);
}

int main() {
    danglingPointer1();
    return 0;
}