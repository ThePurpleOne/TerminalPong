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
		long getPosY();
		long getVelX();
		long getVelY();
		void setPosX(long pos);
		void setPosY(long pos);
		void setVelX(long vel);
		void setVelY(long vel);

		//Proto Functions
		void draw();
		void update();
		void inverseVelX();
		void inverseVelY();
};

#endif


