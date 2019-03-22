#ifndef BULLET_H
#define BULLET_H
#include <SDL.h>
#include "MovingSprite.h"
namespace cwing {

	class Bullet :public MovingSprite
	{
	public:

		void moveDown();
		void moveUp();

		void moveLeft();
		void moveRight();

		void draw();

		static Bullet* getInstance(int a, int b) { return new Bullet(a, b); };
	protected:

	private:

		Bullet(int a, int b) :MovingSprite(a, b) {};

	};

} // cwing

#endif