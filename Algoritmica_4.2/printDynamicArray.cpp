#include "printDynamicArray.h"


void PrintDynamicArray(int* arr, int arrActualSize, int arrLogicalSize, bool stoppingActions)
{
    if (!stoppingActions)
    {
        std::cout << "Äèíàìè÷åñêèé ìàññèâ: ";
    }
    else
    {
        std::cout << "Ñïàñèáî! Âàø ìàññèâ: ";
    };

    for (int i = 0; i < arrLogicalSize; i++)
    {
        std::cout << " ";
        std::cout << arr[i];
    };

    for (int i = arrLogicalSize; i < arrActualSize; i++)
    {
        std::cout << " ";
        std::cout << "_";
    };

    std::cout << std::endl;
};