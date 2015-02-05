#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "MapView.h"
#include "Food.h"
#include <time.h>

SDL_Surface* Food::foodSurface = NULL;
SDL_Rect Food::foodRect;

Food::Food(MapView& map, int _points) :  x(5), y(5), points(_points)
{
	if(foodSurface == NULL) {
		SDL_Surface * loadedImage = IMG_Load("Food.png");
		SDL_Surface * optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
		SDL_FreeSurface(loadedImage);
		foodSurface = optimizedImage;

		respawn(map);
	}

	foodRect.x = 0;
	foodRect.y = 0;
	foodRect.w = 50;
	foodRect.h = 50;
}

Food::~Food() 
{
	// SDL_FreeSurface(foodSurface);
}

int Food::getPoints()
{
	return points;
}

int Food::getX()
{
	return x;
}

int Food::getY()
{
	return y;
}

void Food::setX(int _x)
{
	x = _x;
}

void Food::setY(int _y)
{
	y = _y;
}

void Food::respawn(MapView& map)
{

	int foodX = x;
        int foodY = y;
        while(map.isOccupied(foodX,foodY))
        {
		srand(time(NULL));
                foodX=rand()%(map.getHorizontalTiles()-1)+1;
                foodY=rand()%(map.getVerticalTiles()-1)+1;
        }
	x=foodX;
	y=foodY;
}


void Food::draw(MapView& map)
{
	SDL_Surface * screen = SDL_GetVideoSurface();
	SDL_Rect rect;
	rect.x = map.getX() + x*map.getTileWidth();
	rect.y = map.getY() + y*map.getTileHeight();
	rect.w = map.getTileWidth();
	rect.h = map.getTileHeight();
	SDL_BlitSurface(foodSurface,&foodRect,screen,&rect);
}
