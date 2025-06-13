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

    std::cout << "������� ������ �����: ";
    std::cin >> firstNumber;

    std::cout << "������� ������ �����: ";
    std::cin >> secondNumber;

    do
    {
        std::cout << "�������� �������� (1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
        std::cin >> operationSelection;

        if (operationSelection == 4 && secondNumber == 0)
        {
            std::cout << " ������ �� ���� ������... " << std::endl;
        }
        else if (operationSelection <= 5 && operationSelection >= 1)
        {
            checkingValue = true;
        }
        else
        {
            std::cout << " ������ �����. �������� ��� �����... " << std::endl;
        }
    } while (!checkingValue);

    switch (operationSelection)
    {
    case(1):
    {
        nameOfOperation = "����";
        break;
    }
    case(2):
    {
        nameOfOperation = "�����";
        break;
    }
    case(3):
    {
        nameOfOperation = "��������";
        break;
    }
    case(4):
    {
        nameOfOperation = "���������";
        break;
    }
    case(5):
    {
        nameOfOperation = "� �������";
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

