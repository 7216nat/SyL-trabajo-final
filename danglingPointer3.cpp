#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
 
using namespace std;

void danglingPointer3() {
    std::shared_ptr<int> ptr1 (new int(10));
    std::shared_ptr<int> ptr2;

    ptr2 = ptr1;
    cout << "2 variables 1 direccion de memoria reservada ptr1 = ptr2 = " << *ptr1 <<" --> ptr1: " << ptr1.get() <<  " ptr2: " << ptr2.get() << endl;

    printf("Libera la memoria de ptr1 \n");
    // liberar el puntero ptr1
    ptr1.reset();

    // ptr es un puntero huerfano
    printf("Luego se intenta acceder a la direccion reservada habiendo eliminado la referencia de ptr1 -> ptr2: %d\n", *ptr2);
}

int main() {
    danglingPointer3();
    return 0;
}