#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "FloatingText.h"
#include "MapView.h"

SDL_Surface* FloatingText::textSurface = NULL;
SDL_Rect FloatingText::textRect[12];

FloatingText::FloatingText(int _x, int _y, int _maxFrames)
	: Animation(_x,_y,_maxFrames)
{
	if(textSurface==NULL)
	{
		SDL_Surface * loadedImage = IMG_Load("PlusPoints.png");
		SDL_Surface * optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		SDL_FreeSurface(loadedImage);
		textSurface = optimizedImage;

		setClips();
	}
}

void FloatingText::updateAnimation()
{
	if(frame>=12)
	{
		frame=0;
		active=false;
	}
}

void FloatingText::draw(MapView& map)
{
	if(active)
	{
	SDL_Surface * screen = SDL_GetVideoSurface();
	SDL_Rect rect;
	rect.x = map.getX() + (x-2)*(map.getTileWidth());
	rect.y = map.getY() + (y-3)*(map.getTileHeight()) - frame*7;
	rect.w = 75;
	rect.h = 45;
	SDL_BlitSurface(textSurface,&textRect[frame],screen,&rect);
	}
}

void FloatingText::setClips()
{
	for(int i=0; i<12; i++)
	{
		textRect[i].x = 75*i;
		textRect[i].y = 0;
		textRect[i].w = 75;
		textRect[i].h = 45;
	}
}
