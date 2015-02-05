#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include "MapView.h"
#include "Snake.h"
#include "Food.h"
#include "Animation.h"

class Game
{
	public:
		Game();
		~Game();
		void play();
	private:
		int score;
		bool playing;
		void draw();
		bool updateGame();
		void handleEvents();
		void pauseSimulation();
		void updateAnimations();
		void drawAnimations();
		int lastFrame;
		MapView * map;
		Snake * snake;
		Food * food;
		void exit();
		std::list<Animation*> animations;
};

#endif
