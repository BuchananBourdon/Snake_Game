#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "MapView.h"

SDL_Surface * MapView::mapSurface = NULL;
SDL_Rect MapView::mapRect;

MapView::MapView(int _x, int _y, int _w, int _h, int _numberHoriz, int _numberVert) 
	: x(_x), y(_y), tileWidth(_w), tileHeight(_h), horizontalTiles(_numberHoriz), 
	  verticalTiles(_numberVert) { 

	if(mapSurface==NULL)
	{
		SDL_Surface * loadedImage = IMG_Load("GameMap.png");

                SDL_Surface * optimizedImage = SDL_DisplayFormatAlpha(loadedImage);

                SDL_FreeSurface(loadedImage);
                mapSurface = optimizedImage;

		mapRect.x = mapRect.y = 0;
		mapRect.w = 990;
		mapRect.h = 750;
	}


	//tiles = new bool[_numberVert][_numberHoriz];

	for(int i=0; i<verticalTiles; i++)
		for(int j=0; j<horizontalTiles; j++)
			tiles[i][j] = false;

}

MapView::~MapView()
{
	//delete[] tiles;
}

int MapView::getX()
{ 
	return x;
}

int MapView::getY()
{
	return y;
}

int MapView::getTileWidth()
{
	return tileWidth;
}

int MapView::getTileHeight()
{
	return tileHeight;
}

int MapView::getHorizontalTiles()
{
	return horizontalTiles;
}

int MapView::getVerticalTiles()
{
	return verticalTiles;
}

bool MapView::isOccupied(int _x, int _y)
{
	return tiles[_y][_x];
}


void MapView::setOccupancy(int _x, int _y, bool occupancy)
{
	tiles[_y][_x] = occupancy;
}

void MapView::draw()
{
	SDL_Surface * surface = SDL_GetVideoSurface();
	SDL_Rect rect = {x,y,horizontalTiles*tileWidth, verticalTiles*tileHeight};
	SDL_BlitSurface(mapSurface,&mapRect,surface,&rect);
}
