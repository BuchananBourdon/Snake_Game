#ifndef FLOATINGTEXT_H
#define FLOATINGTEXT_H

#include <SDL/SDL.h>
#include "MapView.h"
#include "Animation.h"

class FloatingText : public Animation
{
	public:
		FloatingText(int,int,int);

	private:
		static SDL_Surface * textSurface;
		static SDL_Rect textRect[12];
		void draw(MapView&);
		void updateAnimation();
		void setClips();
};


#endif
