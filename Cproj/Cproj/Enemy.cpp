#include "Enemy.h"
#include "Bullet.h"

#include <SDL.h>
#include "System.h"

#include <SDL_image.h>
using namespace std;
#include <vector>
namespace game {

	void Enemy::moveDown() {
		addY(10);
	}
	void Enemy::moveUp() {
		addY(-10);
	}
	void Enemy::moveLeft() {
		addX(-2);
	}
	void Enemy::moveRight() {
		addX(2);
	}
	Bullet* Enemy::hit(const vector<Sprite*>& sprites) {
		for (Sprite* s : sprites) {
			Bullet* e = dynamic_cast<Bullet*>(s);
			if (e) {
			
				int x1 = e->getX() - getWidth();
				int x2 = e->getX() + e->getWidth();
				int y1 = e->getY() - getHeight();
				int y2 = e->getY() + e->getHeight();
				if (getX() > x1 && getX() < x2 && getY() > y1 && getY() < y2) {
					return e;
				}
			}
		}return nullptr;
	}

	void Enemy::draw() {
		counter++;
		
		rect = { getX(), getY(), 50, 60 };

		//SDL_FreeSurface(surf);
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());

	//	SDL_DestroyTexture(texture);
		if (direction == 1) {
			moveRight();
		}
		else {
			moveLeft();
		}
		

		if (counter % 100 == 0) {
			direction *= -1;
		}
	}


}