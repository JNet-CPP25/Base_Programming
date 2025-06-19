#include <iostream>
#include "print.h"
#include "journeyThroughThePyramid.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(nullptr)); // Начальное значение для генератора случайных чисел

    int arrSize = 5 + rand() % 21;

    //int arr[] = { 1, 3, 6, 5, 9, 8 };

    //int arr[] = {94, 67, 18, 44, 55, 12, 6, 42};
    //int arr[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    //int arrSize = std::size(arr);


    //Создаем массив
    int* arr = new int[arrSize] {};

    // Заполняем массив рандомными числами
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = rand() % 55;
    };

    PrintArray(arr, arrSize);

    int countLevelsOfPyramid = log2(arrSize) + 1;
    int* levelOfpyramid = new int[countLevelsOfPyramid];

    PrintPyramid(arr, arrSize, levelOfpyramid, countLevelsOfPyramid);

    journeyThroughThePyramid(arr, arrSize, levelOfpyramid, countLevelsOfPyramid);


    delete[] levelOfpyramid;  // Удаляем массив
    levelOfpyramid = nullptr;

    delete[] arr;  // Удаляем массив
    arr = nullptr;
}