#ifndef MOVING_H
#define MOVING_H
#include <SDL.h>
namespace cwing {

	class Moving
	{
	public:
		//	virtual void mouseDown(const SDL_Event& event) {}
		//	virtual void mouseUp(const SDL_Event& event) {}
		void moveDown();
		void moveRight();

		~Moving();
		SDL_Rect getRect() const { return rect; }
		void draw();

		Moving(const Moving&) = delete;
		const Moving& operator=(const Moving&) = delete;
		static Moving* getInstance(int a, int b) { return new Moving(a, b); };
	protected:

	private:
		int x;
		int y;
		Moving(int a, int b);
		SDL_Rect rect;
		SDL_Surface* surf;
		SDL_Texture* texture;
	};

} // cwing

#endif
