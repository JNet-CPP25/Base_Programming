#include <iostream>
#include <string>
#include <windows.h>


struct bankAccount
{
	int number{};
	std::string name{};
	float balans{};
};


bankAccount changeBalans(bankAccount& client, float newBalans);


int main()

{
	setlocale(LC_CTYPE, "rus");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bankAccount client;
	float newBalans{};

	std::cout << "¬ведите номер счета : ";
	std::cin >> client.number;
	std::cout << "¬ведите им€ владельца : ";

	//std::getline(client.number, );
	std::getline(std::cin >> std::ws, client.name);
	std::cout << "¬ведите баланс : ";
	std::cin >> client.balans;

	//std::cout << "¬аш счет : " << client.name << ", " << client.number << ", " << client.balans << std::endl;

	std::cout << "¬ведите новый баланс : ";
	std::cin >> newBalans;
	client = changeBalans(client, newBalans);

	std::cout << "¬аш счет: " << client.name << ", " << client.number << ", " << client.balans << std::endl;

}

bankAccount changeBalans(bankAccount& client, float newBalans)
{
	client.balans = newBalans;

	return client;
}