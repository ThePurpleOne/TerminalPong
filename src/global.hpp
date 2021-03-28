#ifndef __GLOBAL__
#define __GLOBAL__
#include <curses.h>


//DEFINE PARAMETERS
#define GAP_WALL_PADDLE 10
#define PADDLE_SIZE 10

struct fullWindow
{
	int windowHeight, windowWidth;
	WINDOW * windowObject;
};

#endif