#include <iostream>
#include <memory>
#include "Rectangle.h"

using namespace std;

void UniquePointer_show() {
    cout << "------------- Unique Pointer -------------" << endl;
    std::unique_ptr<Rectangle> uniqueP1(new Rectangle(10, 5));
    // printea 50
    cout << "UniqueP1 Area: " << uniqueP1->Area() << endl << endl;

    std::unique_ptr<Rectangle> uniqueP2;
    // uniqueP2 = uniqueP1; // No se puede hacer esto

    // Reasignamos el puntero 
    uniqueP2 = move(uniqueP1);
    cout << "UniqueP1 moved to UniqueP2: " << endl << endl;

    // Verificamos que el puntero uniqueP1 sea nulo
    if (uniqueP1 == NULL){
        cout << "UniqueP1 is NULL!" << endl;
    }

    // Verificamos que tampoco se pueda acceder al objeto
    if (uniqueP1.get() == NULL){
        cout << "UniqueP1.get() is NULL!" << endl << endl;
    }
    // printea 50
    cout << "UniqueP2 Area: " <<  uniqueP2->Area() << endl;
    cout << "------------- Unique Pointer -------------" << endl << endl;
}

unique_ptr<Rectangle> doSomething(){
    unique_ptr<Rectangle> UniqueP1(new Rectangle(10, 10));
    cout << "UniqueP1 Area: " <<  UniqueP1->Area() << endl;
    //return move(UniqueP1);
    return UniqueP1;
}

void return_unique_ptr(){
    cout << "------------- Unique Pointer Return-------------" << endl << endl;

    unique_ptr<Rectangle> uniqueP2;
    uniqueP2 = doSomething();
    cout << "Return from func" << endl;
    cout << "UniqueP2 Area: " <<  uniqueP2->Area() << endl;

    cout << "------------- Unique Pointer Return-------------" << endl << endl;

}

void shared_ptr_inside(shared_ptr<Rectangle> *P2, shared_ptr<Rectangle> *P1){
    shared_ptr<Rectangle> P3;
    P3 = *P1;

    cout << "P3 created and pointed to P1" << endl;
    // Compartimos el puntero con el tercer puntero
    cout << "P1 Use Count: " << P1->use_count() << endl;
    cout << "P2 Use Count: " << P2->use_count() << endl;
    cout << "P3 Use Count: " << P3.use_count() << endl << endl;

    // Al salir de la función el puntero se va a eliminar
}

void SharedPointer_show() {
    cout << "------------- Shared Pointer -------------" << endl;
    std::shared_ptr<Rectangle> P1 = std::shared_ptr<Rectangle>(new Rectangle(10, 5));
    // printea 50
    cout << "P1 Area: " << P1->Area() << endl << endl;

    cout << "P2 created and pointed to P1" << endl;
    std::shared_ptr<Rectangle> P2 = P1;

    // Printea 50
    cout << "P2 Area: " << P2->Area() << endl;

    // Puntero compartido
    cout << "P1 Area: " << P1->Area() << endl << endl;

    // Verificamos el contador de referencias
    cout << "P1 Use Count: " << P1.use_count() << endl;
    cout << "P2 Use Count: " << P2.use_count() << endl << endl;

    shared_ptr_inside(&P2, &P1); 

    cout << "Left function P3" << endl;
    cout << "P1 Use Count: " << P1.use_count() << endl;
    cout << "P2 Use Count: " << P2.use_count() << endl << endl;

    // Resetemos el puntero P2 y para ver que el contador de referencias se decrementa
    cout << "P2 reseted" << endl;
    P2.reset();
    cout << "P1 Area: " << P1->Area() << endl;
    cout << "P1 Use Count: " << P1.use_count() << endl;

    cout << "------------- Shared Pointer -------------" << endl << endl;
}

void SharedPointer_show_2() {
    cout << "------------- Shared Pointer -------------" << endl;
    std::shared_ptr<Rectangle> P1 = std::shared_ptr<Rectangle>(new Rectangle(10, 5));
    // printea 50
    cout << "P1 Area: " << P1->Area() << endl << endl;

    cout << "P2 created and pointed to P1" << endl;
    std::shared_ptr<Rectangle> P2 = P1;

    // Printea 50
    cout << "P2 Area: " << P2->Area() << endl;

    // Puntero compartido
    cout << "P1 Area: " << P1->Area() << endl << endl;

    // Verificamos el contador de referencias
    cout << "P1 Use Count: " << P1.use_count() << endl;
    cout << "P2 Use Count: " << P2.use_count() << endl << endl;

    shared_ptr<Rectangle> P3;
    P3 = P1;

    cout << "P3 created and pointed to P1" << endl;
    // Compartimos el puntero con el tercer puntero
    cout << "P1 Use Count: " << P1.use_count() << endl;
    cout << "P2 Use Count: " << P2.use_count() << endl;
    cout << "P3 Use Count: " << P3.use_count() << endl << endl;

    // Resetemos el puntero P3 y para ver que el contador de referencias se decrementa
    cout << "P3 reseted" << endl;
    P3.reset();
    cout << "P1 Use Count: " << P1.use_count() << endl;
    cout << "P2 Use Count: " << P2.use_count() << endl << endl;

    // Resetemos el puntero P2 y para ver que el contador de referencias se decrementa
    cout << "P2 reseted" << endl;
    P2.reset();
    cout << "P1 Use Count: " << P1.use_count() << endl;

    cout << "------------- Shared Pointer -------------" << endl << endl;
}

void WeakPointer_show() {
    cout << "------------- Weak Pointer -------------" << endl;
    //std::shared_ptr<Rectangle> P1 = std::shared_ptr<Rectangle>(new Rectangle(10, 5));
    std::shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    // printea 50
    cout << "P1 Area: " << P1->Area() << endl;

    std::weak_ptr<Rectangle> WP1 = P1;
    cout << "WP1 points to P1, WP1 Use Count = " << WP1.use_count() << endl;
    cout << "P1 Use Count: " << P1.use_count() << endl << endl;
    P1->SetLength(20);

    // intentamos acceder al objeto convertiendo el weak pointer a shared pointer
    if (std::shared_ptr<Rectangle> check = WP1.lock()) {
        cout << "P1 double its length, *WP1 Area = " << check->Area() << endl;
        cout << "P1 Use Count: " << P1.use_count() << endl << endl;
    } else {
        cout << "WP1 is expired\n";
    }

    cout << "Out of if clause, WP1 Use Count = " << WP1.use_count() << endl;
    cout << "P1 Use Count = " << P1.use_count() << endl;
    // reseteamos el puntero compartido y verificamos que el weak pointer se convierte en nulo
    P1.reset();
    cout << "After reseting P1, WP1 Use Count = " << WP1.use_count() << endl;
    if (auto check = WP1.lock()) {
        cout << "*WP1 Area = " << check->Area() << endl;
    } else {
        cout << "WP1 is expired\n";
    }
    cout << "------------- Weak Pointer -------------" << endl;
}
int main() {
    UniquePointer_show();
    return_unique_ptr();
    SharedPointer_show();
    WeakPointer_show();

    return 0;
}