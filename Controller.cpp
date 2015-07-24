#include <thread>
#include <iostream>
#include <windows.h>
#include "headers\Controller.h"
#include "headers\Interface.h"
#include "headers\Entity.h"

using namespace std;

Interface ui;
Entity enemies( ui.getWidth() );
Entity player( ui.getWidth() );

bool over = false;

void Controller::init()
{
	ui.drawGrid(); // Draw game
	int pos = ui.drawChar( ( ( ui.getWidth() - 2 ) / 2 ), ( ui.getHeight() - 3 ), '^', 'x' ); // Draw Player and get coorindates

	// Draw Enemies
	int x = 0;
	int y = 0;

	for( x = 2; x < ( ui.getWidth() - 4 ); x += 2 )
	{
		for( y = 2; y < ( ui.getHeight() / 2 ); y++ )
		{
			int enemy = ui.drawChar( x, y, '*', 'x' );
		}
	}

	player.setX( pos );
	player.setY( ( ui.getHeight() - 3 ) );

	thread t1( &Controller::listenKeyPress, this );
	t1.detach();

	thread t2( &Controller::listenAttacks, this );
	t2.join();
}

void Controller::listenKeyPress()
{
	for(;;)
	{
		if( GetAsyncKeyState( VK_UP ) )
		{
			thread t3( &Controller::initBulletPlayer, this );
			t3.detach();
			for(;;)
			{
				if( !GetAsyncKeyState( VK_UP ) )
				{
					Sleep( 75 );
					break; // prevents holding key down to cheat
				}
			}
		} else if( GetAsyncKeyState( VK_LEFT ) ) {
			if( player.getX() - 1 > 1 )
			{
				int previous = ui.drawChar( player.getX(), player.getY(), ' ', 'x' );
				int newpos   = ui.drawChar( ( player.getX() - 1 ), player.getY(), '^', 'x' );
				player.setX( newpos );
			}
		} else if( GetAsyncKeyState( VK_RIGHT ) ) {
			if( ( player.getX() + 1 ) < ( ui.getWidth() - 4 ) )
			{
				int previous = ui.drawChar( player.getX(), player.getY(), ' ', 'x' );
				int newpos   = ui.drawChar( ( player.getX() + 1 ), player.getY(), '^', 'x' );
				player.setX( newpos );
			}
		}
		Sleep( 100 );

		if( over )
		{
			break;
		}
	}
}

void Controller::listenAttacks()
{
	Sleep(5000);

	int x;
	int y;
	int t;

	for(;;)
	{
		x = rand() % ( ui.getWidth() - 4 ) + 2;
		y = rand() % ( ( ui.getHeight() / 2) - 2 );
		t = rand() % ( 2500 ) + 100;

		initBulletEnemy( x, y );
		Sleep(t);

		if( over )
		{
			break;
		}
	}
}

void Controller::initBulletPlayer()
{
	Entity bullet( ui.getWidth() );
	bullet.setX( player.getX() );
	bullet.setY( ( player.getY() - 1) );

	while( bullet.getY() > 1 && ui.checkChar( bullet.getX(), ( bullet.getY() - 1 ) ) != '*' )
	{
		int previous = ui.drawChar( bullet.getX(), bullet.getY(), ' ', 'y' );
		int newpos   = ui.drawChar( bullet.getX(), ( bullet.getY() - 1 ), '|', 'y' );
		bullet.setY( newpos );
		Sleep( 75 );
	}
	int finalA = ui.drawChar( bullet.getX(), bullet.getY(), ' ', 'y' );
	if( ui.checkChar( bullet.getX(), ( bullet.getY() - 1 ) ) == '*' )
	{
		int finalB = ui.drawChar( bullet.getX(), ( bullet.getY() - 1 ), ' ', 'y' );
		score += 10;
	}
}

void Controller::initBulletEnemy( int x, int y)
{
	Entity bullet( ui.getWidth() );
	bullet.setX( x );
	bullet.setY( ( y + 1) );

	while( bullet.getY() < ( ui.getHeight() - 3 ) && ui.checkChar( bullet.getX(), ( bullet.getY() + 1 ) ) != '*' )
	{
		if( ui.checkChar( bullet.getX(), ( bullet.getY() + 1 ) ) != '*' )
		{
			int previous = ui.drawChar( bullet.getX(), bullet.getY(), ' ', 'y' );
		}

		if( ui.checkChar( bullet.getX(), ( bullet.getY() + 1 ) ) == '^' )
		{
			gameOver();
			break;
		}

		int newpos   = ui.drawChar( bullet.getX(), ( bullet.getY() + 1 ), '|', 'y' );
		bullet.setY( newpos );
		Sleep( 75 );
	}
	int final = ui.drawChar( bullet.getX(), bullet.getY(), ' ', 'y' );
}

void Controller::gameOver()
{
	int q;
	cout << "G A M E  O V E R. FINAL SCORE: " << score << endl;
	over = true;
}