#include "ShapeFactory.h"
#include "Shape.h"

#include <stdexcept>

bool ShapeFactory::Register(int id, Callback callback) {
    callbacks_.insert(CallbackMap::value_type(id, callback));
    return true;
}

std::unique_ptr<Shape> ShapeFactory::Create(int id) const {
    const auto itr = callbacks_.find(id);
    if (itr == callbacks_.end()) {
        throw std::runtime_error("unknown shape id");
    } else {
        return itr->second();
    }
}
