#include <iostream> // debugging
#include <windows.h>
#include "Interface.h"

#define GAME_WIDTH 	77
#define GAME_HEIGHT 22
#define POS_X 		 1
#define POS_Y 		 1

using namespace std;

struct GameCore
{
	COORD size;
	COORD origin;
	HANDLE outStream;
	SMALL_RECT drawRect;
	CHAR_INFO buffer[ GAME_WIDTH * GAME_HEIGHT ];
};

GameCore Core;

Interface::Interface()
{
	Core.outStream 	= GetStdHandle( STD_OUTPUT_HANDLE );
	Core.size 		= { GAME_WIDTH, GAME_HEIGHT };
	Core.origin 	= { 0, 0 };
	Core.drawRect 	= { POS_X, POS_Y, POS_X * ( GAME_WIDTH - 1 ), POS_Y * ( GAME_HEIGHT - 1 ) };
}

void Interface::drawGrid()
{
	int x;
	int y;

	for( y = 0; y < Core.size.Y; y++ )
	{
		for( x = 0; x < Core.size.X; x++ )
		{
			Core.buffer[ x + y * GAME_WIDTH ].Char.AsciiChar 			= ' ';
			Core.buffer[ x + y * GAME_WIDTH ].Attributes 				= FOREGROUND_GREEN;
		}
	}

	for( y = 0; y < ( Core.size.Y - 1 ); y++ )
	{
		Core.buffer[ 0 + y * GAME_WIDTH ].Char.AsciiChar					= '|';
		Core.buffer[ 0 + y * GAME_WIDTH ].Attributes						= FOREGROUND_GREEN;
		Core.buffer[ ( Core.size.X - 2 ) + y * GAME_WIDTH ].Char.AsciiChar		= '|';
		Core.buffer[ ( Core.size.X - 2 ) + y * GAME_WIDTH ].Attributes			= FOREGROUND_GREEN;
	}

	for( x = 0; x < ( Core.size.X - 1 ); x++ )
	{
		Core.buffer[ x + 0 * GAME_WIDTH ].Char.AsciiChar					= '=';
		Core.buffer[ x + 0 * GAME_WIDTH ].Attributes						= FOREGROUND_GREEN;
		Core.buffer[ x + ( Core.size.Y - 2 ) * GAME_WIDTH ].Char.AsciiChar		= '=';
		Core.buffer[ x + ( Core.size.Y - 2 ) ].Attributes						= FOREGROUND_GREEN;
	}

	WriteConsoleOutput( Core.outStream, Core.buffer, Core.size, Core.origin, &Core.drawRect );
}

void Interface::drawChar()
{
	int x;
	int y;

	cout << "." << endl;
}
