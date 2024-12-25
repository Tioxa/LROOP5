// ������� 1
/*
#include <iostream>
#include <vector>
#include <memory>

// ������� ����� Detail
class Detail {
protected:
    Detail(const std::string& name) : name(name) {}
    virtual ~Detail() = default;

public:
    virtual void display() const = 0;

protected:
    std::string name;
};

// ����������� ����� Assembly
class Assembly : public Detail {
protected:
    Assembly(const std::string& name) : Detail(name) {}

public:
    void display() const override {
        std::cout << "Assembly: " << name << std::endl;
    }

    // ��������� ����� ��� �������� ����������
    static std::shared_ptr<Assembly> create(const std::string& name) {
        return std::shared_ptr<Assembly>(new Assembly(name));
    }
};

// ����������� ����� Component
class Component : public Detail {
protected:
    Component(const std::string& name) : Detail(name) {}

public:
    void display() const override {
        std::cout << "Component: " << name << std::endl;
    }

    // ��������� ����� ��� �������� ����������
    static std::shared_ptr<Component> create(const std::string& name) {
        return std::shared_ptr<Component>(new Component(name));
    }
};

int main() {
    // ������ ��� �������� ���������� �� ������� �����
    std::vector<std::shared_ptr<Detail>> storage;

    // ������� ������� � ������� ��������� �������
    auto assembly1 = Assembly::create("Main Assembly");
    auto component1 = Component::create("Bolt");
    auto component2 = Component::create("Nut");

    // �������� �� � ������
    storage.push_back(assembly1);
    storage.push_back(component1);
    storage.push_back(component2);

    // ������� ���������� ��� ���� ���������
    for (const auto& item : storage) {
        item->display();
    }

    return 0;
}
*/

// ������� 2

#include <iostream>
#include <vector>
#include <memory>
#include <random>

// ������� �����
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

    // ����������� ����� ������������
    virtual std::shared_ptr<Base> clone() const {
        return std::make_shared<Base>(*this);
    }
};

// ����������� �����
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

    // ��������������� ������ ������������
    std::shared_ptr<Base> clone() const override {
        return std::make_shared<Derived>(*this);
    }
};

// ������� ��� ���������� �������� � ����� ���������
void add(std::vector<std::shared_ptr<Base>>& storage, const std::shared_ptr<Base>& obj) {
    storage.push_back(obj->clone());
}

int main() {
    // ������ ��� �������� ��������
    std::vector<std::shared_ptr<Base>> storage;

    // ��������� ��������� �����
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    // �������� ��������� ��������
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

    // ������������ ������������
    std::cout << "\nStored objects behavior:\n";
    for (const auto& obj : storage) {
        obj->behavior();
    }

    // ������������ ������ (���������� ������������� ��� ������ �� scope)
    storage.clear();
    std::cout << "\nAll resources have been freed.\n";

    return 0;
}