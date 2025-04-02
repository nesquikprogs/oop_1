#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <vector>
#include <string>

namespace array_utils {

    
    //  Заполняет вектор случайными числами в диапазоне от min до max.
    //  Аргументы: 
    //  arr - Вектор, который будет заполнен случайными числами.
    //  min Минимальное значение для случайных чисел.
    //  Максимальное значение для случайных чисел.
    void fillArray(std::vector<double>& arr, double min, double max);


    // Заполняет обычный массив случайными числами в диапазоне от min до max.
    // Аргументы:
    // arr Обычный массив, который будет заполнен случайными числами.
    // size Размер массива.
    // min Минимальное значение для случайных чисел.
    // max Максимальное значение для случайных чисел.
    void fillArray(double* arr, size_t size, double min, double max);


    //  Выводит элементы вектора на экран.
    //  Аргументы:
    //  arr Вектор, элементы которого будут выведены.
    void printArray(const std::vector<double>& arr);

    
    //  Выводит элементы обычного массива на экран.
    //  Аргументы:
    //  arr Обычный массив, элементы которого будут выведены.
    //  size Размер массива.
    void printArray(const double* arr, size_t size);


    // Вычисляет произведение элементов вектора.
    // Аргументы:
    // arr Вектор, элементы которого нужно перемножить.
    // Возвращает произведение элементов вектора.
    double calculateProduct(const std::vector<double>& arr);


    // Вычисляет произведение элементов обычного массива.
    // Аргументы:
    // arr Обычный массив, элементы которого нужно перемножить.
    // size Размер массива.
    // Возвращает произведение элементов массива.
    double calculateProduct(const double* arr, size_t size);


    // Записывает элементы вектора в файл.
    // Аргументы:
    // arr Вектор, элементы которого нужно записать в файл.
    // filename Имя файла, в который будут записаны данные.
    void writeArrayToFile(const std::vector<double>& arr, const std::string& filename);


    // Записывает элементы обычного массива в файл.
    // Аргументы:
    // arr Обычный массив, элементы которого нужно записать в файл.
    // size Размер массива.
    // filename Имя файла, в который будут записаны данные.
    void writeArrayToFile(const double* arr, size_t size, const std::string& filename);


    // Читает элементы вектора из файла.
    // Аргументы:
    // arr Вектор, в который будут загружены данные из файла.
    // filename Имя файла, из которого будут загружены данные.
    void readArrayFromFile(std::vector<double>& arr, const std::string& filename);


    // Читает элементы обычного массива из файла.
    // Аргументы:
    // arr Обычный массив, в который будут загружены данные из файла.
    // size Размер массива.
    // filename Имя файла, из которого будут загружены данные.
    void readArrayFromFile(double* arr, size_t size, const std::string& filename);

    
    // Тестирует правильность вычисления произведения элементов массива с помощью ассертов.
    void testCalculateProduct();

}

#endif
