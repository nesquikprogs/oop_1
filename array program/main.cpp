#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "array_utils.h" // Подключаем заголовочный файл модуля

using namespace std;

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    try {
        // Запускаем все тесты на вычисление произведения
        array_utils::testCalculateProduct();

        // Размер массива, вводимый пользователем
        int size;
        cout << "Введите размер массива: ";
        cin >> size; // Пользователь вводит размер массива

        // Проверка на корректность введённого размера массива
        if (size <= 0) {
            cout << "Размер массива должен быть положительным числом!" << endl;
            return 1;
        }

        // Ввод минимального и максимального значений
        double min, max;
        cout << "Введите минимальное значение: ";
        cin >> min;
        cout << "Введите максимальное значение: ";
        cin >> max;

        // Массив в виде вектора
        vector<double> arr(size);
        array_utils::fillArray(arr, min, max); // Для вектора
        array_utils::printArray(arr); // Для вектора
        string filename = "array_data.txt";
        array_utils::writeArrayToFile(arr, filename); // Для вектора

        vector<double> arrFromFile(size);
        array_utils::readArrayFromFile(arrFromFile, filename); // Для вектора
        array_utils::printArray(arrFromFile); // Для вектора
        double product = array_utils::calculateProduct(arrFromFile); // Для вектора
        cout << "Произведение элементов массива (вектор): " << product << endl;

        // Массив как обычный динамический массив
        double* arrDyn = new double[size];
        array_utils::fillArray(arrDyn, size, min, max); // Для обычного массива
        array_utils::printArray(arrDyn, size); // Для обычного массива
        array_utils::writeArrayToFile(arrDyn, size, filename); // Для обычного массива

        double* arrFromFileDyn = new double[size];
        array_utils::readArrayFromFile(arrFromFileDyn, size, filename); // Для обычного массива
        array_utils::printArray(arrFromFileDyn, size); // Для обычного массива
        product = array_utils::calculateProduct(arrFromFileDyn, size); // Для обычного массива
        cout << "Произведение элементов массива (обычный массив): " << product << endl;

        // Освобождение памяти
        delete[] arrDyn;
        delete[] arrFromFileDyn;
    }

    // Обработка исключений
    // В случае возникновения исключения в блоке try, управление передается сюда.
    // В объекте e содержится информация о произошедшей ошибке.
    // Метод e.what() возвращает описание ошибки в виде строки.
    // Сообщение об ошибке выводится в стандартный поток ошибок (cerr).
    catch (const exception& e) {
        cerr << "Произошла ошибка: " << e.what() << endl;
    }

    return 0;
}
