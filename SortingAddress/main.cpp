﻿#include <iostream>
#include <cstring>
#include <fstream>
#include <string>


class Adress //Класс Адрес с методами
{
private:
    std::string NameCity;
    std::string NameStreet;
    int NumberHouse = 0;
    int NumberApartment = 0;
    std::string FullAdress;

public:
    // Конструктор
    Adress(std::string NameCity, std::string NameStreet, int NumberHouse, int NumberApartment)
    {
        this->NameCity = NameCity;
        this->NameStreet = NameStreet;
        this->NumberHouse = NumberHouse;
        this->NumberApartment = NumberApartment;
    }

    // Метод создания строки полного адреса для вывода
    std::string createAdress2Out()
    {
        FullAdress = NameCity + ", " + NameStreet + ", " + std::to_string(NumberHouse)
            + ", " + std::to_string(NumberApartment);
        return FullAdress;
    };
};

enum class codeCommit
{
    fileInOpenError, fileOutOpenError
};

//Функция печати массива в файл
int printArrayForClassObjects(std::string* arrayForClassObjects, const int quantityAdresses)
{
    std::ofstream fileOut("out.txt", std::ios_base::trunc);

    if (fileOut.is_open())
    {
        std::cout << "Файл out.txt успешно открыт." << std::endl;
    }
    else
    {
        std::cout << "Ошибка открытия файла" << std::endl;
        return static_cast<int>(codeCommit::fileOutOpenError);
    }

    fileOut << quantityAdresses << std::endl << std::endl;

     for (int i = 0; i < quantityAdresses - 1; i++)
    {
        fileOut << i + 1 << ". " << arrayForClassObjects[i] << std::endl;
    }
    fileOut.close();
};

//Функция сортировки пузырьком
void addressSort(std::string* arrayForClassObjects, const int quantityAdresses)
{
    bool swapped = false;
    do {
        swapped = false;
        std::string tmp;

        for (int i = quantityAdresses - 1; i > 0; --i)
        {
            if (arrayForClassObjects[i - 1] > arrayForClassObjects[i])
            {
                tmp = arrayForClassObjects[i];
                arrayForClassObjects[i] = arrayForClassObjects[i - 1];
                arrayForClassObjects[i - 1] = tmp;
                swapped = true;
            }
        }
    } while (swapped);
}

//Функция создания текстового динамического массива
std::string* createTextArr(const int quantityAdresses)
{
    std::string* TextArr = new std::string[quantityAdresses]{};

    return TextArr;
}

//Функция удаления динамического массива
void deleteTextArr(std::string* TextArr, const int quantityAdresses)
{
    delete[] TextArr;
    TextArr = nullptr;
}

int main()
{
    setlocale(LC_ALL, "Russian"); 

    std::ifstream fileIn("in.txt"); // Открываем файл и проверяем удалось ли открыть
    if (!fileIn)
    {
        std::cout << "Ошибка открытия файла in.txt." << std::endl;
        return static_cast<int>(codeCommit::fileInOpenError);
    }
    else
    {
        std::cout << "Файл in.txt успешно открыт." << std::endl;
    }

    int quantityAdresses = 0;
    std::string NameCity = {};
    std::string NameStreet = {};
    int NumberHouse = 0;
    int NumberApartment = 0;

    fileIn >> quantityAdresses; //Считываем кол-во адресов из файла(объектов класса) 

    std::string* arrayForClassObjects = createTextArr(quantityAdresses); //Cоздаем динамический массив для объектов класса Adress

    for (int i = 0; i < quantityAdresses; i++) //Считываем адрес
    {
        fileIn >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
        Adress adress(NameCity, NameStreet, NumberHouse, NumberApartment);
        arrayForClassObjects[i] = adress.createAdress2Out();

    };
    fileIn.close(); //Закрываем файл in.txt

    addressSort(arrayForClassObjects, quantityAdresses); //Сортируем адреса
    printArrayForClassObjects(arrayForClassObjects, quantityAdresses); //Печатаем адреса в файл
    deleteTextArr(arrayForClassObjects, quantityAdresses); //Удаляем массив

    std::cout << "Результат работы программы смотри в файле out.txt" << std::endl;
}