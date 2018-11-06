#include "stdafx.h"
#include "BitmapHeader.h"
#include <iostream>
using namespace std;
using namespace bitmap;

std::string bitmap::getInfoHeader(int width, int height, unsigned int & rowSize, unsigned int & totalFileSize)
{
	string infoHeader(HEADER_SIZE, BLANK_BYTE);

	//Adds the letters BM at the start of the header which indicates the file is a bitmap
	infoHeader[0] = BITMAPHEADER_1[0];
	infoHeader[1] = BITMAPHEADER_1[1];

	//Calculates the size of each row in bytes
	rowSize = floor((24 * width + 31) / 32)*4;
	//Calculates the size of the pixel data in bytes
	unsigned int pixelArraySize = rowSize * abs(height);
	
	//Calculates the overall size of the file in bytes 
	totalFileSize = pixelArraySize + HEADER_SIZE;
	
	//Adds the file size to the header
	//Uses bit shift because a character is 1 byte but the file size takes up 4 bytes in the file header
	infoHeader[2] = totalFileSize;
	infoHeader[3] = totalFileSize >> 8;
	infoHeader[4] = totalFileSize >> 16;
	infoHeader[5] = totalFileSize >> 24;

	//Byte number where the colour data starts
	infoHeader[10] = OFFSET;

	//Size of the windows bitmap info header in bytes
	infoHeader[14] = WINDOWS_BITMAP_INFO_HEADER_SIZE;

	//Size in pixels
	infoHeader[18] = width;
	infoHeader[19] = width >> 8;
	infoHeader[20] = width >> 16;
	infoHeader[21] = width >> 24;

	infoHeader[22] = height;
	infoHeader[23] = height >> 8;
	infoHeader[24] = height >> 16;
	infoHeader[25] = height >> 24;

	//Number of colour planes
	infoHeader[26] = COLOUR_PLANES;

	//Bits per pixel
	infoHeader[28] = BITS_PER_PIXEL;

	//Pixel array size in bytes
	infoHeader[34] = pixelArraySize;
	infoHeader[35] = pixelArraySize >> 8;
	infoHeader[36] = pixelArraySize >> 16;
	infoHeader[37] = pixelArraySize >> 24;

	//Pixels per meter (For printing) 
	infoHeader[38] = PIXELS_PER_METER;
	infoHeader[42] = PIXELS_PER_METER;

	return infoHeader;
}
