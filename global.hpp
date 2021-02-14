#ifndef __GLOBAL__
#define __GLOBAL__
#include <curses.h>

struct fullWindow
{
	int windowHeight, windowWidth;
	WINDOW * windowObject;
};

#endif