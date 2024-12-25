// задание 1
/*
#include <iostream>
#include <vector>
#include <memory>

// Базовый класс Detail
class Detail {
protected:
    Detail(const std::string& name) : name(name) {}
    virtual ~Detail() = default;

public:
    virtual void display() const = 0;

protected:
    std::string name;
};

// Производный класс Assembly
class Assembly : public Detail {
protected:
    Assembly(const std::string& name) : Detail(name) {}

public:
    void display() const override {
        std::cout << "Assembly: " << name << std::endl;
    }

    // Фабричный метод для создания экземпляра
    static std::shared_ptr<Assembly> create(const std::string& name) {
        return std::shared_ptr<Assembly>(new Assembly(name));
    }
};

// Производный класс Component
class Component : public Detail {
protected:
    Component(const std::string& name) : Detail(name) {}

public:
    void display() const override {
        std::cout << "Component: " << name << std::endl;
    }

    // Фабричный метод для создания экземпляра
    static std::shared_ptr<Component> create(const std::string& name) {
        return std::shared_ptr<Component>(new Component(name));
    }
};

int main() {
    // Вектор для хранения указателей на базовый класс
    std::vector<std::shared_ptr<Detail>> storage;

    // Создаем объекты с помощью фабричных методов
    auto assembly1 = Assembly::create("Main Assembly");
    auto component1 = Component::create("Bolt");
    auto component2 = Component::create("Nut");

    // Помещаем их в вектор
    storage.push_back(assembly1);
    storage.push_back(component1);
    storage.push_back(component2);

    // Выводим информацию обо всех элементах
    for (const auto& item : storage) {
        item->display();
    }

    return 0;
}
*/

// задание 2

#include <iostream>
#include <vector>
#include <memory>
#include <random>

// Базовый класс
class Base {
public:
    Base() {
        std::cout << "Base constructed\n";
    }

    virtual ~Base() {
        std::cout << "Base destructed\n";
    }

    virtual void behavior() const {
        std::cout << "Base behavior\n";
    }

    // Виртуальный метод клонирования
    virtual std::shared_ptr<Base> clone() const {
        return std::make_shared<Base>(*this);
    }
};

// Производный класс
class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructed\n";
    }

    ~Derived() override {
        std::cout << "Derived destructed\n";
    }

    void behavior() const override {
        std::cout << "Derived behavior\n";
    }

    // Переопределение метода клонирования
    std::shared_ptr<Base> clone() const override {
        return std::make_shared<Derived>(*this);
    }
};

// Функция для добавления объектов в общее хранилище
void add(std::vector<std::shared_ptr<Base>>& storage, const std::shared_ptr<Base>& obj) {
    storage.push_back(obj->clone());
}

int main() {
    // Вектор для хранения объектов
    std::vector<std::shared_ptr<Base>> storage;

    // Генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    // Создание случайных объектов
    for (int i = 0; i < 10; ++i) {
        if (dist(gen) % 2 == 0) {
            auto baseObj = std::make_shared<Base>();
            add(storage, baseObj);
        }
        else {
            auto derivedObj = std::make_shared<Derived>();
            add(storage, derivedObj);
        }
    }

    // Демонстрация полиморфизма
    std::cout << "\nStored objects behavior:\n";
    for (const auto& obj : storage) {
        obj->behavior();
    }

    // Освобождение памяти (происходит автоматически при выходе из scope)
    storage.clear();
    std::cout << "\nAll resources have been freed.\n";

    return 0;
}