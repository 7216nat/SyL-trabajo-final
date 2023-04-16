#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
 
using namespace std;

void danglingPointer2() {
    std::shared_ptr<int> ptr;
    // Se ve que el puntero se a inicializado como nullptr
    cout << "ptr use count: " << ptr.use_count() << endl;
    cout << "Efectivamente, el puntero es null" << endl;
    if (ptr == nullptr) {
        cout << "ptr es null" << endl;
    }

    cout << ptr.get() << endl;
    printf("Luego se intenta acceder desde la funcion invocante: -> %d\n", *ptr);

}

int main() {
    danglingPointer2();
    return 0;
}