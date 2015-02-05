#include <SDL/SDL.h>
#include "Animation.h"

Animation::Animation(int _x, int _y, int _maxFrame)
	  : x(_x), y(_y), frame(0), maxFrame(_maxFrame), active(true) 
{}

int Animation::getX()
{
	return x;
}

int Animation::getY()
{
	return y;
}

bool Animation::isActive()
{
	return active;
}

void Animation::update()
{
	frame++;
	this->updateAnimation();
}

