// Измените программы из первого и второго задания с помощью шаблонов


#include <iostream>
#include <windows.h>
#include <random>
using namespace std;

// Заполнение одномерного массива случайными значениями
template <typename T>
void FillArray(T arr[], int size);

// Перегруженный метод заполнения двумерного массива
template <typename T, int rows, int cols>
void FillArray(T arr[][cols]);

// Вывод массива на экран
template <typename T>
void PrintArray(T arr[], int size);

// Перегруженный метод печати двумерного массива
template <typename T, int rows, int cols>
void PrintArray(T arr[][cols]);

// Нахождение максимального значения в массиве
template <typename T>
T FindMax(T arr[], int size);

// Нахождение максимального в двумерном массиве
template <typename T, int rows, int cols>
T FindMax(T arr[][cols]);

// Нахождение максимального значения из двух целых
template <typename T>
T FindMaxDigit(T a, T b);

// Нахождение максимального значения из трёх целых
template <typename T>
T FindMaxDigit(T a, T b, T c);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 20;
    const int rows = 20;
    const int cols = 20;
    int A = 0, B = 0, C = 0;
    int IntArray[size];
    int IntTwoDimensionalArray[rows][cols];

    char CharArray[size];
    char CharTwoDimensionalArray[rows][cols];

    double DoubleArray[size];
    double DoubleTwoDimensionalArray[rows][cols];

    // Заполнение и вывод одномерных массивов типа int
    FillArray(IntArray, size);
    cout << "Заполненный одномерный массив (int) : " << endl;
    PrintArray(IntArray, size);
    cout << "Максимальное значение в массиве : " << FindMax(IntArray, size) << endl;

    // Заполнение и вывод двумерных массивов типа int
    cout << "Заполненный двумерный массив (int) : " << endl;
    FillArray<int, rows, cols>(IntTwoDimensionalArray);
    PrintArray<int, rows, cols>(IntTwoDimensionalArray);
    cout << "Максимальное значение в двумерном в массиве : " << FindMax<int, rows, cols>(IntTwoDimensionalArray) << endl;

    cout << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    // Заполнение и вывод одномерных массивов типа char
    FillArray(CharArray, size);
    cout << "Заполненный одномерный массив (char) : " << endl;
    PrintArray(CharArray, size);
    cout << "Максимальное значение в массиве : " << FindMax(CharArray, size) << endl;

    // Заполнение и вывод двумерных массивов типа char
    cout << "Заполненный двумерный массив (char) : " << endl;
    FillArray<char, rows, cols>(CharTwoDimensionalArray);
    PrintArray<char, rows, cols>(CharTwoDimensionalArray);
    cout << "Максимальное значение в двумерном в массиве : " << FindMax<char, rows, cols>(CharTwoDimensionalArray) << endl;

    cout << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    // Заполнение и вывод одномерных массивов типа double
    FillArray(DoubleArray, size);
    cout << "Заполненный одномерный массив (double) : " << endl;
    PrintArray(DoubleArray, size);
    cout << "Максимальное значение в массиве : " << FindMax(DoubleArray, size) << endl;

    // Заполнение и вывод двумерных массивов типа double
    cout << "Заполненный двумерный массив (double) : " << endl;
    FillArray<double, rows, cols>(DoubleTwoDimensionalArray);
    PrintArray<double, rows, cols>(DoubleTwoDimensionalArray);
    cout << "Максимальное значение в двумерном в массиве : " << FindMax<double, rows, cols>(DoubleTwoDimensionalArray) << endl;
;
}

template <typename T>
void FillArray(T arr[], int size) {
    random_device random;
    for (size_t i = 0; i < size; i++) {
        arr[i] = random() % (100 + 50) - 50;
    }
}

template <typename T, int rows, int cols>
void FillArray(T arr[][cols]) {
    random_device random;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = random() % (100 + 50) - 50;
        }
    }
}

template <typename T>
void PrintArray(T arr[], int size) {
    for (size_t i = 0; i < size; i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}

template <typename T, int rows, int cols>
void PrintArray(T arr[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "[" << arr[i][j] << "] ";
        }
        cout << std::endl;
    }
}

template <typename T>
T FindMax(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

template <typename T, int rows, int cols>
T FindMax(T arr[][cols]) {
    T maxVal = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}

template <typename T>
T FindMaxDigit(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T FindMaxDigit(T a, T b, T c) {
    return FindMaxDigit(FindMaxDigit(a, b), c);
}
