#pragma once
#include <string>
#include "Figure.h"

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
	std::string getNameOfFigure();
	int getHaveFourSides();

	int getSideLengthA();
	int getSideLengthB(); 
	int getSideLengthC();
	int getSideLengthD(); 

	int getAngleA(); 
	int getAngleB(); 
	int getAngleC();
	int getAngleD();
};


