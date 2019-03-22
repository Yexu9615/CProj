#include "Player.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>

namespace cwing {

	void Player::moveDown() {
		addY(10);
	}
	void Player::moveUp() {
		addY(-10);
	}
	void Player::moveLeft() {
		addX(-10);
	}
	void Player::moveRight() {
		addX(10);
	}
	void Player::draw() {

		surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/gubbe.bmp");
		Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
		SDL_SetColorKey(surf, true, white);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		rect = { getX(), getY(), 50, 60 };

		SDL_FreeSurface(surf);
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());

		SDL_DestroyTexture(texture);



	}
	

}