#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <iostream>

#include "Game.h"
#include "MapView.h"
#include "Snake.h"
#include "Food.h"
#include "Section.h"
#include "Animation.h"
#include "Smoke.h"
#include "FloatingText.h"
#include "Electricity.h"

using namespace std;

Game::Game() : score(0), lastFrame(0)
{
	map = new MapView(150,50, 15,15,66,50);
	snake = new Snake(10,10,*map);
	food = new Food(*map,10);
}

Game::~Game()
{
	delete map;
	delete snake;
	delete food;

	SDL_FreeSurface(SDL_GetVideoSurface());
}

void Game::draw()
{
	// Clear the screen for consistency
	SDL_Surface *surface = SDL_GetVideoSurface();
	SDL_Rect rect = {0, 0, (Uint16) surface->w, (Uint16) surface->h};
	SDL_FillRect(surface,&rect,SDL_MapRGB(surface->format,30,30,30));

	map->draw();
	snake->draw(*map);
	food->draw(*map);

	drawAnimations();

	SDL_Flip(SDL_GetVideoSurface());
}


void Game::drawAnimations()
{
	for(std::list<Animation*>::iterator i = animations.begin();
		i!=animations.end(); i++)
	{
		Animation * animation = *i;
		animation->draw(*map);
	}
}

void Game::updateAnimations()
{
	for(std::list<Animation*>::iterator i=animations.begin();
		i!=animations.end(); )
	{
		Animation * animation = *i;
		if(animation->isActive())
		{
			animation->update();
			i++;
		}
		else
		{
			i = animations.erase(i);
		}
	}
}

void Game::handleEvents()
{
	SDL_PumpEvents();

	SDL_Event event;
	SDL_PollEvent(&event); 
	
		if(event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym) {
			
			case SDLK_UP: 
				snake->setDirection(Section::UP);
				break;

			case SDLK_DOWN: 
				snake->setDirection(Section::DOWN);
				break;

			case SDLK_LEFT: 
				snake->setDirection(Section::LEFT);
				break;

			case SDLK_RIGHT: 
				snake->setDirection(Section::RIGHT);
				break;

			default: break;
			}
		}
	
}

bool Game::updateGame()
{
	if(!snake->move(*map)) 
	{
		playing = false;
		Animation * newAnimation = new Smoke(snake->getX(),snake->getY(),10);
		animations.push_back(newAnimation);
		newAnimation = new Electricity(snake->getX(),snake->getY(),10);
		animations.push_back(newAnimation);
		return false;
	}
	if(snake->eatFood(*food))
	{
		Animation * newAnimation = new FloatingText(food->getX(),food->getY(),12);
		animations.push_back(newAnimation);
		score+=food->getPoints();
		food->respawn(*map);
	}
	updateAnimations();
	return true;
}

void Game::pauseSimulation()
{
	if(SDL_GetTicks() - lastFrame < 50)
		SDL_Delay(50-(SDL_GetTicks()-lastFrame));
	lastFrame = SDL_GetTicks();
}

void Game::play()
{
	playing=true;
	while(playing)
	{
		//check user input for change in direction
		handleEvents();
						cout<<"In game play and playing is: "<<playing<<endl;

		if(!updateGame()) continue;
						cout<<"In game play and playing is: "<<playing<<endl;


		draw();
		pauseSimulation();	
	}
	while(animations.size()>0)
	{
		
		updateAnimations();
		draw();
		pauseSimulation();
	}

}
