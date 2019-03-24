#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
namespace cwing {

	class Sprite
	{
	public:
		int getHeight() const { return height; }

		int getWidth() const { return width; }

		int getX() const { return x; }
		int getY() const { return y; }
		void addX(int a) { x += a; }
		void addY(int a) { y += a; }
		//void setRect()  { return rect; }

		SDL_Rect getRect() const { return rect; }
		SDL_Surface* getSurf()  { return surf; }
	virtual	void setSurf() {}
		SDL_Texture* getTexture()  { return texture; }
	virtual	void setTexture() {}
		virtual ~Sprite() {};
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;

		virtual void draw()=0;
		virtual void moveDown()=0;
		virtual void moveUp() = 0;
		virtual void moveLeft() = 0;
		virtual void moveRight() = 0;

	
	
	protected:
		Sprite(int a, int b,int c,int d) :x(a), y(b) ,width(c),height(d){};
		SDL_Surface* surf;
		SDL_Texture* texture;
		SDL_Rect rect;
	

	private:
		int x;
		int y;
		int height;
		int width;
	
	};

} // cwing

#endif