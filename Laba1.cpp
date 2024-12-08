#include <iostream>

int main() {
    // ������� ������ �� 10 ��������� ���� double
    int n = 10;
    double* array = new double[n];  // �������� ������ ��� �������

    // ��������� ������ ������� (��������, �� 1.0 �� 10.0)
    for (int i = 0; i < n; i++) {
        array[i] = i + 1.0;
    }

    // ������� ���������� �������
    std::cout << "���������� �������:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }

    // ���������� ����� ������ ������� � �������� ���������
    std::cout << "\n����� ������ �������: " << static_cast<void*>(array) << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "����� �������� array[" << i << "]: " << static_cast<void*>(array + i)
            << " (�������� �� ������: " << (array + i) - array << " ���������)" << std::endl;
    }

    // ����������� ���������� ������
    delete[] array;

    return 0;
}
