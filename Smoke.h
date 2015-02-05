#ifndef SMOKE_H
#define SMOKE_H

#include <SDL/SDL.h>
#include "Animation.h"
#include "MapView.h"

class Smoke : public Animation
{
	public:
		Smoke(int,int,int);

	private:
		static SDL_Surface * smokeSurface;
		static SDL_Rect smokeRect[10]; 
		void draw(MapView&);
		void updateAnimation();
		void setClips();
};

#endif
