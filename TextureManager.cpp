#include "TextureManager.h"
#include "SDLDeleter.h"
#include "Game.h"
#include <assert.h>
#include <SDL_image.h>
#include "SDL_Surface.h"
#include "SDL2-2.0.4\include\SDL_surface.h"

TextureManager * TextureManager::sm_instance = nullptr;

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}


TextureManager * TextureManager::instance()
{
	if (sm_instance == nullptr) {
		sm_instance = new TextureManager();
	}
	return sm_instance;
}

void TextureManager::draw(float x, float y, int w, int h, const std::string & textureID)
{
	SDL_Texture *texture = m_textures[textureID];

	int texW, texH;
	SDL_QueryTexture(texture, nullptr, nullptr, &texW, &texH);

	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = texW;
	srcRect.h = texH;

	SDL_Rect dstRect;
	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = w;
	dstRect.h = h;

	SDL_RenderCopy(Game::instance()->getRenderer(), texture, &srcRect, &dstRect);
}

void TextureManager::load(const std::string& textureID, std::string path)
{
	//std::unique_ptr<SDL_Surface, SDLDeleter> loadedSurface(IMG_Load(path.c_str()), SDLDeleter());
	//assert(loadedSurface != nullptr);
	//std::unique_ptr<SDL_Surface, SDLDeleter> optimizedSuface(SDL_ConvertSurface(loadedSurface.get(), Game::instance()->getWindowSurface()->format, 0));
	//assert(optimizedSuface != nullptr);
	//std::unique_ptr<SDL_Texture, SDLDeleter> loadedTexture(SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), optimizedSuface.get()));
	//assert(loadedTexture != nullptr);
	//std::unique_ptr<SDL_Surface, SDLDeleter> loadedSurface(IMG_Load(path.c_str()), SDLDeleter());
	//assert(loadedSurface != nullptr);
	//std::unique_ptr<SDL_Surface, SDLDeleter> optimizedSurface(SDL_ConvertSurface(loadedSurface.get(), Game::instance()->getWindowSurface()->format, 0), SDLDeleter());
	//assert(optimizedSurface != nullptr);
	//std::unique_ptr<SDL_Texture, SDLDeleter> loadedTexture(SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), optimizedSurface.get()), SDLDeleter());
	//assert(loadedTexture != nullptr);
	//std::unique_ptr<SDL_Surface, SDLDeleter> loadedSurface(IMG_Load(path.c_str()), SDLDeleter());
	//assert(loadedSurface != nullptr);
	//SDL_Surface* optimizedSurface = SDL_ConvertSurface(loadedSurface.get(), Game::instance()->getWindowSurface()->format, 0);
	////std::unique_ptr<SDL_Surface, SDLDeleter> optimizedSurface(SDL_ConvertSurface(loadedSurface.get(), Game::instance()->getWindowSurface()->format, 0), SDLDeleter());
	//assert(optimizedSurface != nullptr);
	//std::unique_ptr<SDL_Texture, SDLDeleter> loadedTexture(SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), optimizedSurface), SDLDeleter());
	//assert(loadedTexture != nullptr);

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	SDL_Surface* optimizedSurface = SDL_ConvertSurface(loadedSurface, Game::instance()->getWindowSurface()->format, 0);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), optimizedSurface);


	m_textures[textureID] = texture;
}
//
//SDL_Surface* TextureManager::loadSurface(const std::string& path)
//{
//
//
//	return optimizedSurface;
//}
//
//SDL_Texture * TextureManager::loadTexture(const std::string & path)
//{
//
//	return loadedTexture.get();
//}


