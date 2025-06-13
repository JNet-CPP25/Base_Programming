#include "EquilateralTriangle.h"


	equilateralTriangle::equilateralTriangle(int sideLengthA)
		: Triangle(sideLengthA, sideLengthA, sideLengthA, 60, 60, 60)
	{
		Triangle::nameOfFigure = "Равносторонний треугольник";
	};
