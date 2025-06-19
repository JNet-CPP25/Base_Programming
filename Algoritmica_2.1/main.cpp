#include <iostream>


int fooFib(int num)
{
    if (num <= 1)
    {
        return num;
    }
    return fooFib(num - 1) + fooFib(num - 2);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
    system("chcp 1251");


    int num = 0;
    std::cout << "Введите число: ";
    std::cin >> num;
    std::cout << std::endl << "Числа Фибоначчи: \n";

    // Выводим число Фибоначчи
    std::cout << fooFib(num) << std::endl;
}
