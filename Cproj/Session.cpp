#include "Session.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>

namespace cwing {

	Session::Session()
	{
	}

	void Session::add(Sprite* s) {
		allSprites.push_back(s);
	}
	void Session::add2(Moving* s) {
		allMovings.push_back(s);
	}
	void Session::add3(Fixed* s) {
		allFixed.push_back(s);
	}
	void Session::run() {
		add(player);
		add2(mov);
		add2(mov2);
		add2(mov3);
		add3(f);
		add3(f2);
		bool quit = false;

		while (!quit) {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT: quit = true; break;

				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_UP: player->moveUp(); break;
					case SDLK_DOWN: player->moveDown(); break;
					case SDLK_RIGHT: player->moveRight(); break;
					case SDLK_LEFT: player->moveLeft(); break;
					} // inre switch
					break;

				}
			} // inre while
			for (Moving* c : allMovings)
				c->moveRight();
			SDL_RenderClear(sys.getRen());
			//\\GOOFY2\HT17\yexu9615\Desktop\2019-03-12 C++\images
			SDL_Surface* bgSurf = SDL_LoadBMP("//GOOFY2/HT17/yexu9615/Desktop/2019-03-12 C++/images/bg.bmp");
			SDL_Texture* bgTx = SDL_CreateTextureFromSurface(sys.getRen(), bgSurf);
			SDL_FreeSurface(bgSurf);

			int w, h;
			SDL_QueryTexture(bgTx, NULL, NULL, &w, &h);
			SDL_Rect donkRect = { 0, 0, w, h };
			SDL_RenderCopy(sys.getRen(), bgTx, NULL, &donkRect);

			for (Sprite* c : allSprites)
				c->draw();
			for (Moving* c : allMovings)
				c->draw();
			for (Fixed* c : allFixed)
				c->draw();
			SDL_RenderPresent(sys.getRen());
			SDL_DestroyTexture(bgTx);

		} // yttre while

	}

	Session::~Session()
	{
		for (Sprite* c : allSprites)
			delete c;
	}
} // cwing