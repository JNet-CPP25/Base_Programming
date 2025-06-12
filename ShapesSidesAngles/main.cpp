#include <iostream>
#include <string>

class Figure
{
protected:
	std::string nameOfFigure;
	bool haveFourSides = false; //признак что четыре стороны
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;

public:
	std::string getNameOfFigure() { return nameOfFigure; }
	int getHaveFourSides() { return haveFourSides; }

	int getSideLengthA() { return a; }
	int getSideLengthB() { return b; }
	int getSideLengthC() { return c; }
	int getSideLengthD() { return d; }

	int getAngleA() { return A; }
	int getAngleB() { return B; }
	int getAngleC() { return C; }
	int getAngleD() { return D; }
};


class Triangle : public Figure
{
public:
		//Конструктор треугольника
	Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
	{
		nameOfFigure = "Треугольник";
		a = sideLengthA;
		b = sideLengthB;
		c = sideLengthC;
		A = angleA;
		B = angleB;
		C = angleC;
	}
};

class rightTriangle : public Triangle 
{
public:
	rightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, 90)
	{
		Triangle::nameOfFigure = "Прямоугольный треугольник";
	};
};

class isoscelesTriangle : public Triangle   //равнобедренный треугольник
{
public:
	isoscelesTriangle(int sideLengthA, int sideLengthB, int angleA, int angleB)
		: Triangle(sideLengthA, sideLengthB, sideLengthA, angleA, angleB, angleA)
	{
		Triangle::nameOfFigure = "Равнобедренный треугольник";
	};
};

class equilateralTriangle : public Triangle
{
public:
	equilateralTriangle(int sideLengthA)
		: Triangle(sideLengthA, sideLengthA, sideLengthA, 60, 60, 60)
	{
		Triangle::nameOfFigure = "Равносторонний треугольник";
	};
};

class Quadrilateral : public Figure
{

public:
	Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
	{
		nameOfFigure = "Четырехугольник";

		haveFourSides = true;

		a = sideLengthA;
		b = sideLengthB;
		c = sideLengthC;
		d = sideLengthD;

		A = angleA;
		B = angleB;
		C = angleC;
		D = angleD;
	}
};

class Rectangle : public Quadrilateral
{
public: //int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD
	Rectangle(int sideLengthA, int sideLengthB)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthA, sideLengthB, 90, 90, 90, 90)
	{
		Quadrilateral::nameOfFigure = "Прямоугольник";
	}
};

class Square : public Quadrilateral
{
public:
	Square(int sideLengthA)
		: Quadrilateral(sideLengthA, sideLengthA, sideLengthA, sideLengthA, 90, 90, 90, 90)
	{
		Quadrilateral::nameOfFigure = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int sideLengthA, int sideLengthB, int angleA, int angleB)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthA, sideLengthB, angleA, angleB, angleA, angleB)
	{
		Quadrilateral::nameOfFigure = "Параллелограмм";
	}
};

class Rhomb : public Quadrilateral
{
public:
	Rhomb(int sideLengthA, int angleA, int angleB)
		: Quadrilateral(sideLengthA, sideLengthA, sideLengthA, sideLengthA, angleA, angleB, angleA, angleB)
	{
		Quadrilateral::nameOfFigure = "Ромб";
	}
};

void print_info(Figure& figure)
{
	std::cout << std::endl;
	std::cout << figure.getNameOfFigure() << ":" << std::endl;

	std::cout << "Стороны:";
	std::cout << " a = " << figure.getSideLengthA() << ", b = " << figure.getSideLengthB() << ", с = " << figure.getSideLengthC();
	if (figure.getHaveFourSides())
	{
		std::cout << ", d = " << figure.getSideLengthD() << std::endl;
	}
	else { std::cout << std::endl; }

	std::cout << "Углы:";
	std::cout << " А = " << figure.getAngleA() << ", В = " << figure.getAngleB() << ", С = " << figure.getAngleC();
	if (figure.getHaveFourSides()) { std::cout << ", D = " << figure.getAngleD() << std::endl; }
	else { std::cout << std::endl; }
}

int main()
{
	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы

	Triangle Triangle1(10, 20, 30, 40, 50, 60);
	print_info(Triangle1);

	rightTriangle rightTriangle1(10, 20, 30, 40, 50);
	print_info(rightTriangle1);

	isoscelesTriangle isoscelesTriangle1(11, 220, 330, 440);
	print_info(isoscelesTriangle1);

	equilateralTriangle equilateralTriangle1(111);
	print_info(equilateralTriangle1);

	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(Quadrilateral1);

	Rectangle Rectangle1(14, 24);
	print_info(Rectangle1);

	Square Square1(333);
	print_info(Square1);

	Parallelogram Parallelogram1(555, 666, 777, 888);
	print_info(Parallelogram1);

	Rhomb Rhomb1(14, 24, 34);
	print_info(Rhomb1);
}