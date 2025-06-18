#include <iostream>
#include <windows.h>

class Counter //Создаем класс "Счетчик"
{
private:
    int counterResult = 0;

public:
    Counter() {};
    Counter(int initialValue) {
        this->counterResult = initialValue;
    };

    int getCounter() {
        return this->counterResult;
    };
    int counterPlus() {
        return ++counterResult;
    };
    int counterMinus() {
        return --counterResult;
    };
};

int main()
{
    setlocale(LC_ALL, "Russian"); //Руссификация
    SetConsoleCP(1251);

    std::string checkInitialInitValue;
    int initialInitValue = 0;
    bool checkTrueInitialInitValue = false;
    Counter* counter = nullptr;

    //Проверяем начальное значение счет
    do
    {
        std::cout << std::endl << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> checkInitialInitValue;
        std::cout << std::endl;

        if (checkInitialInitValue == "да" || checkInitialInitValue == "Да")
        {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> initialInitValue;

            counter = new Counter(initialInitValue);
            checkTrueInitialInitValue = true;
        }
        else if (checkInitialInitValue == "нет" || checkInitialInitValue == "Нет")
        {
            counter = new Counter();
            checkTrueInitialInitValue = true;
        }
        else
        {
            std::cout << "Вы ввели неверную команду.";
        }
    } while (!checkTrueInitialInitValue);

    //Counter Counter(initialInitValue);

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
            counter->counterPlus();
        }
        else if (commandValue == "-")
        {
            counter->counterMinus();
        }
        else if (commandValue == "=")
        {
            std::cout << "Значение счетчика: " << counter->getCounter() << "." << std::endl;
        }
        else
        {
            std::cout << "Вы ввели неверную команду." << std::endl;
        }
    } while (!checkCommand);

    delete counter;
}