#include <iostream>
#include <string>

struct PostAddress
{
	std::string city{};
	std::string street{};
	std::string numberHouse{};
	int numberApartment{};
	int index{};
};

void printAddress(PostAddress& address);

int main()
{
	setlocale(LC_CTYPE, "rus");

	PostAddress addressOne{ "����� �������", "��������� ������", "25/1", 30, 170000 };
	PostAddress addressTwo{ "������", "�����", "12", 8, 123456 };
	PostAddress addressThree{ "������", "�������", "59", 143, 953769 };

	printAddress(addressOne);
	printAddress(addressTwo);
	printAddress(addressThree);

}

void printAddress(PostAddress& address)
{
	std::cout << "�����: " << address.city << std::endl;
	std::cout << "�����: " << address.street << std::endl;
	std::cout << "����� ����: " << address.numberHouse << std::endl;
	std::cout << "����� ��������: " << address.numberApartment << std::endl;
	std::cout << "������: " << address.index << std::endl;
	std::cout << std::endl;
}