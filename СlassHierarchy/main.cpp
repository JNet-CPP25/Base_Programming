#include <iostream>
#include <string>
#include "Figure.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"
#include "Print_info.h"



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