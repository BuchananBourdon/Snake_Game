#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <SDL/SDL.h>

class MapView
{
	public:
		MapView(int, int, int, int, int, int);
		~MapView();
		int getTileWidth();
		int getTileHeight();
		int getHorizontalTiles();
		int getVerticalTiles();
		bool isOccupied(int, int);
		void setOccupancy(int, int, bool);
		int getX();
		int getY();
		void draw();

	private:
		int x, y;	//location of map on screen
		int tileWidth;
		int tileHeight;
		int horizontalTiles;
		int verticalTiles;
		bool tiles[100][100];
		static SDL_Surface * mapSurface;
		static SDL_Rect mapRect;
};

#endif
