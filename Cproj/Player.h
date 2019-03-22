#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>
#include "Sprite.h"
namespace cwing {

	class Player:public Sprite
	{
	public:
		
		void moveDown();
		void moveUp();

		void moveLeft();
		void moveRight();

		void draw();

		static Player* getInstance(int a,int b) { return new Player(a,b); };
	protected:

	private:
	
		Player(int a, int b) :Sprite(a, b) {};
		
	};

} // cwing

#endif