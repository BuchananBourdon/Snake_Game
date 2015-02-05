#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Electricity.h"
#include "MapView.h"


SDL_Surface* Electricity::electricitySurface = NULL;
SDL_Rect Electricity::electricityRect[10];

Electricity::Electricity(int _x, int _y, int _maxFrame) : Animation(_x, _y, _maxFrame)
{
	if(electricitySurface==NULL)
	{
		SDL_Surface * loadedImage = IMG_Load("Electricity.png");
		SDL_Surface * optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		SDL_FreeSurface(loadedImage);
		electricitySurface=optimizedImage;

		setClips();
	}
}

void Electricity::setClips()
{
	for(int i=0; i<10; i++)
	{
		electricityRect[i].x = i*60;
		electricityRect[i].y = 0;
		electricityRect[i].h = electricityRect[i].w = 60;
	}
}

void Electricity::updateAnimation()
{
	if(frame > 9)
	{
		frame=0;
		active=false;
	}
}

void Electricity::draw(MapView& map)
{
	if(active)	 //just incase someone doesn't get the memo
	{
		SDL_Surface * screen = SDL_GetVideoSurface();
		SDL_Rect rect;
		rect.x = map.getX() + (x-1)*(map.getTileWidth());
		rect.y = map.getY() + (y-2)*(map.getTileHeight());
		rect.w = rect.h = 60;
		SDL_BlitSurface(electricitySurface,&electricityRect[frame],screen,&rect);
	}
}


