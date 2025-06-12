#include <iostream>
#include <iostream>#include <string>

class Figure
{
protected:
	std::string nameOfFigure = "Фигура";
	bool checkFigure = false;
	int quantityOfSides = 0;
	int sideLengthA = 0;
	int sideLengthB = 0;
	int sideLengthC = 0;
	int sideLengthD = 0;
	int angleA = 0;
	int angleB = 0;
	int angleC = 0;
	int angleD = 0;

	virtual bool check() //Виртуальный метод проверки фигуры.Кол-во сторон == 0 
	{
		if (quantityOfSides == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	//Геттеры
	std::string getNameOfFigure() { return nameOfFigure; }

	int getSideLengthA() { return sideLengthA; }
	int getSideLengthB() { return sideLengthB; }
	int getSideLengthC() { return sideLengthC; }
	int getSideLengthD() { return sideLengthD; }

	int getAngleA() { return angleA; }
	int getAngleB() { return angleB; }
	int getAngleC() { return angleC; }
	int getAngleD() { return angleD; }

	virtual void print_info() //Виртуальный метод печати и проверка правильности фигуры
	{
		std::cout << std::endl;
		std::cout << nameOfFigure << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else { std::cout << "Неправильная" << std::endl; }

		std::cout << "Количество сторон: " << quantityOfSides << std::endl;
	}
};

class Triangle : public Figure
{
protected:
	bool check() override //Переписанный метод проверки на сумма всех углов треуг == 180
	{
		if ((angleA + angleB + angleC) == 180)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	//Конструктор треугольника
	Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
	{
		nameOfFigure = "Треугольник";
		this->sideLengthA = sideLengthA;
		this->sideLengthB = sideLengthB;
		this->sideLengthC = sideLengthC;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		quantityOfSides = 3;
		checkFigure = check();
	}

	void print_info() override //Переписанный метод печати с вызовом базового метода печати
	{
		Figure::print_info();

		std::cout << "Стороны:";
		std::cout << " a = " << getSideLengthA() << ", b = " << getSideLengthB() << ", с = " << getSideLengthC();
		std::cout << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << getAngleA() << ", В = " << getAngleB() << ", С = " << getAngleC();
		std::cout << std::endl;
	}

};

class rightTriangle : public Triangle
{
protected:
	bool check() override
	{
		if (Triangle::check() && (angleC == 90))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	rightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Прямоугольный треугольник";
	};
};

class isoscelesTriangle : public Triangle
{
protected:
	bool check() override
	{
		if (Triangle::check() && (sideLengthA == sideLengthC && angleA == angleC))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	isoscelesTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Равнобедренный треугольник";
	};
};

class equilateralTriangle : public Triangle
{
private:
	bool CheckEquilateralTriangle()
	{
		if ((sideLengthA == sideLengthB && sideLengthB == sideLengthC) && ((angleA == 60) && (angleA = 60) && (angleC = 60)))
		{
			return true;
		}
		else
		{
			return false;
		};
	}

public:
	equilateralTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Равносторонний треугольник";
	};
protected:
	bool check() override
	{
		if (Triangle::check() && (CheckEquilateralTriangle()))
		{
			return true;
		}
		else
		{
			return false;
		};
	};



};

class Quadrilateral : public Figure
{
protected:
	virtual bool check()
	{
		if ((angleA + angleB + angleC + angleD) == 360)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	//Метод проверки "стороны a,c и b,d попарно равны"
	bool metodCheckSideLengthACiBD()
	{
		if (sideLengthA == sideLengthC && sideLengthB == sideLengthD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	//Метод проверки "все стороны равны"
	bool metodCheckSideLengthACBD()
	{
		if (sideLengthA == sideLengthB && sideLengthB == sideLengthC && sideLengthC == sideLengthD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	//Метод проверки "все углы равны 90 градусов"
	bool metodCheckAngleabcd90()
	{
		if (angleA == 90 && angleB == 90 && angleC == 90 && angleD == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	//Метод проверки "углы A,C и B,D попарно равны"
	bool metodCheckAngleACiBD()
	{
		if (angleA == angleC && angleB == angleD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
	{
		nameOfFigure = "Четырехугольник";

		quantityOfSides = 4;
		this->sideLengthA = sideLengthA;
		this->sideLengthB = sideLengthB;
		this->sideLengthC = sideLengthC;
		this->sideLengthD = sideLengthD;

		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		this->angleD = angleD;
	}

	void print_info() override
	{
		Figure::print_info();

		std::cout << "Стороны:";
		std::cout << " a = " << getSideLengthA() << ", b = " << getSideLengthB() << ", с = " << getSideLengthC();
		std::cout << ", d = " << getSideLengthD() << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << getAngleA() << ", В = " << getAngleB() << ", С = " << getAngleC();
		std::cout << ", D = " << getAngleD() << std::endl;
	}

};

class Rectangle : public Quadrilateral
{
protected:
	bool check() override
	{
		if (Quadrilateral::check() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Rectangle(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Прямоугольник";
	}
};

class Square : public Quadrilateral
{
protected:
	bool check() override
	{
		if (Quadrilateral::check() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	Square(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
protected:
	bool check() override
	{
		if (Quadrilateral::check() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Parallelogram(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Параллелограмм";
	}
};

class Rhomb : public Quadrilateral
{
protected:
	bool check() override
	{
		if (Quadrilateral::check() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Rhomb(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Ромб";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
	system("chcp 1251");

	Figure Figure1;
	Figure1.print_info();

	Triangle Triangle1(10, 20, 30, 50, 60, 70);
	Triangle1.print_info();

	rightTriangle rightTriangle1(10, 20, 30, 50, 60, 90);
	rightTriangle1.print_info();

	rightTriangle rightTriangle2(10, 20, 30, 50, 40, 90);
	rightTriangle2.print_info();

	isoscelesTriangle isoscelesTriangle1(10, 20, 10, 50, 60, 90);
	isoscelesTriangle1.print_info();

	equilateralTriangle equilateralTriangle1(30, 30, 30, 60, 60, 60);
	equilateralTriangle1.print_info();

	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	Quadrilateral1.print_info();

	Rectangle Rectangle1(10, 20, 10, 20, 90, 90, 90, 90);
	Rectangle1.print_info();

	Square Square1(20, 20, 20, 20, 90, 90, 90, 90);
	Square1.print_info();

	Parallelogram Parallelogram1(20, 30, 20, 30, 30, 40, 30, 40);
	Parallelogram1.print_info();

	Rhomb Rhomb1(30, 30, 30, 30, 30, 40, 30, 40);
	Rhomb1.print_info();
}