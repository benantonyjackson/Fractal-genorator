#include "stdafx.h"
#include "BitmapImage.h"
#include <iostream>
#include <math.h>

//Constructor - called when an instance of BitmapImage is created 
BitmapImage::BitmapImage(int width, int height)
{
	//Generate the file header
	std::string header = bitmap::getInfoHeader(width, height, rowSize, size);
	//Calculates the amount of padding that should be at the end of each row
	this->padding = rowSize - (width * 3);

	this->width = width;
	this->height = height;

	//Creates a new array of characters on the heap for the file data
	data = new char[size];
	
	//Writes the file header to the file data array
	for (int i = 0; i < header.size(); i++)
	{
		data[i] = header[i];
	}

	
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

	//Calculates the gradient of the line
	double o = y2 - y1;
	double a = abs(x2 - x1);
	double gradient;

	//If the line is horizontal with no gradient  
	if (x1 == x2)
	{
		gradient = 0;
	}
	else
	{
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

void BitmapImage::SierpinskiTriangle(double width, double height)
{
	setImageColour(255, 255, 255);
	//Draws the first triangle, each point hits the edge of the screen
	drawTriangle(0, 0, width / 2, height-1, width-1, 0);
	//Starts drawing Sierpinski Triangle 
	//Draws a triangle half the size of the current one with each point touching the midpoint of the current triangles lines
	genSierpinskiTriangle(width*0.25, height / 2, width*0.75, height / 2, width / 2, 0);

}

char * BitmapImage::getPixel(unsigned int x, unsigned int y)
{
	//Returns a pointer to the pixel at the given coordinates
	//Uses pointer arithmetic to find the correct position in the array of characters used to store the bitmap data
	return data + bitmap::HEADER_SIZE + ((y*(int)rowSize) + (padding*y)) + (x * 3);
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

void BitmapImage::mandelbrotSet()
{
	//For each pixel in the image
	for (double x = 0; x < 8999; x++)
	{
		for (double y = 0; y < 5999; y++)
		{
			/*
			Scales the x and y axis to a complex number from -2 to 1 on the real number line
			and -1 to 1 on the imaginary number line
			*/
			complex c;
			c.real = (x / 3000.0) - 2.0;
			c.imaginary = (y / 3000.0) - 1.0;

			//Instantiates a complex number 0
			complex z{0, 0};

			/*
			Iterates function z*z + c
			Stores number of iterations until the number gets too large for the computer to store
			*/
			int i = isInSet(z, c);
			
			//Uses i as a hue value and converts the hsv values to rgb values
			double hsv[3] = {300-i*8 , 1, (i > 0) /*Ensures that if i is 0 then the colour is black*/ };
			double rgb[3];
			fromHSVtoRGB(hsv, rgb);

			char * temp = getPixel(x, y);
			temp[0] = (char)rgb[2] * 255;
			temp[1] = (char)rgb[1] * 255;
			temp[2] = (char)rgb[0] * 255;


		}
		//Calculates the current percentage of completion
		progress = (((float)x / 8999) * 100);
		//\r removes the line after it is printed to show the percentage on only one line rather than across multiple lines
		//-https://stackoverflow.com/questions/35258108/delete-the-last-line-outputted-into-console-from-a-cout
		std::cout << progress << "% \r";
		//End of code sourced from -https://stackoverflow.com/questions/35258108/delete-the-last-line-outputted-into-console-from-a-cout
	}

}

void BitmapImage::chaosGame(std::vector<point> & points)
{
	//Chooses a random point in the image to start
	point currentPoint{ rand() % 2000, rand() % 2000 };

	for (int i = 0; i < 50000000; i++)
	{
		//Creates a pointer to a random point in the list of points provided by the user
		point * tempPoint = &points[rand() % points.size()];

		//Moves the current point half way toward the randomly selected point
		currentPoint = point{ currentPoint.x - ((currentPoint.x - tempPoint->x) / 2),
			currentPoint.y - ((currentPoint.y - tempPoint->y) / 2) };

		//Draws the current point
		getPixel(currentPoint.x, currentPoint.y)[colour::g] = 255;
		
	}
}

int BitmapImage::isInSet(complex z, complex c)
{
	//Iterates function Fc(z) = z*z+c 100 times
	for (int count = 1; count < 100; count++)
	{
		complex temp;
		//Squares the complex number z and adds the complex number c
		temp.real = (z.real*z.real) - (z.imaginary*z.imaginary) + c.real;
		temp.imaginary = (z.real * z.imaginary) * 2.0 + c.imaginary;

		z = temp;

		//If the complex number is too large for the computer to store 
		if (isnan(z.real + z.imaginary))
		{
			//Return the number of iterations 
			return count;
		}
	}

	//If in the set return 0
	return 0;
}

void BitmapImage::juliaSet(complex c)
{
	//For each pixel in the image
	for (int x = 0; x < 11999; x++)
	{
		for (int y = 0; y < 11999; y++)
		{
			//Scales the x and y axis to a complex number from -2 to 1 on the real number line
			//And -1 to 1 on the imaginary number line
			complex z;
			z.real = (x / 3000.0) - 2.0;
			z.imaginary = (y / 3000.0) - 2.0;

			/*
			Iterates function z*z + c
			Stores number of iterations until the number gets too large for the computer to store
			*/
			int i = isInSet(z, c);

			//Uses i as a hue value and converts the hsv values to rgb values
			double hsv[3] = { 300 - i * 8, 1, (i > 0) };
			double rgb[3];
			
			fromHSVtoRGB(hsv, rgb);

			char * temp = getPixel(x, y);
			temp[0] = (char)rgb[2] * 255;
			temp[1] = (char)rgb[1] * 255;
			temp[2] = (char)rgb[0] * 255;
			
		}
		
		progress = (((float)x / 11999) * 100);
		std::cout << progress << "% \r";
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

void BitmapImage::genSierpinskiTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	//Draws the current triangle
	drawTriangle(x1, y1, x2, y2, x3, y3);
	//Stops recursive function calls when the current traingle is less than 30 pixels large
	if (y1-y3 > 30)
	{
		//Draws triangle at bottom left line of the current trianlge
		genSierpinskiTriangle(x1 - ((x2 - x1) * 0.25), y1 - ((y1 - y3) / 2), x1 + ((x2 - x1) * 0.25), y1 - ((y1 - y3) / 2), x1, y3);
		//Draws triangle at bottom right line of the current triangle
		genSierpinskiTriangle(x2 - ((x2-x1) * 0.25), y1 - ((y1 - y3) / 2), x2 + ((x2-x1)*0.25), y1 - ((y1 - y3) / 2), x2, y3);
		//Draws triangle on top of the current triangle
		genSierpinskiTriangle(x1 + ((x2 - x1)*0.25), y1 + ((y1 - y3) / 2), x2 - ((x2 - x1)*0.25), y1 + ((y1 - y3) / 2), x1 + ((x2 - x1)*0.5), y1);
	}
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