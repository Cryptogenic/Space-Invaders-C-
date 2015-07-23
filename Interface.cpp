#include <windows.h>
#include "Interface.h"

Interface::Interface( int width, int height )
{
	max_width  = width;
	max_height = height;
}

void Interface::init( HANDLE outputHandle, CHAR_INFO* consoleBuffer, COORD gridSize, COORD gridOrigin, SMALL_RECT rectangle )
{
	out 		= outputHandle;
	buffer 		= consoleBuffer;
	size 		= gridSize;
	origin 		= gridOrigin;
	rect 		= rectangle;

	initConsoleGame();
}

void Interface::initConsoleGame()
{
	drawGrid();
}

void Interface::drawGrid()
{
	int x;
	int y;

	for( y = 0; y < size.Y; y++ )
	{
		for( x = 0; x < size.X; x++ )
		{
			buffer[ x + y * max_width ].Char.AsciiChar 			= ' ';
			buffer[ x + y * max_width ].Attributes 				= FOREGROUND_GREEN;
		}
	}

	for( y = 0; y < ( size.Y - 1 ); y++ )
	{
		buffer[ 0 + y * max_width ].Char.AsciiChar					= '|';
		buffer[ 0 + y * max_width ].Attributes						= FOREGROUND_GREEN;
		buffer[ ( size.X - 2 ) + y * max_width ].Char.AsciiChar		= '|';
		buffer[ ( size.X - 2 ) + y * max_width ].Attributes			= FOREGROUND_GREEN;
	}

	for( x = 0; x < ( size.X - 1 ); x++ )
	{
		buffer[ x + 0 * max_width ].Char.AsciiChar					= '=';
		buffer[ x + 0 * max_width ].Attributes						= FOREGROUND_GREEN;
		buffer[ x + ( size.Y - 2 ) ].Char.AsciiChar					= '=';
		buffer[ x + ( size.Y - 2 ) ].Attributes						= FOREGROUND_GREEN;
	}

	WriteConsoleOutput( out, buffer, size, origin, &rect );
}

void Interface::drawChar()
{
	int x;
	int y;

	for( y = 0; y < size.Y; y++ )
	{
		for( x = 0; x < size.X; x++ )
		{
			buffer[ x + y * max_width ].Char.AsciiChar 			= ' ';
			buffer[ x + y * max_width ].Attributes 				= FOREGROUND_GREEN;
		}
	}

	for( y = 0; y < ( size.Y - 1 ); y++ )
	{
		buffer[ 0 + y * max_width ].Char.AsciiChar					= '|';
		buffer[ 0 + y * max_width ].Attributes						= FOREGROUND_GREEN;
		buffer[ ( size.X - 2 ) + y * max_width ].Char.AsciiChar		= '|';
		buffer[ ( size.X - 2 ) + y * max_width ].Attributes			= FOREGROUND_GREEN;
	}

	for( x = 0; x < ( size.X - 1 ); x++ )
	{
		buffer[ x + 0 * max_width ].Char.AsciiChar					= '=';
		buffer[ x + 0 * max_width ].Attributes						= FOREGROUND_GREEN;
		buffer[ x + ( size.Y - 2 ) ].Char.AsciiChar					= '=';
		buffer[ x + ( size.Y - 2 ) ].Attributes						= FOREGROUND_GREEN;
	}

	WriteConsoleOutput( out, buffer, size, origin, &rect );
}
