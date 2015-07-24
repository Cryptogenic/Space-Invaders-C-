#include <windows.h>

#ifndef INTERFACE_H
#define INTERFACE_H

class Interface
{
public:
	Interface();
	void drawGrid();
	int drawChar( int x, int y, char symbol, char type );
	int getWidth();
	int getHeight();
	char checkChar( int x, int y );
private:
	int max_width;
	int max_height;
	HANDLE out;
	CHAR_INFO* buffer;
	COORD size;
	COORD origin;
	SMALL_RECT rect;
};

#endif