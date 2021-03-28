#include <iostream>
#include <string>
#include <curses.h>
#include <unistd.h> //delay 
#include "global.hpp"
#include "moving_object.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "playground.hpp"

using namespace std;

int main()
{
	
	//INIT CURSES
	initscr();
	noecho();
	curs_set(0);

	//CREATE PLAYGROUND + window parameters variables
	playground pl1 = playground(50, 200, 0, 0);
	WINDOW * mainWin1 = pl1.getWindow();
	fullWindow mainFullWindow1 = pl1.getfullWindow();
	long windowHeight = pl1.getWindowHeight();
	long windowWidth = pl1.getWindowWidth();

	box(mainWin1, 0, 0); //Draw window
	wrefresh(mainWin1);  //refresh window

	//Objects creation - base positions
	ball b1 = ball(mainWin1, windowWidth / 2, windowHeight / 2);
	paddle p1 = paddle(mainWin1, GAP_WALL_PADDLE, windowHeight / 2);
	paddle p2 = paddle(mainWin1, windowWidth - GAP_WALL_PADDLE, windowHeight / 2);

	box(mainWin1, 0, 0); //draw the playground (window object)
	wrefresh(mainWin1);

	while(true)
	{

		// DEBUG
		char * text;
		sprintf(text, "Pos x: %li    Pos y: %li", b1.getPosX(), b1.getPosY());
		mvwprintw(mainWin1, 1, 1, text);
		sprintf(text, "Vel x: %li    Vel y: %li   ", b1.getVelX(), b1.getVelY());
		mvwprintw(mainWin1, 2, 1, text);
		sprintf(text, "Window Width : %i    Window Height: %i", pl1.getWindowWidth(), pl1.getWindowHeight());
		mvwprintw(mainWin1, 3, 1, text);
		
		// HANDLE USER INPUTS
		keypad(mainWin1, true); //makin' KEY_UP n'all possible 
		nodelay(mainWin1, TRUE);//Make wgetch non blocking

		int car = wgetch(mainWin1);
		switch (car)
		{
			case KEY_UP:
				if(p2.getPosY() > 1 )
				{
					p2.moveUp();
				}
				break;

			case KEY_DOWN:
				if(p2.getPosY() < (windowHeight - p2.getPaddleSize() - 1 ) )
				{
					p2.moveDown();
				}
				break;
				
			default:
				break;
		}
		wrefresh(mainWin1);

		//Check for ball collisions with every walls and paddles
		pl1.collisionTopBot(&b1);
		pl1.collisionLeftWall(&b1);
		pl1.collisionRightWall(&b1);
		p1.collisionPaddle(&b1);
		p2.collisionPaddle(&b1);

		b1.update();

		b1.draw();
		p1.draw();
		p2.draw();

		// sleep(1);
		usleep(30000);
	}

	getch();
	endwin();


	return 0;
}