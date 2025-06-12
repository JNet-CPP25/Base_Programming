#include <iostream>
#include <string>
#include <windows.h>


struct BankAccount
{
	int number{};
	std::string name{};
	float balans{};
};


BankAccount changeBalans(BankAccount& client, float newBalans);


int main()

{
	setlocale(LC_CTYPE, "rus");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BankAccount client;
	float newBalans{};

	std::cout << "Введите номер счета : ";
	std::cin >> client.number;
	std::cout << "Введите имя владельца : ";


	std::getline(std::cin >> std::ws, client.name);
	std::cout << "Введите баланс : ";
	std::cin >> client.balans;

	//std::cout << "Ваш счет : " << client.name << ", " << client.number << ", " << client.balans << std::endl;

	std::cout << "Введите новый баланс : ";
	std::cin >> newBalans;
	client = changeBalans(client, newBalans);

	std::cout << "Ваш счет: " << client.name << ", " << client.number << ", " << client.balans << std::endl;

}

BankAccount changeBalans(BankAccount& client, float newBalans)
{
	client.balans = newBalans;

	return client;
}