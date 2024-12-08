#include <iostream>

int main() {
    // Создаем массив из 10 элементов типа double
    int n = 10;
    double* array = new double[n];  // Выделяем память для массива

    // Заполняем массив числами (например, от 1.0 до 10.0)
    for (int i = 0; i < n; i++) {
        array[i] = i + 1.0;
    }

    // Выводим содержимое массива
    std::cout << "Содержимое массива:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }

    // Определяем адрес начала массива и смещения элементов
    std::cout << "\nАдрес начала массива: " << static_cast<void*>(array) << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Адрес элемента array[" << i << "]: " << static_cast<void*>(array + i)
            << " (смещение от начала: " << (array + i) - array << " элементов)" << std::endl;
    }

    // Освобождаем выделенную память
    delete[] array;

    return 0;
}
