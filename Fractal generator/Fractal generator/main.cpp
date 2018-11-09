// Fractal generator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "FractalGenerator.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <time.h>
#include <random>
#include <Windows.h>
#include <string>


int main()
{
	//Initialises random
	srand(time(NULL));

	FractalGenerator * image = NULL;
	//String which stores the fractal the user selected 
	std::string cmd;

	//Thread that will generate  the fractal while the user enters the file location
	std::thread * thread1 = NULL;

	//Starts the GUI menu executable
	if (system("main_menu\\Fractal_genorator.exe"))
	{
		//Handles executable not existing
		//Clears console of the default error message
		system("CLS");
		std::cout << "Could not find the main_menu.exe\n";
		system("pause");
		return 0;
	}

	//Reads user input
	std::ifstream fCmd("cmd.txt");

	if (!fCmd)
	{

		std::cout << "No user input was recieved\n";

		system("pause");

		return 0;
	}

	fCmd >> cmd;

	if (cmd == "mandelbrotSet")
	{
		image = new FractalGenerator(9000, 6000);

		thread1 = new std::thread(&FractalGenerator::mandelbrotSet, *image);
	}
	else if (cmd == "juliaSet")
	{
		image = new FractalGenerator(12000, 12000);
		double real, imaginary;
		//Reads the complex number selected by the user from a file
		fCmd >> real;
		fCmd >> imaginary;

		thread1 = new std::thread(&FractalGenerator::juliaSet, *image, FractalGenerator::complex{ real ,  imaginary });
	}
	else if (cmd == "SierpinskiTriangle")
	{
		int width, height;
		fCmd >> width;
		fCmd >> height;

		image = new FractalGenerator(width, height);

		std::cout << "Please wait...\n\n";

		thread1 = new std::thread(&FractalGenerator::SierpinskiTriangle, *image, width, height);
	}
	else if (cmd == "chaosGame")
	{
		image = new FractalGenerator(2000, 2000);

		std::vector<BitmapImage::point> points;

		
		int numOfPoints;

		fCmd >> numOfPoints;

		//Reads each point entered by the user into a vector
		for (int i = 0; i < numOfPoints; i++)
		{
			points.push_back(BitmapImage::point{ 0,0 });
			fCmd >> points[i].x;
			fCmd >> points[i].y;
		}

		std::cout << "Please wait...\n\n";
		
		thread1 = new std::thread(&FractalGenerator::chaosGame, *image, points);
		image->chaosGame(points);
	}

	//Closes the file
	fCmd.close();
	std::string errorMessage = "";
	std::string fileName;
	
	//Deletes the text file containing user input
	remove("cmd.txt");

	//Starts save file dialog
	if (system("Select_file\\Select_file.exe"))
	{
		//Handles executable not existing

		//Clears console of default error message for exe not existing
		system("CLS");

		fileName = "Fractal.bmp";

		errorMessage = "The file save dialog could not be found\n";
		errorMessage += "The file will be saved as Fractal.bmp in the root directory of the executable";
	}
	else
	{
		//Reads the file directory that the user selected
		fCmd.open("file_name.txt");
		if (!fCmd)
		{
			//Handles the file not existing
			errorMessage = "There was an error reading the location to store the file\n";
			errorMessage += "The file will be saved as Fractal.bmp in the root directory of the executable";
		}
		else
		{
			std::getline(fCmd, fileName);

			fCmd.close();
		}

	}

	//If the file name is the rouge value *, which means the user did not enter a file or closed the dialog
	if (fileName == "*")
	{
		fileName = "Fractal.bmp";
		errorMessage = "No save directory was provided\n";
		errorMessage += "The file will be saved as Fractal.bmp in the root directory of the executable";
	}
	
	//Deletes the file containing the file directory
	remove("file_name.txt");

	//Waits for the file to be finished generating
	thread1->join();

	//Writes image to file
	std::cout << "Writting to file\n";
	std::ofstream file( fileName, std::ios::binary);
	image->writeToFile(file);
	
	//If an error occurred, print the error message
	if (errorMessage != "")
	{
		std::cout << std::endl << std::endl;
		std::cout << errorMessage << "\n\n\n";
	}

	
	system("pause");

    return 0;
}

