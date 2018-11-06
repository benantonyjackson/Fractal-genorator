#pragma once
#include <memory>
#include <vector>
#include <string>
//Size of the file is pixel array size + header size

namespace bitmap
{
	//Stores the first two bytes of the bitmap,
	//Used to establish the file as a bitmap
	const char BITMAPHEADER_1[2] = { 0x42, 0x4D };
	//Stores where the colour data starts in the file
	const unsigned __int8 OFFSET = 0x36;
	//Stores the size of the windows bitmap info header
	const unsigned __int32 HEADER_SIZE = 54;
	const char BLANK_BYTE = 0x00;
	//
	const char WINDOWS_BITMAP_INFO_HEADER_SIZE = 0x28;

	const char COLOUR_PLANES = 0x01;

	const char BITS_PER_PIXEL = 0x18;

	const char PIXELS_PER_METER = 0x5C;


	std::string getInfoHeader(int width, int height, unsigned int & rowSize, unsigned int & totalFileSize);
}