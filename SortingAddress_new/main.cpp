#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Address //Класс Адрес с методами
{
private:
    string NameCity;
    string NameStreet;
    int NumberHouse = 0;
    int NumberApartment = 0;

public:
    // Конструкторы
    Address() {}

    Address(string NameCity, string NameStreet, int NumberHouse, int NumberApartment)
    {
        fillAddress(NameCity, NameStreet, NumberHouse, NumberApartment);
    }

    // Метод получения полного адреса
    string getFullAddress()
    {
        return NameCity + ", " + NameStreet + ", " + to_string(NumberHouse) + ", " + to_string(NumberApartment);
    }

    // Метод получения города
    string getCity()
    {
        return NameCity;
    }

    // Метод заполнения полей объекта класса
    void fillAddress(string NameCity, string NameStreet, int NumberHouse, int NumberApartment)
    {
        this->NameCity = NameCity;
        this->NameStreet = NameStreet;
        this->NumberHouse = NumberHouse;
        this->NumberApartment = NumberApartment;
    }
};

enum class codeCommit
{
    fileInOpenError, fileOutOpenError
};

//Функция печати массива в файл
int printArrayForClassObjects(Address* objects, const int count)
{
    ofstream fileOut("out.txt", ios_base::trunc);

    if (fileOut.is_open())
    {
        cout << "Файл out.txt успешно открыт." << endl;
    }
    else
    {
        cout << "Ошибка открытия файла out.txt" << endl;
        return static_cast<int>(codeCommit::fileOutOpenError);
    }

    fileOut << "Всего количество адресов: " << count << endl << endl;

    fileOut << "Адреса:" << endl;

    for (int i = 0; i < count; i++)
    {
        fileOut << i + 1 << ". " << objects[i].getFullAddress() << endl;
    }

    fileOut.close();
    return 0;
};

// Функция сравнения для сортировки
bool compareObjects(Address& a, Address& b) {
    return a.getCity() < b.getCity(); // по возрастанию. Если надо по убыванию: a.getCity() > b.getCity();
}

//Функция сортировки
void addressSort(Address* objects, const int count)
{
    sort(objects, objects + count, compareObjects);
};

int main() {
    setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы

    ifstream fileIn("in.txt"); // Открываем файл и проверяем удалось ли открыть
    if (!fileIn)
    {
        cout << "Ошибка открытия файла in.txt." << endl;
        return static_cast<int>(codeCommit::fileInOpenError);
    }
    else
    {
        cout << "Файл in.txt успешно открыт." << endl;
    }

    int quantityAddresses = 0;
    string NameCity = {};
    string NameStreet = {};
    int NumberHouse = 0;
    int NumberApartment = 0;

    fileIn >> quantityAddresses; //Считываем кол-во адресов из файла(объектов класса) 

    Address* arr = new Address[quantityAddresses]; // Создаем динамический массив 

    for (int i = 0; i < quantityAddresses; i++) //Заполняем массив адресов
    {
        fileIn >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
        arr[i].fillAddress(NameCity, NameStreet, NumberHouse, NumberApartment);
    };

    fileIn.close(); //Закрываем файл in.txt

    addressSort(arr, quantityAddresses);
    printArrayForClassObjects(arr, quantityAddresses);

    delete[] arr;
}