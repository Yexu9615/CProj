#ifndef ENEMY_H
#define ENEMY_H
#include <SDL.h>
#include "Bullet.h"
using namespace std;
#include <vector>
#include "MovingSprite.h"
namespace cwing {

	class Enemy :public MovingSprite
	{
	public:
		void moveDown();
		void moveUp();
		Bullet* hit(const vector<Sprite*>& sprites);
		
		
		void moveLeft();
		void moveRight();

		void draw();

		static Enemy* getInstance(int a, int b) { return new Enemy(a, b); };
	protected:

	private:
		

		Enemy(int a, int b) :MovingSprite(a, b,50,50) {};

	};

} // cwing

#endif