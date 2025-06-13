#include <iostream>
#include "MathFunction.h"



int main()
{
    setlocale(LC_ALL, "Russian");

    double firstNumber = 0;
    double secondNumber = 0;
    int operationSelection = 0;
    std::string nameOfOperation;
    bool checkingValue = false;

    std::cout << "¬ведите первое число: ";
    std::cin >> firstNumber;

    std::cout << "¬ведите второе число: ";
    std::cin >> secondNumber;

    do
    {
        std::cout << "¬ыберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
        std::cin >> operationSelection;

        if (operationSelection == 4 && secondNumber == 0)
        {
            std::cout << " ƒелить на ноль нельз€... " << std::endl;
        }
        else if (operationSelection <= 5 && operationSelection >= 1)
        {
            checkingValue = true;
        }
        else
        {
            std::cout << " ѕлохой выбор. ¬ыберете еще разок... " << std::endl;
        }
    } while (!checkingValue);

    switch (operationSelection)
    {
    case(1):
    {
        nameOfOperation = "плюс";
        break;
    }
    case(2):
    {
        nameOfOperation = "минус";
        break;
    }
    case(3):
    {
        nameOfOperation = "умножить";
        break;
    }
    case(4):
    {
        nameOfOperation = "разделить";
        break;
    }
    case(5):
    {
        nameOfOperation = "в степени";
        break;
    }
    };

    std::cout << firstNumber << " " << nameOfOperation << " " << secondNumber << " = ";

    if (operationSelection == 1)
    {
        std::cout << addition(firstNumber, secondNumber);
    }
    else if (operationSelection == 2)
    {
        std::cout << subtraction(firstNumber, secondNumber);
    }
    else if (operationSelection == 3)
    {
        std::cout << multiplication(firstNumber, secondNumber);
    }
    else if (operationSelection == 4)
    {
        std::cout << division(firstNumber, secondNumber);
    }
    else
    {
        std::cout << exponentiation(firstNumber, secondNumber);
    };
};

