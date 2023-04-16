#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
 
using namespace std;

std::shared_ptr<int> danglingPointer() {
    // inicializar el puntero
    std::shared_ptr<int> temp (new int(10));
    // comprorbar que el puntero no es nulo
    cout << "temp use count: " << temp.use_count() << endl;
    return temp;
}

void danglingPointer2() {
    std::shared_ptr<int> ptr;
    ptr = danglingPointer();
    // Se ve que la direccion compartida ha sido liberada una vez que se sale de la subrutina
    cout << "ptr use count: " << ptr.use_count() << endl;
    cout << "Efectivamente, la direccion compartida ha sido liberada una vez que se sale de la subrutina" << endl;

    printf("Luego se intenta acceder desde la funcion invocante: indefinido -> %d\n", *ptr);
}

int main() {
    danglingPointer2();
    return 0;
}