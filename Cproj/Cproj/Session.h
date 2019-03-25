#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Sprite.h"
#include "MovingSprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Wall.h"

namespace game {

	class Session
	{
	public:
		int getEnemies();
		void initiateBg(int);
		bool forceToQuit=false;
		void initiateSprites(int );
		bool alive = true;
		Session();
		void add(Sprite*);
	//	void addEnemy(Sprite*);
		//void addBullet(Sprite*);
		void run(int level);
		~Session();
	private:
		int chNr;
		int enemies=2;
		Sprite* player;
		SDL_Surface* bgSurf;
		Wall* wall;
	//	std::vector<Sprite*> enemies;
	//	std::vector<Sprite*> bullets;
		std::vector<Sprite*>  removed;

		std::vector<Sprite*> allSprites;
		
		//Sprite* bullet1 = Bullet::getInstance(200, 500);
		
		//Moving* mov2 = Moving::getInstance(0, 150);
	//	Moving* mov3 = Moving::getInstance(0, 350);
	//	Fixed* f = Fixed::getInstance(100, 100);
	//	Fixed* f2 = Fixed::getInstance(100, 230);

	};

} // cwing
#endif