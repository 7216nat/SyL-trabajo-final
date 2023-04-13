#include <iostream>
#include <memory>
#include "Rectangle.h"

using namespace std;

void UniquePointer_show() {
    cout << "------------- Unique Pointer -------------" << endl;
    std::unique_ptr<Rectangle> uniqueP1(new Rectangle(10, 5));
    // printea 50
    cout << "UniqueP1 Area: " << uniqueP1->Area() << endl;

    std::unique_ptr<Rectangle> uniqueP2;
    // uniqueP2 = uniqueP1; // No se puede hacer esto

    uniqueP2 = move(uniqueP1);
    cout << "UniqueP1 moved to UniqueP2: " << endl;

    if (uniqueP1 == NULL){
        cout << "UniqueP1 is NULL!" << endl;
    }

    if (uniqueP1.get() == NULL){
        cout << "UniqueP1.get() is NULL!" << endl;
    }
    // printea 50
    cout << "UniqueP2 Area: " <<  uniqueP2->Area() << endl;
    cout << "------------- Unique Pointer -------------" << endl;
}

void SharedPointer_show() {
    cout << "------------- Shared Pointer -------------" << endl;
    std::shared_ptr<Rectangle> P1 = std::shared_ptr<Rectangle>(new Rectangle(10, 5));
    // printea 50
    cout << "P1 Area: " << P1->Area() << endl;

    cout << "P2 created and pointed to P1" << endl;
    std::shared_ptr<Rectangle> P2 = P1;

    // Printea 50
    cout << "P2 Area: " << P2->Area() << endl;

    // Puntero compartido
    cout << "P1 Area: " << P1->Area() << endl;

    // Verificamos el contador de referencias
    cout << "P1 Use Count: " << P1.use_count() << endl;
    cout << "P2 Use Count: " << P2.use_count() << endl;

    shared_ptr<Rectangle> P3;
    P3 = P1;

    cout << "P3 created and pointed to P1" << endl;
    // Compartimos el puntero con el tercer puntero
    cout << "P1 Use Count: " << P1.use_count() << endl;
    cout << "P2 Use Count: " << P2.use_count() << endl;
    cout << "P3 Use Count: " << P3.use_count() << endl;

    cout << "P3 reseted" << endl;
    P3.reset();
    cout << "P1 Use Count: " << P1.use_count() << endl;
    cout << "P2 Use Count: " << P2.use_count() << endl;
    cout << "P2 reseted" << endl;
    P2.reset();
    cout << "P1 Use Count: " << P1.use_count() << endl;

    cout << "------------- Shared Pointer -------------" << endl;
}

void WeakPointer_show() {
    cout << "------------- Weak Pointer -------------" << endl;
    std::shared_ptr<Rectangle> P1 = std::shared_ptr<Rectangle>(new Rectangle(10, 5));
    // printea 50
    cout << "P1 Area: " << P1->Area() << endl;

    std::weak_ptr<Rectangle> WP1 = P1;
    cout << "WP1 points to P1, WP1 Use Count = " << WP1.use_count() << endl;
    cout << "P1 Use Count: " << P1.use_count() << endl;
    P1->SetLength(20);
    if (auto check = WP1.lock()) {
        cout << "P1 double its length, *WP1 Area = " << check->Area() << endl;
    } else {
        cout << "WP1 is expired\n";
    }

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
    SharedPointer_show();
    WeakPointer_show();
    return 0;
}