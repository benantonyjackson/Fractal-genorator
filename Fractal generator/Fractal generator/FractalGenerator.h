#pragma once
#include "BitmapImage.h"

/*
Handles the generation of the fractals
Inherits from BitmapImage class so that the fractals can be written to a bitmap image file
*/
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

	//Stores an estimate how close the image is to being generated as a percentage
	int progress = 0;
};

