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

	PostAddress addressOne{ "Новый Уренгой", "Буровиков проезд", "25/1", 30, 170000 };
	PostAddress addressTwo{ "Москва", "Арбат", "12", 8, 123456 };
	PostAddress addressThree{ "Ижевск", "Пушкина", "59", 143, 953769 };

	printAddress(addressOne);
	printAddress(addressTwo);
	printAddress(addressThree);

}

void printAddress(PostAddress& address)
{
	std::cout << "Город: " << address.city << std::endl;
	std::cout << "Улица: " << address.street << std::endl;
	std::cout << "Номер дома: " << address.numberHouse << std::endl;
	std::cout << "Номер квартиры: " << address.numberApartment << std::endl;
	std::cout << "Индекс: " << address.index << std::endl;
	std::cout << std::endl;
}