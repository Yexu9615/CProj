#include <SDL.h>
#include "Session.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
using namespace std;
using namespace game;

#define FPS 60

int main(int argc, char** argv) {
	
	Session ses;


		ses.run(1);
		if (ses.alive&&!ses.forceToQuit) {
			ses.run(2);

		}
		if (ses.alive&&!ses.forceToQuit) {
			ses.run(3);

		}
	//}


	return 0;

}