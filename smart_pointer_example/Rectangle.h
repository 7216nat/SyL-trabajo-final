#ifndef SMART_POINTERS_RECTANGLE_H
#define SMART_POINTERS_RECTANGLE_H

#include <memory>

using namespace std;

class Rectangle {
    int length;
    int width;

public:
    Rectangle(int l, int w);
    int Area();
    void SetLength(int length);
    void SetWidth(int width);
    Rectangle(shared_ptr<Rectangle> sharedPtr);
};

#endif //SMART_POINTERS_RECTANGLE_H