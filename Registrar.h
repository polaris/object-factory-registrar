#ifndef __Registrar_H
#define __Registrar_H

#include "ShapeFactory.h"

#include <memory>

template <typename T, int ID>
class Registrar {
    static const bool registered;
};

template <typename T, int ID>
const bool Registrar<T, ID>::registered = ShapeFactory::Instance().Register(ID, [] {
    return std::make_unique<T>();
});

#endif
