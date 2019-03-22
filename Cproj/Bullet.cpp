#include "Bullet.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>

namespace cwing {

	void Bullet::moveDown() {
		addY(10);
	}
	void Bullet::moveUp() {
		addY(-5);
	}
	void Bullet::moveLeft() {
		addX(-10);
	}
	void Bullet::moveRight() {
		addX(10);
	}
	void Bullet::draw() {

		surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/bullet.bmp");
		Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
		SDL_SetColorKey(surf, true, white);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		rect = { getX(), getY(), 20, 20 };

		SDL_FreeSurface(surf);
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());

		SDL_DestroyTexture(texture);



	}


}