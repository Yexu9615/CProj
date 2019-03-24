#include "Wall.h"
#include <SDL.h>
#include "System.h"
#include "Enemy.h"

#include <SDL_image.h>
#include <vector>
using namespace std;

namespace cwing {

	
	void Wall::draw() {

	
			surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/wall.bmp");
	

	//	Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
	//	SDL_SetColorKey(surf, true, white);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);

		SDL_FreeSurface(surf);
		rect = { getX(), getY(), getWidth(), getHeight() };

		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());

		SDL_DestroyTexture(texture);
	}
	
	


}