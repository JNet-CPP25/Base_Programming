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
		std::cout << "������� ����� ������ �� 1 �� 12: ";
		std::cin >> month;

		Months monthCurrent{ static_cast<Months>(month) };

		switch (monthCurrent)
		{
		case Months::January:
			std::cout << "������ \n" << std::endl;
			break;
		case Months::February:
			std::cout << "������� \n" << std::endl;
			break;
		case Months::March:
			std::cout << "���� \n" << std::endl;
			break;
		case Months::April:
			std::cout << "������ \n" << std::endl;
			break;
		case Months::May:
			std::cout << "��� \n" << std::endl;
			break;
		case Months::June:
			std::cout << "���� \n" << std::endl;
			break;
		case Months::July:
			std::cout << "���� \n" << std::endl;
			break;
		case Months::August:
			std::cout << "������ \n" << std::endl;
			break;
		case Months::September:
			std::cout << "�������� \n" << std::endl;
			break;
		case Months::October:
			std::cout << "������� \n" << std::endl;
			break;
		case Months::November:
			std::cout << "������ \n" << std::endl;
			break;
		case Months::December:
			std::cout << "������� \n" << std::endl;
			break;

		default:
			if (month != 0) { std::cout << "\n������������ �����! \n" << std::endl; }
			break;
		}
	} while (month != 0);
	std::cout << "�� ��������" << std::endl;


}