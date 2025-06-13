#include <iostream>
#include <windows.h>
#include "Class.h"




int main()
{
    setlocale(LC_ALL, "Russian"); //Руссификация
    SetConsoleCP(1251);

    std::string checkInitialInitValue;
    int initialInitValue = 0;
    bool checkTrueInitialInitValue = false;

    //Проверяем начальное значение счетчика
    do
    {
        std::cout << std::endl << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> checkInitialInitValue;
        std::cout << std::endl;

        if (checkInitialInitValue == "да" || checkInitialInitValue == "Да")
        {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> initialInitValue;
            checkTrueInitialInitValue = true;
        }
        else if (checkInitialInitValue == "нет" || checkInitialInitValue == "Нет")
        {
            checkTrueInitialInitValue = true;
        }
        else
        {
            std::cout << "Вы ввели неверную команду.";
        }
    } while (!checkTrueInitialInitValue);

    Counter Counter(initialInitValue);

    std::cout << std::endl;

    std::string commandValue;
    bool checkCommand = false;

    //Сам счётчик
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> commandValue;

        if (commandValue == "x")
        {
            std::cout << "Пока.";
            checkCommand = true;
        }
        else if (commandValue == "+")
        {
            Counter.counterPlus();
        }
        else if (commandValue == "-")
        {
            Counter.counterMinus();
        }
        else if (commandValue == "=")
        {
            std::cout << "Значение счетчика: " << Counter.getCounter() << "." << std::endl;
        }
        else
        {
            std::cout << "Вы ввели неверную команду." << std::endl;
        }
    } while (!checkCommand);
}