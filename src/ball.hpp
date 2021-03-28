#ifndef __BALL__
#define __BALL__
#include "global.hpp"
#include <curses.h>
#include "moving_object.hpp"

class ball : public movingObject
{
	private:
		//Attributes

		
	public:
		
		//Constructors
		ball();
		ball(WINDOW * windowObj, long xPos, long yPos);
		
		//Functions
		void draw();

		WINDOW  * currentWindow; 
};

#endif


