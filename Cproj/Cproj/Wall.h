#ifndef WALL_H
#define WALL_H
#include <SDL.h>
#include "Sprite.h"
#include "System.h"

using namespace std;

namespace game {

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
			surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/wall.bmp");



			texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);

		};
		//Player(int a, int b) :Sprite(a, b) {};

	};

} // cwing

#endif