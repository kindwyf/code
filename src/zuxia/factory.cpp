#include <iostream>
#include <map>
#include <memory>

template <class Abstract>
class AbstractRegistrar {
public:
    virtual std::unique_ptr<Abstract> Create() = 0;
};

template <class Abstract>
class Factory {
public:
    static Factory<Abstract>& Instance() {
        // TODO
        static Factory<Abstract> instance;
        return instance;
    }
    void Regist(std::string name, AbstractRegistrar<Abstract>* registrar) {
        // TODO
        m_registry[name] = registrar;
    }

    std::unique_ptr<Abstract> Get(std::string name) {
        // TODO
        auto it = m_registry.find(name);
        if (it != m_registry.end()) {
            return it->second->Create();
        }
        return nullptr;
    }

private:
    // TODO
    std::map<std::string, AbstractRegistrar<Abstract>*> m_registry;
};

template <class Abstract, class Instance>
class Registrar : public AbstractRegistrar<Abstract> {
public:
    explicit Registrar(std::string name) {
        // TODO
        Factory<Abstract>::Instance().Regist(name, this);
    }
    std::unique_ptr<Abstract> Create() {
        // TODO
        return std::make_unique<Instance>();
    }
};

class Shape {
public:
    virtual void Draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void Draw() const override { std::cout << "Drawing Circle" << std::endl; }
};

class Rectangle : public Shape {
public:
    void Draw() const override { std::cout << "Drawing Rectangle" << std::endl; }
};

class Triangle : public Shape {
public:
    void Draw() const override { std::cout << "Drawing Triangle" << std::endl; }
};

int main() {
    Registrar<Shape, Circle> circle_registrar("Circle");
    Registrar<Shape, Rectangle> rectangle_registrar("Rectangle");
    Registrar<Shape, Triangle> triangle_registrar("Triangle");

    // Get and use instances from the factory
    auto circle = Factory<Shape>::Instance().Get("Circle");
    if (circle) {
        circle->Draw();
    }

    auto rectangle = Factory<Shape>::Instance().Get("Rectangle");
    if (rectangle) {
        rectangle->Draw();
    }

    auto triangle = Factory<Shape>::Instance().Get("Triangle");
    if (triangle) {
        triangle->Draw();
    }

    return 0;
}
