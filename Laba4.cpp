#include <iostream>
#include <stdexcept>
#include <vector>

// Базовый класс "Средство передвижения"
class Transport {
public:
    virtual void describe() const = 0; // Чисто виртуальная функция
    virtual ~Transport() = default;   // Виртуальный деструктор
};

// Класс "Велосипед"
class Bicycle : public Transport {
public:
    void describe() const override {
        std::cout << "This is a bicycle." << std::endl;
    }
};

// Класс "Автомобиль"
class Car : public Transport {
public:
    void describe() const override {
        std::cout << "This is a car." << std::endl;
    }
};

// Класс "Грузовик"
class Truck : public Transport {
public:
    void describe() const override {
        std::cout << "This is a truck." << std::endl;
    }
};

// Шаблонный класс для хранения массива указателей
template <typename T>
class PointerArray {
private:
    std::vector<T*> data; // Вектор указателей

public:
    // Конструктор
    PointerArray() = default;

    // Деструктор освобождает память
    ~PointerArray() {
        for (T* ptr : data) {
            delete ptr;
        }
    }

    // Добавление элемента
    void add(T* element) {
        data.push_back(element);
    }

    // Перегрузка оператора []
    T& operator[](std::size_t index) {
        if (index >= data.size()) {
            throw std::logic_error("Index out of range");
        }
        return *data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= data.size()) {
            throw std::logic_error("Index out of range");
        }
        return *data[index];
    }

    // Получение размера
    std::size_t size() const {
        return data.size();
    }
};

// Функция демонстрации работы
int main() {
    try {
        // Создаем массив указателей на средства передвижения
        PointerArray<Transport> transportArray;

        // Добавляем объекты разных типов
        transportArray.add(new Bicycle());
        transportArray.add(new Car());
        transportArray.add(new Truck());

        // Демонстрируем работу перегрузки оператора []
        for (std::size_t i = 0; i < transportArray.size(); ++i) {
            transportArray[i].describe();
        }

        // Попытка обратиться к элементу с несуществующим индексом
        transportArray[10].describe(); // Выброс исключения

    }
    catch (const std::logic_error& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Проверка на утечки памяти будет автоматической, так как я освобождаю память в деструкторе PointerArray
    return 0;
}