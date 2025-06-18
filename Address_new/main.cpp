#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

//using namespace std;

class Address //Класс Адрес с методами
{
private:
	std::string NameCity;
	std::string NameStreet;
	int NumberHouse = 0;
	int NumberApartment = 0;

public:
	// Конструкторы
	Address() {}

	Address(std::string NameCity, std::string NameStreet, int NumberHouse, int NumberApartment)
	{
		fillAddress(NameCity, NameStreet, NumberHouse, NumberApartment);
	}

	// Метод получения полного адреса
	std::string getFullAddress()
	{
		return NameCity + ", " + NameStreet + ", " + std::to_string(NumberHouse) + ", " + std::to_string(NumberApartment);
	}

	// Метод заполнения полей объекта класса
	void fillAddress(std::string NameCity, std::string NameStreet, int NumberHouse, int NumberApartment)
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
	std::ofstream fileOut("out.txt", std::ios_base::trunc);

	if (fileOut.is_open())
	{
		std::cout << "Файл out.txt успешно открыт." << std::endl;
	}
	else
	{
		std::cout << "Ошибка открытия файла out.txt" << std::endl;
		return static_cast<int>(codeCommit::fileOutOpenError);
	}

	fileOut << "Всего количество адресов: " << count << std::endl << std::endl;

	fileOut << "Адреса:" << std::endl;

	for (int i = 0; i < count; i++)
	{
		fileOut << i + 1 << ". " << objects[i].getFullAddress() << std::endl;
	}

	fileOut.close();
	return 0;
};

int main() {
	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы

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

	int quantityAddresses = 0;
	std::string NameCity = {};
	std::string NameStreet = {};
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

	printArrayForClassObjects(arr, quantityAddresses);

	std::cout << "Результат работы программы смотри в файле out.txt" << std::endl;

	delete[] arr;
}