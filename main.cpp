#include <windows.h>
#include "Controller.h"
#include "Entity.h"
#include "Interface.h"

#define GAME_WIDTH 	77
#define GAME_HEIGHT 22
#define POS_X 		 1
#define POS_Y 		 1

int main()
{
	Controller playerController( 0 );
	Entity enemies( GAME_WIDTH );
	Entity player( GAME_WIDTH );
	Interface ui( GAME_WIDTH, GAME_HEIGHT );

	playerController.init( enemies, player, ui );

	return EXIT_SUCCESS;
}