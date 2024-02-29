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
    int Array[size];
    int TwoDimensionalArray[rows][cols];

    // Заполнение и вывод одномерного массива
    FillArray(Array, size);
    cout << "Заполненный одномерный массив : " << endl;
    PrintArray(Array, size);
    cout << "Максимальное значение в массиве : " << FindMax(Array, size) << endl;

    // Заполнение и вывод двумерного массива
    cout << "Заполненный двумерный массив : " << endl;
    FillArray<int, rows, cols>(TwoDimensionalArray);
    PrintArray<int, rows, cols>(TwoDimensionalArray);
    cout << "Максимальное значение в двумерном в массиве : " << FindMax<int, rows, cols>(TwoDimensionalArray) << endl;

    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    // Нахождение максимального значения из двух целых
    cout << "Для нахождения максимального из двух целых введите A и B :";
    cin >> A >> B;
    cout << endl;
    cout << "Максимально значение : " << FindMaxDigit<int>(A, B) << endl;

    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    // Нахождение максимального значения из трёх целых
    cout << "Для нахождения максимального из трёх целых введите A и B и С:";
    cin >> A >> B >> C;
    cout << "Максимально значение : " << FindMaxDigit<int>(A, B, C) << endl;
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
