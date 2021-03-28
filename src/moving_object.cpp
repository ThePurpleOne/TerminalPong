#include "moving_object.hpp"

//Setters and getters
void movingObject::setPosX(long pos){posX = pos;}
void movingObject::setPosY(long pos){posY = pos;}
void movingObject::setVelX(long vel){velX = vel;}
void movingObject::setVelY(long vel){velY = vel;}
long movingObject::getPosX(){return posX;}
long movingObject::getPosY(){return posY;}
long movingObject::getVelX(){return velX;}
long movingObject::getVelY(){return velY;}

//Functions
void movingObject::draw()
{
	
}

void movingObject::update()
{
	setPosX(getPosX() + getVelX());
	setPosY(getPosY() + getVelY());
}
void movingObject::inverseVelX()
{
	setVelX(getVelX() * -1);
	// velX = -1;

}
void movingObject::inverseVelY()
{
	setVelY(getVelY() * -1);
}
