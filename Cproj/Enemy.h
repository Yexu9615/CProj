#ifndef ENEMY_H
#define ENEMY_H
#include <SDL.h>
#include "MovingSprite.h"
namespace cwing {

	class Enemy :public MovingSprite
	{
	public:
		int width = 50;
		int height = 60;
		void moveDown();
		void moveUp();
		
		void moveLeft();
		void moveRight();

		void draw();

		static Enemy* getInstance(int a, int b) { return new Enemy(a, b); };
	protected:

	private:
		
		Enemy(int a, int b) :MovingSprite(a, b) {};

	};

} // cwing

#endif