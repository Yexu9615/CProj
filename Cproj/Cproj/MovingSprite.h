#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include <SDL.h>
#include "Sprite.h"
namespace game {

	class MovingSprite:public Sprite
	{
	public:
		
	virtual	void moveDown()=0;
	virtual	void moveRight()=0;
	virtual	void moveUp() = 0;
	virtual	void moveLeft() = 0;

		void draw()=0;

		//static MovingSprite* getInstance(int a, int b) { return new MovingSprite(a, b); };
	protected:
		MovingSprite(int a, int b,int c, int d) :Sprite(a, b, c, d) {};

	private:
	
		
	};

} // cwing

#endif
