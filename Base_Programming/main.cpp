#include <iostream>

enum class Months {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int month{};
	do {
		std::cout << "Введите номер месяца от 1 до 12: ";
		std::cin >> month;

		Months monthCurrent{ static_cast<Months>(month) };

		switch (monthCurrent)
		{
		case Months::January:
			std::cout << "Январь \n" << std::endl;
			break;
		case Months::February:
			std::cout << "Февраль \n" << std::endl;
			break;
		case Months::March:
			std::cout << "Март \n" << std::endl;
			break;
		case Months::April:
			std::cout << "Апрель \n" << std::endl;
			break;
		case Months::May:
			std::cout << "Май \n" << std::endl;
			break;
		case Months::June:
			std::cout << "Июнь \n" << std::endl;
			break;
		case Months::July:
			std::cout << "Июль \n" << std::endl;
			break;
		case Months::August:
			std::cout << "Август \n" << std::endl;
			break;
		case Months::September:
			std::cout << "Сентябрь \n" << std::endl;
			break;
		case Months::October:
			std::cout << "Октябрь \n" << std::endl;
			break;
		case Months::November:
			std::cout << "Ноябрь \n" << std::endl;
			break;
		case Months::December:
			std::cout << "Декабрь \n" << std::endl;
			break;

		default:
			if (month != 0) { std::cout << "\nНеправильный номер! \n" << std::endl; }
			break;
		}
	} while (month != 0);
	std::cout << "До свидания" << std::endl;


}