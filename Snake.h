#ifndef SNAKE_H
#define SNAKE_H

#include "Section.h"
#include "MapView.h"
#include "Food.h"

class Snake
{
	public:
		Snake(int,int, MapView&);
		~Snake();
		bool move(MapView&);
		void draw(MapView&);
		void setDirection(Section::direction);
		bool isIntersection(MapView&);
		bool isWithinBounds(MapView&);
		bool eatFood(Food&);
		int getX();
		int getY();

	private:
		Section * headSection;
		Section * tailSection;
		
		int unspawnedSections;
		void addSection(int, int);
};


#endif
