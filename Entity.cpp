#include <windows.h>
#include "Entity.h"

Entity::Entity( int width )
{
	x = 0;
	y = 0;
	max = width;
}

int Entity::getCoordinates()
{
	return (x + (y * max));
}

int Entity::getX()
{
	return x;
}

int Entity::getY()
{ 
	return y;
}

void Entity::setX( int val )
{
	x = val;
}

void Entity::setY( int val )
{
	y = val;
}