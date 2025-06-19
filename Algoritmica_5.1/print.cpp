#include "print.h"

void PrintArray(int* arr, const int arrSize)
{
    std::cout << "Исходный массив:";

    for (int i = 0; i < arrSize; i++)
    {
        std::cout << " ";
        std::cout << arr[i];
    };
    std::cout << std::endl;
};

int PyramidLevelNow(int* levelOfpyramid, const int countLevelsOfPyramid, int i)
{
    for (int j = 0; j < countLevelsOfPyramid; j++)
    {
        if (i < levelOfpyramid[j])
        {
            return j + 1;
        }
    };
    return 1;
};

void PrintPyramid(int* arr, const int arrSize)
{
    //int pyramidLevelNow = 0;

    std::cout << "Пирамида:\n";
    std::cout << "Уровень: 0. Root. Значение: " << arr[0] << std::endl;

    int countLevelsOfPyramid = log2(arrSize) + 1;
    int* levelOfpyramid = new int[countLevelsOfPyramid];

   
    for (int i = 0; i < countLevelsOfPyramid; i++)
    {
        levelOfpyramid[i] = pow(2, i);
    }

    for (int i = 0; i < arrSize; i++)
    {
        int indexLeft = 2 * i + 1;
        if (indexLeft < arrSize)
        {
            std::cout << "Уровень: " << PyramidLevelNow(levelOfpyramid, countLevelsOfPyramid, i) << ". Left(" << arr[i] << ")" << ". Значение: " << arr[2 * i + 1] << std::endl;
        }

        int indexRight = 2 * i + 2;
        if (indexRight < arrSize)
        {
            std::cout << "Уровень: " << PyramidLevelNow(levelOfpyramid, countLevelsOfPyramid, i) << ". Right(" << arr[i] << ")" << ". Значение: " << arr[2 * i + 2] << std::endl;
        }
    }
    std::cout << std::endl;

    delete[] levelOfpyramid;
    levelOfpyramid = nullptr;
};