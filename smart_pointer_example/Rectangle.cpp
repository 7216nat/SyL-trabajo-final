#include "Rectangle.h"

Rectangle::Rectangle(int l, int b) {
    length = l;
    width = b;
}

int Rectangle::Area() {
    return length * width;
}

Rectangle::Rectangle(shared_ptr<Rectangle> sharedPtr) {
    length = sharedPtr->length;
    width = sharedPtr->width;
}

void Rectangle::SetLength(int length) {
    this->length = length;
}

void Rectangle::SetWidth(int width) {
    this->width = width;
}