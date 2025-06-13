#include "Quadrilateral.h"


Quadrilateral::Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
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
