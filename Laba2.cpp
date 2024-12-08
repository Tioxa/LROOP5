#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    virtual void getdata() {
        cout << "Введите название книги: ";
        getline(cin, title);
        cout << "Введите цену книги: ";
        cin >> price;
        cin.ignore(); // Очищаем буфер после ввода числа
    }

    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }
};

class Sales {
protected:
    float sales[3]; // массив для хранения продаж за последние три месяца

public:
    Sales() : sales{ 0.0, 0.0, 0.0 } {}

    void getdata() {
        cout << "Введите продажи за последние три месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putdata() const {
        cout << "Продажи за последние три месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": " << sales[i] << " руб." << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int page_count;

public:
    Book() : page_count(0) {}

    void getdata() override {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> page_count;
        cin.ignore(); // Очищаем буфер после ввода числа
        Sales::getdata(); // получение данных о продажах
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Количество страниц: " << page_count << endl;
        Sales::putdata(); // вывод данных о продажах
    }
};

class Type : public Publication, public Sales {
private:
    float play_time;

public:
    Type() : play_time(0.0) {}

    void getdata() override {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> play_time;
        cin.ignore(); // Очищаем буфер после ввода числа
        Sales::getdata(); // получение данных о продажах
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Время записи: " << play_time << " минут" << endl;
        Sales::putdata(); // вывод данных о продажах
    }
};

int main() {
    setlocale(0, "");
    Book myBook;
    Type myType;

    cout << "Введите данные для книги:" << endl;
    myBook.getdata();
    cout << "\nВведите данные для аудиозаписи:" << endl;
    myType.getdata();

    cout << "\nДанные о книге:" << endl;
    myBook.putdata();

    cout << "\nДанные об аудиозаписи:" << endl;
    myType.putdata();

    return 0;
}