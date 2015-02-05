#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

#include "Section.h"
#include "MapView.h"
using namespace std;
SDL_Surface * Section::sectionSurface = NULL;
SDL_Rect Section::sectionClips[4];


Section::Section(int _x, int _y, int _w, int _h, Section* _pSection)
	: x(_x), y(_y), w(_w), h(_h) { //come back to this.................
	if(sectionSurface==NULL)
	{

		SDL_Surface * loadedImage = IMG_Load("Section.png");

		SDL_Surface * optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		cout<<"in section constructor"<<endl;

		SDL_FreeSurface(loadedImage);
		sectionSurface = optimizedImage;
		setClips();
	}
	previousSection = _pSection;
	if(_pSection) dir = previousSection->getDirection();
	else dir = RIGHT;
}

int Section::getX()
{
	return x;
}

int Section::getY()
{
	return y;
}

Section::direction Section::getDirection()
{
	return dir;
}

void Section::setDirection(Section::direction newDir)
{
	if(!(newDir==LEFT && dir==RIGHT) && !(newDir==RIGHT && dir==LEFT)
                && !(newDir==UP && dir==DOWN) && !(newDir==DOWN && dir==UP))
		dir = newDir;
}

Section* Section::getPreviousSection()
{
	return previousSection;
}

void Section::draw(MapView& map)
{
	SDL_Surface * screen = SDL_GetVideoSurface();
	SDL_Rect rect;
	rect.x = map.getX() + x*map.getTileWidth();
	rect.y = map.getY() + y*map.getTileHeight();
	rect.w = map.getTileWidth();
	rect.h = map.getTileHeight();
	SDL_BlitSurface(sectionSurface,&sectionClips[0],screen,&rect);

}

void Section::update()
{
	if(previousSection) //not the head section
	{
		x = previousSection->getX();
		y = previousSection->getY();
		setDirection(previousSection->getDirection());
	}
	else  //head section
	{
		if(dir==UP) y--;
		else if(dir==DOWN) y++;
		else if(dir==LEFT) x--;
		else if(dir==RIGHT) x++;
	}

}


void Section::setClips()
{
	for(int i=0; i<4; i++)
	{
		sectionClips[i].x = 15*i;
		sectionClips[i].y = 0;
		sectionClips[i].w = 15;
		sectionClips[i].h = 15;
	}
}
