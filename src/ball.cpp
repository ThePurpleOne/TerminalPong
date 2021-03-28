#include "ball.hpp"

//Constructor
ball::ball()
{

}
ball::ball(WINDOW * windowObj, long xPos, long yPos)
{
	currentWindow = windowObj;
	setPosX(xPos);
	setPosY(yPos);
	setVelX(1);
	setVelY(1);
}


void ball::draw() 
{
	//clear the old one
	mvwaddch(currentWindow, getPosY() - getVelY(), getPosX() - getVelX(), ' ');

	//draw the new
	mvwaddch(currentWindow, getPosY(), getPosX(), 'O');
	wrefresh(currentWindow);
}