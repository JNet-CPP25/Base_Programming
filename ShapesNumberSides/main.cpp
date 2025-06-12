#include <iostream>
#include <string>


class Figure
{
protected:
	int sides_count = 0;
	std::string name;

public:
	Figure() : Figure(0, "������") {};
	Figure(int sides_count, std::string name)
	{
		this->sides_count = sides_count;
		this->name = name;
	};

	int getsiget_sides_count() const { return sides_count; } //����� ������ ����� ������

	std::string getname() const { return name; } //����� ������ �������� ������
};

class Triangle : public Figure
{
public:

	Triangle() : Figure(3, "�����������") {};
	
};

class Quadrangle : public Figure
{
public:

	Quadrangle() : Figure(4, "���������������") {};
};

void print(Figure& xFig) //������� ������ �������� ������ � ����� ������
{
	std::cout << xFig.getname() << ": " << xFig.getsiget_sides_count() << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian"); //���������� ����������� ���������
	

	std::cout << std::endl << "���������� ������: " << std::endl;

	Figure Figure1;
	print(Figure1);

	Triangle Triangle1;
	print(Triangle1);

	Quadrangle Quadrangle1;
	print(Quadrangle1);
};