#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
	Entity(int max_width = 0);
	int getX();
	int getY();
	int getCoordinates();
	void setX( int val );
	void setY( int val );
private:
	int x;
	int y;
	int max;
};

#endif