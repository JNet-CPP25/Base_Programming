#include <iostream>

//�����������
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

//������
void printResult(double result)
{
    std::cout << result << std::endl;
}

int main()
{
    setlocale(LC_CTYPE, "rus"); //�����������

    double num1 = 0;
    double num2 = 0;

    Calculator result; // ������� ��������� ������ 

    while (true) 
    {
        
        do //�������� num1 �� ����
        {
            std::cout << "������� num1: ";
            std::cin >> num1;
            if (!result.set_num1(num1))
            {
                std::cout << "�������� ����! " << std::endl;
            };
        } while (!result.set_num1(num1));

        do //�������� num2 �� ����
        {
            std::cout << "������� num2: ";
            std::cin >> num2;
            if (!result.set_num2(num2))
            {
                std::cout << "�������� ����! " << std::endl;
            };
        } while (!result.set_num2(num2));

        result.add(); //��������
        std::cout << std::endl << "num1 + num2 = "; 
        printResult(result.add()); 

        result.multiply();  //���������
        std::cout << "num1 * num2 = ";
        printResult(result.multiply());

        result.subtract_1_2();  //�������� 
        std::cout << "num1 - num2 = ";
        printResult(result.subtract_1_2());

        result.subtract_2_1();  //��������
        std::cout << "num2 - num1 = ";
        printResult(result.subtract_2_1());

        result.divide_1_2(); //�������
        std::cout << "num1 / num2 = ";
        printResult(result.divide_1_2());

        result.divide_2_1(); //�������
        std::cout << "num2 / num1 = ";
        printResult(result.divide_2_1());
    }
}