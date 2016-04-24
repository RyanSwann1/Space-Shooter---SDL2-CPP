#ifndef SDLDELETER_H
#define SDLDELETER_H

#include <SDL.h>
struct SDLDeleter
{
	void operator()(SDL_Window *p) { SDL_DestroyWindow(p); }
	void operator()(SDL_Renderer *p) {SDL_DestroyRenderer(p); }
	void operator()(SDL_Surface *p) { SDL_FreeSurface(p); }
	void operator()(SDL_Texture *p) { SDL_DestroyTexture(p); }

};
#endif // !SDLDELETR_H