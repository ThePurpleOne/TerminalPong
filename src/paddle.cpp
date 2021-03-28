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
	//clear the column
	for (int i = 1; i < 49; i++) //HARD CODED CAUSE NOT GIVEN YET, EWW (height of win)
	{
		mvwaddch(currentWindow, i, getPosX(), ' '); 
		wrefresh(currentWindow);
	}

	//draw paddle
	for(int i = 0; i < getPaddleSize(); i++)
	{
		mvwaddch(currentWindow, getPosY() + i, getPosX(), '|');
		wrefresh(currentWindow);
	}

	
}

void paddle::collisionPaddle(ball * b)
{
	int ballxPos = b->getPosX();
	int ballyPos = b->getPosY();
	int ballxVel = b->getVelX();
	int ballyVel = b->getVelY();

	if(ballxPos == getPosX() - 1 && (ballxVel == 1) ) //LEFT side of the Paddle
	{
		if( (ballyPos >= getPosY()) && (ballyPos <= (getPosY() + PADDLE_SIZE) )) //Hits the paddle on a valid Y posiiton
		{	
			//Reverse x axis velocity
			b->inverseVelX();

			//Adapt the angle https://www.instructables.com/Pong-With-Processing/
			//ballStruct->vY = ballStruct->y - padStruct->y;
		}
	}
	else if(ballxPos== getPosX() + 1 && (ballxVel == -1) )//RIGHT side of the paddle
	{
		if( (ballyPos >= getPosY()) && (ballyPos <= (getPosY() + PADDLE_SIZE))) //Hits the paddle on a valid Y posiiton
		{
			//Reverse x axis velocity
			b->inverseVelX();
		}
	}

}

void paddle::moveUp()
{
 	setPosY(getPosY() - 1);
}
void paddle::moveDown()
{
	setPosY(getPosY() + 1);
}