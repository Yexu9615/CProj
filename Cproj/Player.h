#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>
#include "Sprite.h"
using namespace std;
#include <vector>

namespace cwing {

	class Player:public Sprite
	{
	public:
		
		void moveDown();
		void moveUp();
		int width = 50;
		int height = 60;
		void moveLeft();
		void moveRight();
		bool hit(const vector<Sprite*>& x);
		void draw();

		static Player* getInstance(int a,int b) { return new Player(a,b); };
	protected:

	private:
		int mark;
		int counter=0;
		Player(int a, int b);
		//Player(int a, int b) :Sprite(a, b) {};
		
	};

} // cwing

#endif