#include "ShapeFactory.h"
#include "Shape.h"

#include <iostream>

int main(int, char const **) {
    auto shape1 = ShapeFactory::Instance().Create(0);
    auto shape2 = ShapeFactory::Instance().Create(1);
    shape1->draw();
    shape2->draw();
}
