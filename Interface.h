#include <windows.h>

#ifndef INTERFACE_H
#define INTERFACE_H

class Interface
{
public:
	Interface( int height = 0, int width = 0 );
	void init( HANDLE outputHandle, CHAR_INFO* consoleBuffer, COORD gridSize, COORD gridOrigin, SMALL_RECT rectangle );
	void initConsoleGame();
	void drawGrid();
	void drawChar();
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