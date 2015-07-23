#include <windows.h>
#include <iostream>

using namespace std;

class model
{
public:
	int getX();
	int getY();
	COORD getSize();
	COORD getOrigin();
	CHAR_INFO getBuffer();
	SMALL_RECT getRect();

	int setX( int );
	int setY( int );
private:
	int x;
	int y;

	COORD gridSize;
	COORD gridOrigin;
	CHAR_INFO screenBuffer;
	SMALL_RECT drawRect;
};

class view
{
public:
	void drawGrid( CHAR_INFO*, COORD );
	void drawEnemies( CHAR_INFO*, COORD );
	void drawPlayer( CHAR_INFO*, COORD );
private:
	void initConsoleGame();
};

class controller
{
public:
	void listenKeyPress();
	void listenAttacks();
private:
	HANDLE outputHandle;
}