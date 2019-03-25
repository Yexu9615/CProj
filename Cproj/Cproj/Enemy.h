#ifndef ENEMY_H
#define ENEMY_H
#include <SDL.h>
#include "Bullet.h"
using namespace std;
#include <vector>
#include "MovingSprite.h"
namespace game {

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
		int direction = 1;
		int counter = 0;
		Enemy(int a, int b) :MovingSprite(a, b,50,50) {
			surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/donkey.bmp");
			Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
			SDL_SetColorKey(surf, true, white);
			texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		};
	
	};

} // cwing

#endif