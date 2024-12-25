#include <iostream>
#include <stdexcept>
#include <vector>

// ������� ����� "�������� ������������"
class Transport {
public:
    virtual void describe() const = 0; // ����� ����������� �������
    virtual ~Transport() = default;   // ����������� ����������
};

// ����� "���������"
class Bicycle : public Transport {
public:
    void describe() const override {
        std::cout << "This is a bicycle." << std::endl;
    }
};

// ����� "����������"
class Car : public Transport {
public:
    void describe() const override {
        std::cout << "This is a car." << std::endl;
    }
};

// ����� "��������"
class Truck : public Transport {
public:
    void describe() const override {
        std::cout << "This is a truck." << std::endl;
    }
};

// ��������� ����� ��� �������� ������� ����������
template <typename T>
class PointerArray {
private:
    std::vector<T*> data; // ������ ����������

public:
    // �����������
    PointerArray() = default;

    // ���������� ����������� ������
    ~PointerArray() {
        for (T* ptr : data) {
            delete ptr;
        }
    }

    // ���������� ��������
    void add(T* element) {
        data.push_back(element);
    }

    // ���������� ��������� []
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

    // ��������� �������
    std::size_t size() const {
        return data.size();
    }
};

// ������� ������������ ������
int main() {
    try {
        // ������� ������ ���������� �� �������� ������������
        PointerArray<Transport> transportArray;

        // ��������� ������� ������ �����
        transportArray.add(new Bicycle());
        transportArray.add(new Car());
        transportArray.add(new Truck());

        // ������������� ������ ���������� ��������� []
        for (std::size_t i = 0; i < transportArray.size(); ++i) {
            transportArray[i].describe();
        }

        // ������� ���������� � �������� � �������������� ��������
        transportArray[10].describe(); // ������ ����������

    }
    catch (const std::logic_error& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // �������� �� ������ ������ ����� ��������������, ��� ��� � ���������� ������ � ����������� PointerArray
    return 0;
}