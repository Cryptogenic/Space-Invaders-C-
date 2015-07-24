#include <windows.h>
#include "headers\Controller.h"
#include "headers\Interface.h"
#include "headers\Entity.h"

void Controller::init()
{
	Interface ui;
	Entity enemies( ui.getWidth() );
	Entity player( ui.getWidth() );

	ui.drawGrid(); // Draw game
	ui.drawChar( ( ( ui.getWidth() - 2 ) / 2 ), ( ui.getHeight() - 3 ), '^' ); // Draw Player

	// Draw Enemies
	int x = 0;
	int y = 0;

	for( x = 2; x < ( ui.getWidth() - 4 ); x += 2 )
	{
		for( y = 2; y < ( ui.getHeight() / 2 ); y++ )
		{
			ui.drawChar(x, y, '*');
		}
	}
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