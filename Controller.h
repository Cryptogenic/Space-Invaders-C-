#include <windows.h>
#include "Entity.h"
#include "Interface.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
	Controller( int k );
	void listenKeyPress();
	void listenAttacks();
	void init( Entity player, Entity enemies, Interface ui );
private:
	int key;
};

#endif