#pragma once
#include "BitmapImage.h"
class FractalGenerator :
	public BitmapImage
{
public:
	FractalGenerator(int width, int height);
	~FractalGenerator();

	struct complex
	{
		double real;
		double imaginary;
	};


	void SierpinskiTriangle(double width, double height);

	void mandelbrotSet();

	void chaosGame(std::vector<point> & points);

	int isInSet(complex z, complex c);

	void juliaSet(complex c);

	void genSierpinskiTriangle(double x1, double y1, double x2, double y2, double x3, double y3);

};

