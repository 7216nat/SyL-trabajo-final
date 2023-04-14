#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
 
using namespace std;

void danglingPointer(std::shared_ptr<int> ptr) {
    // inicializar el puntero
    std::shared_ptr<int> temp (new int(10));
    // comprorbar que el puntero no es nulo
    cout << "temp use count: " << temp.use_count() << endl;
    cout << "ptr use count: " << ptr.use_count() << endl;
    // compartir el puntero con el puntero recibido
    ptr = temp;

    // Verificar que ambos punteros apuntan a la misma direccion
    printf("Si se asigna a una direccion de una variable en stack: ptr(%d) = temp(%d) = %d\n", *ptr, *temp, *ptr);
    cout << "temp use count: " << temp.use_count() << endl;
    cout << "ptr use count: " << ptr.use_count() << endl;
    return;
}

void danglingPointer2() {
    std::shared_ptr<int> ptr;
    danglingPointer(ptr);
    // Se ve que la direccion compartida ha sido liberada una vez que se sale de la subrutina
    cout << "ptr use count: " << ptr.use_count() << endl;
    cout << "Efectivamente, la direccion compartida ha sido liberada una vez que se sale de la subrutina" << endl;

    printf("Luego se intenta acceder desde la funcion invocante: indefinido -> %d\n", *ptr);
}

int main() {
    danglingPointer2();
    return 0;
}