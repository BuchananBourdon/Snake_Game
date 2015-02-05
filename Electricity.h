#ifndef ELECTRICITY_H
#define ELECTRICITY_H

#include <SDL/SDL.h>
#include "Animation.h"
#include "MapView.h"

class Electricity : public Animation
{
	public:
		Electricity(int,int,int);

	private:
		static SDL_Surface * electricitySurface;
		static SDL_Rect electricityRect[10]; 
		void draw(MapView&);
		void updateAnimation();
		void setClips();
};


#endif
