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
    setlocale(LC_ALL, "Russian"); //���������� ����������� ���������
    system("chcp 1251");


    int num = 0;
    std::cout << "������� �����: ";
    std::cin >> num;
    std::cout << std::endl << "����� ���������: \n";

    // ������� ����� ���������
    std::cout << fooFib(num) << std::endl;
}
