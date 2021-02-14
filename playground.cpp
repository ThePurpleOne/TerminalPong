#include <iostream>
#include "playground.hpp"



//Constructors
playground::playground(int windowH, int windowW, int windowX, int windowY )
{
	WINDOW * w1 = newwin(windowH, windowW, windowX, windowY);
	f.windowHeight = windowH;
	f.windowWidth = windowW;
	f.windowObject = w1;
}

//Getter Setter
fullWindow playground::getfullWindow()
{
	return f;
}
int playground::getWindowHeight()
{
	return f.windowHeight;
}
int playground::getWindowWidth()
{
	return f.windowWidth;
}
WINDOW * playground::getWindow()
{
	return f.windowObject;
}


//Functions
void playground::collisionTopBot(ball * b)
{
	//Hits the top or bot
	if ( (b->getPosY() < 2) || (b->getPosY() > (getWindowHeight() - 10) )) 
	{
		b->inverseVelX();
		// b.setVelY(-1);
		mvwaddch(getWindow(), 10, 10, 'D');

	}
}
bool playground::collisionLeftWall(ball b)
{
	if(b.getPosX() < 5)
	{
		b.inverseVelX();
		return(true);
	}
	else
	{
		return(false);
	}
}
bool playground::collisionRightWall(ball b)
{
	if(b.getPosX() > getWindowWidth() - 1)
	{
		b.inverseVelX();
		return(true);
	}
	else
	{
		return(false);
	}
}
