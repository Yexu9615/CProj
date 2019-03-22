#include "Player.h"
#include <SDL.h>
#include "System.h"
#include "Enemy.h"

#include <SDL_image.h>
#include <vector>
using namespace std;

namespace cwing {
	Player::Player(int a, int b) :Sprite(a, b) {

	};
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
		
		if (++counter / 10 % 2 == 0) {

			surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/hero1.bmp");
		}
		else {
			surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/hero0.bmp");
		}

		Uint32 black = SDL_MapRGB(surf->format, 0, 0, 0);
		SDL_SetColorKey(surf, true, black);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);

		SDL_FreeSurface(surf);
		rect = { getX(), getY(), width, height };

		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());

		SDL_DestroyTexture(texture);
	}
	bool Player:: hit(const vector<Sprite*>& sprites){
		for (Sprite* s : sprites) {
			Enemy* e = dynamic_cast<Enemy*>(s);
			if (e) {
			/*	int x1 = e->getX() - width / 2;
				int x2 = e->getX() +  e->width + width / 2;
				int y1 = e->getY() - height / 2;
				int y2 = e->getY() + e->height + height / 2;
				int x = this->getX() + width / 2;
				int y = this->getY() + height / 2;*/

				int x1 = e->getX() - width;
				int x2 = e->getX() + e->width;
				int y1 = e->getY() - height;
				int y2 = e->getY() + e->height;
				if (getX() > x1 && getX() < x2 && getY() > y1 && getY() < y2) {
					return true;
				}
			}
		}return false;
	}
	

}