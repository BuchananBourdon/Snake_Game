#ifndef SECTION_H
#define SECTION_H

#include <SDL/SDL.h>
#include "MapView.h"

class Section {

	public:
		Section(int, int, int, int, Section*);
		
		int getX();
		int getY();

 		enum direction{
                        UP,
                        DOWN,
                        LEFT,
                        RIGHT,
                };

		Section::direction getDirection();
		void setDirection(Section::direction);

		Section * getPreviousSection();

		void draw(MapView&);
		void update();


	private:
		int x, y;	//location
		int w,h;	//size
		
		static SDL_Surface * sectionSurface;
		static SDL_Rect sectionClips[4];

		void setClips();

		enum direction dir;

		Section * previousSection;
};


#endif
