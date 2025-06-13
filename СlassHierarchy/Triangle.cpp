#include "Triangle.h"
#include "Figure.h"


Triangle::Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
{
	nameOfFigure = "Треугольник";
	a = sideLengthA;
	b = sideLengthB;
	c = sideLengthC;
	A = angleA;
	B = angleB;
	C = angleC;
}