#include "Session.h"
#include <SDL.h>
#include "System.h"
#include "Bullet.h"

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include "Sprite.h"
#define FPS 60
using namespace std;

namespace cwing {

	Session::Session()
	{
	}
	
	void Session::add(Sprite* s) {


		allSprites.push_back(s);
	}


	void Session::removeBullet(Sprite* s) {

	}
	void Session::run() {
		Sprite* player = Player::getInstance(300, 440);
		Sprite* enemy1 = Enemy::getInstance(0, 0);
		Sprite* enemy2 = Enemy::getInstance(330, 120);
		 alive = true;
		const int tickInterval = 1000 / FPS;

		add(player);
		add(enemy1);
		add(enemy2);
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
		Mix_Chunk* muzak = Mix_LoadWAV("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/bgMusic.wav");
		int volume = 64;
		Mix_Volume(-1, volume);
		int chNr = Mix_PlayChannel(-1, muzak, -1);
		Mix_Chunk* skott = Mix_LoadWAV("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/klick.wav");
		bool paused = false;
	
		bool quit = false;
		int varv = 0;
		int direction = 1;

		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT: quit = true; break;

				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_UP:
						if (alive) 
						{ player->moveUp(); } break;
					case SDLK_DOWN: 
						if (alive)
						{
							player->moveDown();
						} break;
					case SDLK_RIGHT: 
						if (alive) {
							player->moveRight();
						}break;
					case SDLK_LEFT:
						if (alive) {
							player->moveLeft();
						} break;
					case	SDLK_SPACE: 
						if(alive)
					{Sprite* bulletX = Bullet::getInstance(player->getX(), player->getY());
					allSprites.push_back(bulletX); }
						break;//TODO
					case 'm':
						if (paused)
							Mix_Resume(chNr);
						else
							Mix_Pause(chNr);
						paused = !paused;
					} // inre switch
					break;
				}
			} // inre while


			for (Sprite* s : allSprites) {
				Bullet* b = dynamic_cast<Bullet*>(s);
				if (b) {
					if (b->getY() < 0) {
						removed.push_back(b);
					}
				}
				Enemy* e = dynamic_cast<Enemy*>(s);
			
			}
			
	
			if (alive) {
				if (Player* p = dynamic_cast<Player*>(player)) {
					if (p->hit(allSprites)) {
						alive = false;
						removed.push_back(player);
					}
				}
			}

			
		if (enemies > 0) {
			for (Sprite* s : allSprites) {
				if (Enemy* e = dynamic_cast<Enemy*>(s)) {
					Bullet* b = e->hit(allSprites);
					if (b) {
						enemies--;
						removed.push_back(e);
						removed.push_back(b);
					}
				}
			}
		}
			for (Sprite* c : removed) {
				for (vector<Sprite*>::iterator i = allSprites.begin(); i != allSprites.end(); )
					if (*i == c) {
						i = allSprites.erase(i);
						delete c;
					}
					else
						i++;
			}
		
			removed.clear();
			if (enemies == 0) {
				level++;
				enemies = 2;//TODO
				quit = true;
			}

			SDL_RenderClear(sys.getRen());
			SDL_Surface* bgSurf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/bg.bmp");
			SDL_Texture* bgTx = SDL_CreateTextureFromSurface(sys.getRen(), bgSurf);
			SDL_FreeSurface(bgSurf);

			int w, h;
			SDL_QueryTexture(bgTx, NULL, NULL, &w, &h);
			SDL_Rect donkRect = { 0, 0, w, h };
			SDL_RenderCopy(sys.getRen(), bgTx, NULL, &donkRect);


			for (Sprite* c : allSprites)
				c->draw();
			
		
			SDL_RenderPresent(sys.getRen());
			SDL_DestroyTexture(bgTx);
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
			SDL_Delay(delay);
		} // yttre while

	}

	Session::~Session()
	{
		for (Sprite* c : allSprites)
			delete c;
	

	}
} // cwing