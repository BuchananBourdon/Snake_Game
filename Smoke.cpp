#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Smoke.h"
#include "MapView.h"


SDL_Surface* Smoke::smokeSurface = NULL;
SDL_Rect Smoke::smokeRect[10];

Smoke::Smoke(int _x, int _y, int _maxFrame) : Animation(_x, _y, _maxFrame)
{
	if(smokeSurface==NULL)
	{
		SDL_Surface * loadedImage = IMG_Load("Smoke.png");
		SDL_Surface * optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		SDL_FreeSurface(loadedImage);
		smokeSurface=optimizedImage;

		setClips();
	}
}

void Smoke::setClips()
{
	for(int i=0; i<10; i++)
	{
		smokeRect[i].x = i*45;
		smokeRect[i].y = 0;
		smokeRect[i].h = smokeRect[i].w = 45;
	}
}

void Smoke::updateAnimation()
{
	if(frame > 9)
	{
		frame=0;
		active=false;
	}
}

void Smoke::draw(MapView& map)
{
	if(active)
	{
		SDL_Surface * screen = SDL_GetVideoSurface();
		SDL_Rect rect;
		rect.x = map.getX() + (x-1)*(map.getTileWidth());
		rect.y = map.getY() + (y-2)*(map.getTileHeight());
		rect.w = rect.h = 45;
		SDL_BlitSurface(smokeSurface,&smokeRect[frame],screen,&rect);
	}
}


