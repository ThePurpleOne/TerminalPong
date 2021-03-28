#ifndef __PADDLE__
#define __PADDLE__
#include <curses.h>
#include "moving_object.hpp"
#include "ball.hpp"

class paddle : public movingObject
{
	private:
		//Attributes
		int paddleSize = PADDLE_SIZE;
	public:
		
		//Constructors
		paddle();
		paddle(WINDOW * windowObj, long xPos, long yPos);

		//Getter Setters
		int getPaddleSize();
		void setPaddleSize(int size);

		//Functions
		void draw();
		void collisionPaddle(ball * b);
		void moveUp();
		void moveDown();

		WINDOW  * currentWindow; 
};

#endif


