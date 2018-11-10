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

	void juliaSet(complex c);

	//Stores an estimate how close the image is to being generated as a percentage
	int progress = 0;

protected:
	//Recursive function used to generate the Sierpinski triangle
	void genSierpinskiTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
	//Itterates Fc(z) = z*z+c 100 times
	int isInSet(complex z, complex c);
};