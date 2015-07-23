#include <windows.h>

#ifndef INTERFACE_H
#define INTERFACE_H

class Interface
{
public:
	void init( HANDLE, CHAR_INFO*, COORD, COORD, SMALL_RECT );
	void drawGrid( CHAR_INFO*, COORD );
	void drawChar( CHAR_INFO*, COORD );
private:
	int max_width;
	int max_height;
	HANDLE out;
	CHAR_INFO* buffer;
	COORD size;
	COORD origin;
	SMALL_RECT rect;
};