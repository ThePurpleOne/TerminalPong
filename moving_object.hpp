#ifndef __MOVING_OBJECT__
#define __MOVING_OBJECT__
#include <curses.h>

class movingObject
{
	private:
		//Attriibuts
		long posX, posY;
		long velX, velY;

		
	public:
		//Variables

		//Properties
		long getPosX();
		void setPosX(long pos);
		long getPosY();
		void setPosY(long pos);
		long getVelX();
		void setVelX(long vel);
		long getVelY();
		void setVelY(long vel);

		//Proto Functions
		void draw();
		void update();
		void inverseVelX();
		void inverseVelY();

		

};

#endif


