#include <iostream>

//Калькулятор
class Calculator
{
private:
    double num1 = 1;
    double num2 = 1;

public:
    double add()
    {
        return num1 + num2;
    };

    double multiply()
    {
        return num1 * num2;
    };

    double subtract_1_2()
    {
        return num1 - num2;
    };

    double subtract_2_1()
    {
        return num2 - num1;
    };

    double divide_1_2()
    {
        return num1 / num2;
    };

    double divide_2_1()
    {
        return num2 / num1;
    };

    bool set_num1(double num1)
    {
        if (num1 != 0)
        {
            this->num1 = num1;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool set_num2(double num2)
    {
        if (num2 != 0)
        {
            this->num2 = num2;
            return true;
        }
        else
        {
            return false;
        }
    }
};

//Печать
void printResult(double result)
{
    std::cout << result << std::endl;
}

int main()
{
    setlocale(LC_CTYPE, "rus"); //локализация

    double num1 = 0;
    double num2 = 0;

    Calculator result; // создаем экземпляр класса 

    while (true) 
    {
        
        do //Проверка num1 на ноль
        {
            std::cout << "Введите num1: ";
            std::cin >> num1;
            if (!result.set_num1(num1))
            {
                std::cout << "Неверный ввод! " << std::endl;
            };
        } while (!result.set_num1(num1));

        do //Проверка num2 на ноль
        {
            std::cout << "Введите num2: ";
            std::cin >> num2;
            if (!result.set_num2(num2))
            {
                std::cout << "Неверный ввод! " << std::endl;
            };
        } while (!result.set_num2(num2));

        result.add(); //Сложение
        std::cout << std::endl << "num1 + num2 = "; 
        printResult(result.add()); 

        result.multiply();  //Умножение
        std::cout << "num1 * num2 = ";
        printResult(result.multiply());

        result.subtract_1_2();  //Разность 
        std::cout << "num1 - num2 = ";
        printResult(result.subtract_1_2());

        result.subtract_2_1();  //Разность
        std::cout << "num2 - num1 = ";
        printResult(result.subtract_2_1());

        result.divide_1_2(); //Деление
        std::cout << "num1 / num2 = ";
        printResult(result.divide_1_2());

        result.divide_2_1(); //Деление
        std::cout << "num2 / num1 = ";
        printResult(result.divide_2_1());
    }
}