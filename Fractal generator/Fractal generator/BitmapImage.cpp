#include "stdafx.h"
#include "BitmapImage.h"
#include <iostream>


//Constructor - called when an instance of BitmapImage is created 
BitmapImage::BitmapImage(int width, int height)
{
	//Generate the file header
	genInfoHeader(width, height);

	this->width = width;
	this->height = height;

	//Calculates the amount of padding that should be at the end of each row
	padding = rowSize - (width * 3);
}
//Destructor - called when an instance of BitmapImage is destroyed
BitmapImage::~BitmapImage()
{
	//Destructor
}

void BitmapImage::writeToFile(std::ofstream & file)
{
	std::cout << "Writting file data to disk\n";
	//Writes file data to the file 
	file.write(data, size);

	//Frees memory data takes up after the data was written to the file
	delete data;
}

void BitmapImage::drawLine(double x1, double y1, double x2, double y2)
{
	//Ensures that line is drawn lowest point to highest point
	if (y1 > y2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}

	double gradient;

	//If the line is perfectly horizontal then the line has no gradient 
	if (x1 == x2)
	{
		gradient = 0;
	}
	else
	{
		//Calculates the gradient of the line
		double o = y2 - y1;
		double a = abs(x2 - x1);
		//Divided by 4 because a point is drawn in intervals of 0.25 to avoid gaps in the line
		gradient = (o / a) / 4;
	}

	double increment;

	//Determines whether the line is drawn left to right or right to left
	if (x2 < x1)
	{
		increment = -0.25;
	}
	else
	{
		increment = 0.25;
	}

	//Stores the y value of the current pixel being drawn
	//Initialised to the y value of lowest of the two points
	double y = y1;
	
	for (double x = x1; (int)x != (int)x2; x += increment)
	{
		//Increases y by the gradient
		y += gradient;

		//Gets a pointer to the current pixel in the file data
		char * temp = getPixel(x, y);
		//Indexes the pixels blue intensity
		temp[colour::b] = 0;
		//Indexes the pixels green intensity
		temp[colour::g] = 0;
		//Indexes the pixels red intensity
		temp[colour::r] = 0;
	}
}

char * BitmapImage::getPixel(unsigned int x, unsigned int y)
{
	//Returns a pointer to the pixel at the given coordinates
	//Uses pointer arithmetic to find the correct position in the array of characters used to store the bitmap data
	return data + HEADER_SIZE + ((y*rowSize) /*+ (padding* y)*/) + (x * 3);
}

void BitmapImage::setImageColour(int r, int g, int b)
{
	//Sets the value of each pixel to a given colour
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//Set the current pixels rgb values to the values provided
			char * temp = getPixel(x, y);
				
			temp[colour::b] = b;
			temp[colour::g] = g;
			temp[colour::r] = r;
		}
	}
}

void BitmapImage::swap(double & x, double & y)
{
	//Swaps two numbers
	int temp = x;
	x = y;
	y = temp;
}

void BitmapImage::drawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	//Draws a triangle
	drawLine(x1, y1, x2, y2);
	drawLine(x2, y2, x3, y3);
	drawLine(x3, y3, x1, y1);
}



//Function created using this webpage -https://www.rapidtables.com/convert/color/hsv-to-rgb.html
//Converts hsv to rgb values
void BitmapImage::fromHSVtoRGB(double hsv[3], double rgb[3])
{
	if (hsv[0] < 0)
	{
		hsv[0] += 360;
		fromHSVtoRGB(hsv, rgb);
	}
	else if (hsv[0] > 360)
	{
		hsv[0] -= 360;
		fromHSVtoRGB(hsv, rgb);
	}

	double c = hsv[1] * hsv[2];
	double x = c* (1 - abs(fmod(hsv[0] / 60.0, 2.0) - 1));
	if (hsv[0] < 60)
	{
		rgb[0] = c;
		rgb[1] = x;
		rgb[2] = 0;
	}
	else if (hsv[0] < 120)
	{
		rgb[0] = x;
		rgb[1] = c;
		rgb[2] = 0;
	}
	else if (hsv[0] < 180)
	{
		rgb[0] = 0;
		rgb[1] = c;
		rgb[2] = x;
	}
	else if (hsv[0] < 240)
	{
		rgb[0] = 0;
		rgb[1] = x;
		rgb[2] = c;
	}
	else if (hsv[0] < 300)
	{
		rgb[0] = x;
		rgb[1] = 0;
		rgb[2] = c;
	}
	else if (hsv[0] < 360)
	{
		rgb[0] = c;
		rgb[1] = 0;
		rgb[2] = x;
	}

	double m = hsv[2] - c;

	rgb[0] += m;
	rgb[1] += m;
	rgb[2] += m;

}

void BitmapImage::genInfoHeader(int width, int height)
{

	//Calculates the size of each row in bytes
	rowSize = floor((24 * width + 31) / 32) * 4;
	//Calculates the size of the pixel data in bytes
	unsigned int pixelArraySize = rowSize * abs(height);

	//Calculates the overall size of the file in bytes 
	size = pixelArraySize + HEADER_SIZE;

	//Creates a new array of characters on the heap for the file data
	data = new char[size];

	//Adds the letters BM at the start of the header which indicates the file is a bitmap
	data[0] = BITMAPHEADER_1[0];
	data[1] = BITMAPHEADER_1[1];

	

	//Adds the file size to the header
	//Uses bit shift because a character is 1 byte but the file size takes up 4 bytes in the file header
	data[2] = size;
	data[3] = size >> 8;
	data[4] = size >> 16;
	data[5] = size >> 24;

	//Byte number where the colour data starts
	data[10] = OFFSET;

	//Size of the windows bitmap info header in bytes
	data[14] = WINDOWS_BITMAP_INFO_HEADER_SIZE;

	//Size in pixels
	data[18] = width;
	data[19] = width >> 8;
	data[20] = width >> 16;
	data[21] = width >> 24;

	data[22] = height;
	data[23] = height >> 8;
	data[24] = height >> 16;
	data[25] = height >> 24;

	//Number of colour planes
	data[26] = COLOUR_PLANES;

	//Bits per pixel
	data[28] = BITS_PER_PIXEL;

	//Pixel array size in bytes
	data[34] = pixelArraySize;
	data[35] = pixelArraySize >> 8;
	data[36] = pixelArraySize >> 16;
	data[37] = pixelArraySize >> 24;

	//Pixels per meter (For printing) 
	data[38] = PIXELS_PER_METER;
	data[42] = PIXELS_PER_METER;
}
