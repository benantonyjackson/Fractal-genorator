#pragma once

#include <vector>
#include <string>
#include "bitmapheader.h"
#include <iostream>
#include <fstream>
#include <mutex>

class BitmapImage
{
public:
	BitmapImage(int width, int height);
	~BitmapImage();
	

	enum colour
	{
		r = 2,
		g = 1,
		b = 0
	};

	struct complex 
	{
		double real;
		double imaginary;
	};

	struct point
	{
		double x;
		double y;
	};

	void writeToFile(std::ofstream & file);

	

	void drawLine(double x1, double y1, double x2, double y2);

	void SierpinskiTriangle(double width, double height);

	char * getPixel(unsigned int x, unsigned int y);

	void setImageColour(int r, int g, int b);

	void mandelbrotSet();

	void chaosGame(std::vector<point> & points);

	int isInSet(complex z, complex c);

	void juliaSet(complex c);
	
	int progress = 0;

	
private:
	const double PI = 3.141592653589793238463;
	int width, height;
	unsigned int size;
	unsigned int rowSize;
	
	void swap(double &x, double &y);

	void drawTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
	void genSierpinskiTriangle(double x1, double y1, double x2, double y2, double x3, double y3);

	void fromHSVtoRGB(double hsv[3], double rgb[3]);

	int padding = 0;

	char * data;

};

