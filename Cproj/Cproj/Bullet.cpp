#include "Bullet.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>

namespace game {

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
		rect = { getX(), getY(), 20, 20 };

		//SDL_FreeSurface(surf);
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());

	//	SDL_DestroyTexture(texture);
		moveUp();



	}


}