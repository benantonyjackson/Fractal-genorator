#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

//Handles the creation of, and interaction with the bitmap image
class BitmapImage
{
public:
	BitmapImage(int width, int height);
	~BitmapImage();

	//Used to easily access pixel colour data
	enum colour
	{
		r = 2,
		g = 1,
		b = 0
	};

	struct point
	{
		double x;
		double y;
	};

	//Writes the image to a file
	void writeToFile(std::ofstream & file);

	//Draws a straight line between two vertices
	void drawLine(double x1, double y1, double x2, double y2);

	//Returns a pointer to the requested pixel
	//p[color::r] to acccess the red data of the pixel
	//p[color::g] to acccess the green data of the pixel
	//p[color::b] to acccess the blue data of the pixel
	//
	//
	//e.g. (getPixel(100, 100)[color::r] = 255;)
	//Would set the pixels red value at 100 100 to 255
	char * getPixel(unsigned int x, unsigned int y);

	//Sets the image to a single color
	void setImageColour(int r, int g, int b);
	
protected:
	const double PI = 3.141592653589793238463;
	//Stores the width of the image in pixels
	int width;

	//Stores the height of the image in pixels
	int height;

	//Stores the total size of the file in bytes
	unsigned int size;

	//Stores the total size of each row in bytes
	unsigned int rowSize;
	
	//Swaps two numbers
	void swap(double &x, double &y);

	//Draws a triangle from three vertices
	void drawTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
	
	//Converts HSV values to RGB values
	void fromHSVtoRGB(double hsv[3], double rgb[3]);
	
	//Genorates the bitmap file header
	void genInfoHeader(int width, int height);

	//Stores the number bits of bit required to pad out the row
	int padding = 0;

	//Stores bitmap to be written to a file
	char * data;

	//Variables used to genorate the bitmap file header

	//Stores the first two bytes of the bitmap,
	//Used to establish the file as a bitmap
	const char BITMAPHEADER_1[2] = { 'B', 'M' };

	//Stores where the colour data starts in the file
	const unsigned __int8 OFFSET = 54;

	//Stores the size of the windows bitmap info header
	const unsigned __int32 HEADER_SIZE = 54;

	const char BLANK_BYTE = 0;

	const char WINDOWS_BITMAP_INFO_HEADER_SIZE = 40;

	const char COLOUR_PLANES = 1;

	const char BITS_PER_PIXEL = 24;

	//Used for printing
	const char PIXELS_PER_METER = 0x5C;
};

