#include "paddle.hpp"

//Constructor
paddle::paddle()
{

}
paddle::paddle(WINDOW * windowObj, long xPos, long yPos)
{
	currentWindow = windowObj;
	setPosX(xPos);
	setPosY(yPos);
	setVelX(1);
	setVelY(1);
}

//Getter Setter
int paddle::getPaddleSize()
{
	return paddleSize;
}
void paddle::setPaddleSize(int size)
{
	paddleSize = size;
}

//Functions
void paddle::draw() 
{
	for(int i = 0; i < getPaddleSize(); i++)
	{
		mvwaddch(currentWindow, getPosY() + i, getPosX(), '|');
		wrefresh(currentWindow);
	}
}