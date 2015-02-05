#ifndef ANIMATION_H
#define ANIMATION_H

#include "MapView.h"

class Animation
{
	public:
		Animation(int,int,int);
		virtual void draw(MapView&) = 0;
		int getX();
		int getY();
		bool isActive();
		void update();

	protected:
		int x, y;
		int frame;
		int maxFrame;
		bool active;

	private:
		virtual void updateAnimation() = 0;
};

#endif
