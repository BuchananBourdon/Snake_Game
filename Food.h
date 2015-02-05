#ifndef FOOD_H
#define FOOD_H

#include "MapView.h"

class Food 
{
	public:
		Food(MapView&,int);
		~Food();
		void draw(MapView&);
		int getX();
		int getY();
		void setX(int);
		void setY(int);
		void respawn(MapView&);
		int getPoints();

	private:
		int x, y;
		int points;
		static SDL_Surface * foodSurface;
		static SDL_Rect foodRect;
};

#endif
