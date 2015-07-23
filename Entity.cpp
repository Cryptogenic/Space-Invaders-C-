#include <windows.h>
#include "Entity.h"

Entity::Entity( int width )
{
	x = 0;
	y = 0;
	max = width;
}

int Entity::getX()
{
	return x;
}

int Entity::getY()
{ 
	return y;
}

int Entity::getCoordinates()
{
	return (x + (y * max));
}