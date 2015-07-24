#include <windows.h>
#include "Entity.h"
#include "Interface.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
	void initBulletEnemy(int x, int y);
	void initBulletPlayer();
	void listenKeyPress();
	void listenAttacks();
	void init();
	void gameOver();
	int score;
private:
	int key;
};

#endif