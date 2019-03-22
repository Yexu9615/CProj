#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Sprite.h"
#include "MovingSprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

namespace cwing {

	class Session
	{
	public:
		Session();
		void add(Sprite*);
	//	void addEnemy(Sprite*);
		void removeBullet(Sprite*);
		//void addBullet(Sprite*);
		void run();
		~Session();
	private:
	//	std::vector<Sprite*> enemies;
	//	std::vector<Sprite*> bullets;
		std::vector<Sprite*> removed;

		std::vector<Sprite*> allSprites;
		Sprite* player = Player::getInstance(300,440);
		Sprite* enemy1 = Enemy::getInstance(0, 0);
		Sprite* enemy2 = Enemy::getInstance(330, 120);
		//Sprite* bullet1 = Bullet::getInstance(200, 500);
		
		//Moving* mov2 = Moving::getInstance(0, 150);
	//	Moving* mov3 = Moving::getInstance(0, 350);
	//	Fixed* f = Fixed::getInstance(100, 100);
	//	Fixed* f2 = Fixed::getInstance(100, 230);

	};

} // cwing
#endif