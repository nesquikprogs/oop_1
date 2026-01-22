#include "array_utils.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cassert>

using namespace std;

namespace array_utils {

    // Заполнение массива случайными числами для вектора
    // Аргументы:
    // arr Вектор, который будет заполнен случайными числами.
    // min Минимальное значение для случайных чисел.
    // max Максимальное значение для случайных чисел.
    void fillArray(std::vector<double>& arr, double min, double max) {
        for (size_t i = 0; i < arr.size(); ++i) {
            // Генерация случайного числа в диапазоне [min, max]
            arr[i] = min + (max - min) * (rand() / (RAND_MAX + 1.0));
        }
    }

    // Заполнение массива случайными числами для обычного массива
    // Аргументы:
    // arr Обычный массив, который будет заполнен случайными числами.
    // size Размер массива.
    // min Минимальное значение для случайных чисел.
    // max Максимальное значение для случайных чисел.
    void fillArray(double* arr, size_t size, double min, double max) {
        for (size_t i = 0; i < size; ++i) {
            // Генерация случайного числа в диапазоне [min, max]
            arr[i] = min + (max - min) * (rand() / (RAND_MAX + 1.0));
        }
    }

    // Вывод массива для вектора
    // Аргументы:
    // arr Вектор, элементы которого нужно вывести на экран.
    // Функция выводит все элементы вектора arr.
    // Каждый элемент выравнивается по ширине 8 символов и каждый 10-й элемент выводится с новой строки.
    void printArray(const std::vector<double>& arr) {
        for (size_t i = 0; i < arr.size(); ++i) {
            cout.width(8); // Выделяем место для выравнивания чисел
            cout << arr[i] << " ";
            if ((i + 1) % 10 == 0) {
                cout << endl; // Печатаем новую строку после каждых 10 элементов
            }
        }
        cout << endl;
    }

