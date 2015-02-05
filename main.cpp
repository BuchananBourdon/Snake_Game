#include <SDL/SDL.h>
#include "Game.h"
#include <iostream>
using namespace std;
int main()
{

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_WM_SetCaption("SNAKE",NULL);

	SDL_SetVideoMode(1300,850,0,0);

	if(!SDL_GetVideoSurface())
	{
		cerr<<"SDL could not inititialize. Exiting."<<endl;
		return 1;
	}



	Game game;
	cout<<"got here"<<endl;


	game.play();

	return 0;
}
