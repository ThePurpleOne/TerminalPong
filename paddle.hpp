#ifndef __PADDLE__
#define __PADDLE__
#include <curses.h>
#include "moving_object.hpp"

class paddle : public movingObject
{
	private:
		//Attributes
		int paddleSize = 4;
	public:
		
		//Constructors
		paddle();
		paddle(WINDOW * windowObj, long xPos, long yPos);

		//Getter Setters
		int getPaddleSize();
		void setPaddleSize(int size);

		//Functions
		void draw();

		WINDOW  * currentWindow; 
};

#endif


