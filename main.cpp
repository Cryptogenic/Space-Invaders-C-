#include <windows.h>
#include "headers\Controller.h"

int main()
{
	Controller playerController( 0 );

	playerController.init();

	Sleep(20000); // Debug
	return EXIT_SUCCESS;
}