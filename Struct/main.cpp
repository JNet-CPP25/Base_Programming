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

	std::cout << "������� ����� ����� : ";
	std::cin >> client.number;
	std::cout << "������� ��� ��������� : ";

	//std::getline(client.number, );
	std::getline(std::cin >> std::ws, client.name);
	std::cout << "������� ������ : ";
	std::cin >> client.balans;

	//std::cout << "��� ���� : " << client.name << ", " << client.number << ", " << client.balans << std::endl;

	std::cout << "������� ����� ������ : ";
	std::cin >> newBalans;
	client = changeBalans(client, newBalans);

	std::cout << "��� ����: " << client.name << ", " << client.number << ", " << client.balans << std::endl;

}

bankAccount changeBalans(bankAccount& client, float newBalans)
{
	client.balans = newBalans;

	return client;
}