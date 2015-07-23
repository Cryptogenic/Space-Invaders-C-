#include <windows.h>
#include "Controller.h"
#include "Entity.h"
#include "Interface.h"

int main()
{
	Controller playerController( 0 );

	playerController.init();

	Sleep(20000); // Debug
	return EXIT_SUCCESS;
}