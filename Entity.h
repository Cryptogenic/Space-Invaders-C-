#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
	int getX();
	int getY();
	int setX( int );
	int setY( int );
	int getCoordinates();
private:
	int x;
	int y;
	int max;
};