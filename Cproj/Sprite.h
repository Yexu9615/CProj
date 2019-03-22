#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
namespace cwing {

	class Sprite
	{
	public:
		//	virtual void mouseDown(const SDL_Event& event) {}
		//	virtual void mouseUp(const SDL_Event& event) {}
		void moveDown();
		void moveUp();

		void moveLeft();
		void moveRight();

		~Sprite();
		SDL_Rect getRect() const { return rect; }
		void draw();

		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
		static Sprite* getInstance() { return new Sprite(); };
	protected:

	private:
		int x = 200;
		int y = 400;
		Sprite();
		SDL_Rect rect;
		SDL_Surface* surf;
		SDL_Texture* texture;
	};

} // cwing

#endif