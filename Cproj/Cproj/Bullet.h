#ifndef BULLET_H
#define BULLET_H
#include <SDL.h>
#include "MovingSprite.h"
#include "System.h"

namespace game {

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
		Bullet(int a, int b) :MovingSprite(a, b,20,20) {
			surf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/bullet.bmp");

			Uint32 white = SDL_MapRGB(surf->format, 255, 255, 255);
			SDL_SetColorKey(surf, true, white);
			texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);

		};

	};

} // cwing

#endif