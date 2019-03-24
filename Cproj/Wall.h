#ifndef WALL_H
#define WALL_H
#include <SDL.h>
#include "Sprite.h"
using namespace std;

namespace cwing {

	class Wall :public Sprite
	{
	public:

		void moveDown() {};
		void moveUp() {};

		void moveLeft() {};
		void moveRight() {};
		//bool hit(const vector<Sprite*>& sprites);
		void draw();

		static Wall* getInstance(int a, int b) { return new Wall(a, b); };
	protected:

	private:
	

		Wall(int a, int b) :Sprite(a, b, 680, 10) {

		};
		//Player(int a, int b) :Sprite(a, b) {};

	};

} // cwing

#endif