#include <iostream>

void quickSort(int* arr, int arrLeft, int arrRight)
{

    if (arrLeft >= arrRight)
    {
        return;
    }

    if ((arrRight - arrLeft) == 2)
    {
        if (arr[arrLeft] > arr[arrRight])
            std::swap(arr[arrLeft], arr[arrRight]);
        return;
    }


    int pivot = arr[(arrLeft + arrRight) / 2];

    int i = arrLeft;
    int j = arrRight;


    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        };

        quickSort(arr, arrLeft, j);
        quickSort(arr, i, arrRight);
    }
};

//Функция печати массива
void arrPrint(int* arr, const int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << "\t";
    };
    std::cout << std::endl;
};


int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    std::cout << "Массив до сортировки: \n";
    arrPrint(arr, std::size(arr));

    quickSort(arr, 0, (std::size(arr) - 1));

    std::cout << "Массив после сортировки: \n";
    arrPrint(arr, std::size(arr));
}