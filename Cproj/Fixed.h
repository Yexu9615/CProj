#ifndef FIXED_H
#define FIXED_H
#include <SDL.h>
namespace cwing {

	class Fixed
	{
	public:
		//	virtual void mouseDown(const SDL_Event& event) {}
		//	virtual void mouseUp(const SDL_Event& event) {}


		~Fixed();
		SDL_Rect getRect() const { return rect; }
		void draw();

		Fixed(const Fixed&) = delete;
		const Fixed& operator=(const Fixed&) = delete;
		static Fixed* getInstance(int a, int b) { return new Fixed(a, b); };
	protected:

	private:
		int x;
		int y;
		Fixed(int a, int b);
		SDL_Rect rect;
		SDL_Surface* surf;
		SDL_Texture* texture;
	};

} // cwing

#endif