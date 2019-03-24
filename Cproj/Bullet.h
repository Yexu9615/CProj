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
		int getWidth() { return width; }
		int getHeight() { return height; }

		void moveLeft();
		void moveRight();

		void draw();

		static Bullet* getInstance(int a, int b) { return new Bullet(a, b); };
	protected:

	private:
		int width = 20;
		int height = 20;
		Bullet(int a, int b) :MovingSprite(a, b,20,20) {};

	};

} // cwing

#endif