    // Вывод массива для обычного массива
    // Аргументы:
    // arr Обычный массив, элементы которого нужно вывести на экран.
    // size Размер массива.
    // Функция выводит все элементы обычного массива arr.
    // Каждый элемент выравнивается по ширине 8 символов, и каждый 10-й элемент выводится с новой строки.
    void printArray(const double* arr, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            cout.width(8); // Выделяем место для выравнивания чисел
            cout << arr[i] << " ";
            if ((i + 1) % 10 == 0) {
                cout << endl; // Печатаем новую строку после каждых 10 элементов
            }
        }
        cout << endl;
    }

    // Перемножение элементов массива для вектора
    // Аргументы:
    // arr Вектор, элементы которого нужно перемножить.
    // Возвращаемое значение:
    // Произведение всех элементов вектора.
    // Функция перемножает все элементы вектора arr и возвращает результат.
    double calculateProduct(const std::vector<double>& arr) {
        double product = 1.0;
        for (size_t i = 0; i < arr.size(); ++i) {
            product *= arr[i]; // Перемножаем все элементы массива
        }
        return product;
    }

    // Перемножение элементов массива для обычного массива
    // Аргументы:
    // arr Обычный массив, элементы которого нужно перемножить.
    // size Размер массива.
    // Возвращаемое значение:
    // Произведение всех элементов массива.
    // Функция перемножает все элементы обычного массива arr и возвращает результат.
    double calculateProduct(const double* arr, size_t size) {
        double product = 1.0;
        for (size_t i = 0; i < size; ++i) {
            product *= arr[i]; // Перемножаем все элементы массива
        }
        return product;
    }


    // red1: сделать отдельно try catch от throw
    // 
    // Запись в файл для вектора
    // Аргументы:
    // arr Вектор, элементы которого нужно записать в файл.
    // filename Имя файла для записи данных.
    // Функция записывает элементы вектора arr в файл с указанным именем filename.
    // Если не удается открыть файл, выбрасывается исключение.
    void writeArrayToFile(const std::vector<double>& arr, const std::string& filename) {
        ofstream outFile(filename);
        if (!outFile) { // Если не удалось открыть файл
            throw runtime_error("Не удалось открыть файл для записи!");
        }

        for (size_t i = 0; i < arr.size(); ++i) {
            outFile << arr[i] << endl; // Записываем элементы в файл
        }
        outFile.close(); // Закрываем файл
        cout << "Массив успешно записан в файл " << filename << endl;
    }

    // red1: сделать отдельно try catch от throw
    // 
    // Запись в файл для обычного массива
    // Аргументы:
    // arr Обычный массив, элементы которого нужно записать в файл.
    // size Размер массива.
    // filename Имя файла для записи данных.
    // Функция записывает элементы массива arr в файл с указанным именем filename.
    // Если не удается открыть файл, выбрасывается исключение.
    void writeArrayToFile(const double* arr, size_t size, const std::string& filename) {
        ofstream outFile(filename);
        if (!outFile) { // Если не удалось открыть файл
            throw runtime_error("Не удалось открыть файл для записи!");
        }

        for (size_t i = 0; i < size; ++i) {
            outFile << arr[i] << endl; // Записываем элементы в файл
        }
        outFile.close(); // Закрываем файл
        cout << "Массив успешно записан в файл " << filename << endl;
    }

    // red1: сделать отдельно try catch от throw
    // 
    // Чтение из файла для вектора
    // Аргументы:
    // arr Вектор, в который будут загружены данные из файла.
    // filename Имя файла для чтения данных.
    // Функция читает данные из файла filename и загружает их в вектор arr.
    // Если файл не удается открыть, выбрасывается исключение.
    void readArrayFromFile(std::vector<double>& arr, const std::string& filename) {
        ifstream inFile(filename);
        if (!inFile) { // Если не удалось открыть файл
            throw runtime_error("Не удалось открыть файл для чтения!");
        }

        size_t index = 0;
        while (inFile >> arr[index]) { // Чтение данных в вектор
            ++index;
        }
        inFile.close(); // Закрываем файл
        cout << "Массив успешно загружен из файла " << filename << endl;
    }

    // red1: сделать отдельно try catch от throw
    // 
    // Чтение из файла для обычного массива
    // Аргументы:
    // arr Обычный массив, в который будут загружены данные из файла.
    // size Размер массива.
    // filename Имя файла для чтения данных.
    // Функция читает данные из файла filename и загружает их в обычный массив arr.
    // Если файл не удается открыть, выбрасывается исключение.
    void readArrayFromFile(double* arr, size_t size, const std::string& filename) {
        ifstream inFile(filename);
        if (!inFile) { // Если не удалось открыть файл
            throw runtime_error("Не удалось открыть файл для чтения!"); 
        }

        size_t index = 0;
        while (inFile >> arr[index] && index < size) { // Чтение данных в обычный массив
            ++index;
        }
        inFile.close(); // Закрываем файл
        cout << "Массив успешно загружен из файла " << filename << endl
    }

    // Тестирование функции перемножения элементов массива с использованием assert
    // Функция выполняет несколько тестов, проверяя, что функция calculateProduct работает корректно.
    // Если хотя бы один тест не проходит, выбрасывается исключение.
    void testCalculateProduct() {
        assert(calculateProduct(std::vector<double>{2.0, 3.0, 4.0}) == 24.0);
        assert(calculateProduct(std::vector<double>{0.0, 3.0, 5.0}) == 0.0);
        assert(calculateProduct(std::vector<double>{5.0}) == 5.0);
        assert(calculateProduct(std::vector<double>{-2.0, 3.0, -4.0}) == 24.0);
        assert(calculateProduct(std::vector<double>{0.0}) == 0.0);
        assert(calculateProduct(std::vector<double>{-1.0, -2.0, -3.0}) == -6.0);
        cout << "Все тесты прошли успешно!" << endl;
    }

}
