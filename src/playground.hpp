#ifndef __PLAYGROUND__
#define __PLAYGROUND__
#include <curses.h>
#include "global.hpp"
#include "ball.hpp"
#include "paddle.hpp"


class playground
{
private:
	fullWindow f;	//create struct instance 
	
public:

	//Constructors
	playground(int windowH, int windowW, int windowX, int windowY);

	//Getter Setter
	fullWindow getfullWindow();
	int getWindowHeight();
	int getWindowWidth();
	WINDOW * getWindow();

	//Functions
	void collisionTopBot(ball * b);
	bool collisionLeftWall(ball * b);
	bool collisionRightWall(ball * b);

};

#endif
