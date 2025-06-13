#include "IsoscelesTriangle.h"


	isoscelesTriangle::isoscelesTriangle(int sideLengthA, int sideLengthB, int angleA, int angleB)
		: Triangle(sideLengthA, sideLengthB, sideLengthA, angleA, angleB, angleA)
	{
		Triangle::nameOfFigure = "Равнобедренный треугольник";
	};
