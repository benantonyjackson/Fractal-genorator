#include "stdafx.h"
#include "FractalGenerator.h"

//Constructor - called when an instance of FractalGenerator is created 
FractalGenerator::FractalGenerator(int width, int height)
	: BitmapImage::BitmapImage(width, height)
{
	
}

//Destructor - called when an instance of FractalGenerator is destroyed
FractalGenerator::~FractalGenerator()
{
	//Destructor
}


void FractalGenerator::SierpinskiTriangle(double width, double height)
{
	//Sets background colour to white
	setImageColour(255, 255, 255);

	//Draws the first triangle, each point hits the edge of the screen
	drawTriangle(0, 0, width / 2, height - 1, width - 1, 0);

	//Starts drawing Sierpinski Triangle 
	//Draws a triangle half the size of the current one with each point touching the midpoint of the current triangles lines
	genSierpinskiTriangle(width*0.25, height / 2, width*0.75, height / 2, width / 2, 0);
}

void FractalGenerator::mandelbrotSet()
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
			complex z{ 0, 0 };

			/*
			Iterates function z*z + c
			Stores number of iterations until the number gets too large for the computer to store
			*/
			int i = isInSet(z, c);

			//Uses i as a hue value and converts the hsv values to rgb values
			double hsv[3] = { 300 - i * 8 , 1, (i > 0) /*Ensures that if i is 0 then the colour is black*/ };
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
		std::cout << progress << "% \r";
	}

}

void FractalGenerator::chaosGame(std::vector<point> & points)
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

int FractalGenerator::isInSet(complex z, complex c)
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

void FractalGenerator::juliaSet(complex c)
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
		//\r removes the line after it is printed to show the percentage on only one line rather than across multiple lines
		std::cout << progress << "% \r";
	}
}

void FractalGenerator::genSierpinskiTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	//Draws the current triangle
	drawTriangle(x1, y1, x2, y2, x3, y3);
	//Stops recursive function calls when the current traingle is less than 30 pixels large
	if (y1 - y3 > 30)
	{
		//Draws triangle at bottom left line of the current trianlge
		genSierpinskiTriangle(x1 - ((x2 - x1) * 0.25), y1 - ((y1 - y3) / 2), x1 + ((x2 - x1) * 0.25), y1 - ((y1 - y3) / 2), x1, y3);
		//Draws triangle at bottom right line of the current triangle
		genSierpinskiTriangle(x2 - ((x2 - x1) * 0.25), y1 - ((y1 - y3) / 2), x2 + ((x2 - x1)*0.25), y1 - ((y1 - y3) / 2), x2, y3);
		//Draws triangle on top of the current triangle
		genSierpinskiTriangle(x1 + ((x2 - x1)*0.25), y1 + ((y1 - y3) / 2), x2 - ((x2 - x1)*0.25), y1 + ((y1 - y3) / 2), x1 + ((x2 - x1)*0.5), y1);
	}
}