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
        cout << "������� �������� �����: ";
        getline(cin, title);
        cout << "������� ���� �����: ";
        cin >> price;
        cin.ignore(); // ������� ����� ����� ����� �����
    }

    virtual void putdata() const {
        cout << "��������: " << title << endl;
        cout << "����: " << price << " ���." << endl;
    }
};

class Sales {
protected:
    float sales[3]; // ������ ��� �������� ������ �� ��������� ��� ������

public:
    Sales() : sales{ 0.0, 0.0, 0.0 } {}

    void getdata() {
        cout << "������� ������� �� ��������� ��� ������:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "����� " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putdata() const {
        cout << "������� �� ��������� ��� ������:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "����� " << i + 1 << ": " << sales[i] << " ���." << endl;
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
        cout << "������� ���������� �������: ";
        cin >> page_count;
        cin.ignore(); // ������� ����� ����� ����� �����
        Sales::getdata(); // ��������� ������ � ��������
    }

    void putdata() const override {
        Publication::putdata();
        cout << "���������� �������: " << page_count << endl;
        Sales::putdata(); // ����� ������ � ��������
    }
};

class Type : public Publication, public Sales {
private:
    float play_time;

public:
    Type() : play_time(0.0) {}

    void getdata() override {
        Publication::getdata();
        cout << "������� ����� ������ (� �������): ";
        cin >> play_time;
        cin.ignore(); // ������� ����� ����� ����� �����
        Sales::getdata(); // ��������� ������ � ��������
    }

    void putdata() const override {
        Publication::putdata();
        cout << "����� ������: " << play_time << " �����" << endl;
        Sales::putdata(); // ����� ������ � ��������
    }
};

int main() {
    setlocale(0, "");
    Book myBook;
    Type myType;

    cout << "������� ������ ��� �����:" << endl;
    myBook.getdata();
    cout << "\n������� ������ ��� �����������:" << endl;
    myType.getdata();

    cout << "\n������ � �����:" << endl;
    myBook.putdata();

    cout << "\n������ �� �����������:" << endl;
    myType.putdata();

    return 0;
}