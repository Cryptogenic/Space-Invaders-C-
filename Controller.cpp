#include <windows.h>
#include "Controller.h"
#include "Interface.h"
#include "Entity.h"

#define KEY_LEFT	75
#define KEY_RIGHT	77
#define KEY_UP		72

Controller::Controller( int k )
{
	key = k;
}

void Controller::init()
{
	Entity enemies( 77 );
	Entity player( 77 );
	Interface ui;

	ui.drawGrid();
}

// BELOW FUNCTIONS WILL BE THREADED

void Controller::listenKeyPress()
{
	for(;;)
	{
		key = 0;

		if( GetAsyncKeyState( VK_UP ) )
		{
			// shoot
		} else if( GetAsyncKeyState( VK_LEFT ) ) {
			// move char left
		} else if( GetAsyncKeyState( VK_RIGHT ) ) {
			// move char right
		}
		
	}
}

void Controller::listenAttacks()
{
	for(;;)
	{
		// initate attacks on player
	}
}