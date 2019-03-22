#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Sprite.h"
#include "Moving.h"
#include "Fixed.h"

namespace cwing {

	class Session
	{
	public:
		Session();
		void add(Sprite*);
		void add2(Moving*);
		void add3(Fixed*);

		void run();
		~Session();
	private:
		std::vector<Moving*> allMovings;
		std::vector<Fixed*> allFixed;

		std::vector<Sprite*> allSprites;
		Sprite* player = Sprite::getInstance();
		Moving* mov = Moving::getInstance(0, 0);
		Moving* mov2 = Moving::getInstance(0, 150);
		Moving* mov3 = Moving::getInstance(0, 350);
		Fixed* f = Fixed::getInstance(100, 100);
		Fixed* f2 = Fixed::getInstance(100, 230);

	};

} // cwing
#endif