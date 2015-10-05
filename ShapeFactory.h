#ifndef __ShapeFactory_H
#define __ShapeFactory_H

#include <functional>
#include <unordered_map>

class Shape;

class ShapeFactory {
public:
    using Callback = std::function<std::unique_ptr<Shape> ()>;

private:
    using CallbackMap = std::unordered_map<int, Callback>;

public:
    bool Register(int id, Callback callback);
    std::unique_ptr<Shape> Create(int id) const;

    static ShapeFactory& Instance() {
        static ShapeFactory instance;
        return instance;
    }

private:
    CallbackMap callbacks_;

    ShapeFactory() {
    }
};

#endif
