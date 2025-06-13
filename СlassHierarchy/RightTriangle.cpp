#include "Triangle.h"
#include "RightTriangle.h"


rightTriangle::rightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB)
	: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, 90)
{
	Triangle::nameOfFigure = "Прямоугольный треугольник";
};