#include "Moving.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>

namespace cwing {

	Moving::Moving(int a, int b)
	{
		x = a; y = b;
	}

	void Moving::moveDown() {
		y += 15;
	}


	void Moving::moveRight() {
		x += 15;
	}
	void Moving::draw() {

		surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/gubbe.bmp");
		Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
		SDL_SetColorKey(surf, true, white);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		//rect = { 0, 0, surf->w, surf->h };
		rect = { x, y, 50, 50 };

		//SDL_RenderCopy(sys.getRen(), upIcon, NULL, &getRect());
		SDL_FreeSurface(surf);
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
		SDL_DestroyTexture(texture);

	}
	Moving::~Moving()
	{

		SDL_DestroyTexture(texture);
	}

}