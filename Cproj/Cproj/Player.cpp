#include "Player.h"
#include <SDL.h>
#include "System.h"
#include "Enemy.h"

#include <SDL_image.h>
#include <vector>
using namespace std;

namespace game {
	
	void Player::moveDown() {
		addY(10);
		if (getY() > 430) {
			setY(430);
		}
	}
	void Player::moveUp() {
		addY(-10);
		if (getY() <0) {
			setY(0);
		}

	}
	void Player::moveLeft() {
		addX(-10);

		if (getX() <0) {
			setX(0);
		}
	}
	void Player::moveRight() {
		addX(10);
	
		if (getX() > 630) {
			setX(630);
		}
	}



	void Player::draw() {
		
		if (++counter / 10 % 2 == 0) {

			surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/hero1.bmp");
		}
		else {
			surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/hero0.bmp");
		}

		Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
		SDL_SetColorKey(surf, true, white);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);

		SDL_FreeSurface(surf);
		rect = { getX(), getY(), getWidth(), getHeight() };

		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());

		SDL_DestroyTexture(texture);
	}
	bool Player:: hit(const vector<Sprite*>& sprites){
		for (Sprite* s : sprites) {
			Enemy* e = dynamic_cast<Enemy*>(s);
			if (e) {
			
				int x1 = e->getX() - getWidth();
				int x2 = e->getX() + e->getWidth();
				int y1 = e->getY() - getHeight();
				int y2 = e->getY() + e->getHeight();
				if (getX() > x1 && getX() < x2 && getY() > y1 && getY() < y2) {
					return true;
				}
			}
		}return false;
	}
	

}