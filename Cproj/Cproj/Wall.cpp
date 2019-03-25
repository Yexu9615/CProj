#include "Wall.h"
#include <SDL.h>
#include "System.h"
#include "Enemy.h"

#include <SDL_image.h>
#include <vector>
using namespace std;

namespace game {

	
	void Wall::draw() {

	
			
	//	SDL_FreeSurface(surf);
		rect = { getX(), getY(), getWidth(), getHeight() };

		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());

	//	SDL_DestroyTexture(texture);
	}
	
	


}