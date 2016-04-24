#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "SDLDeleter.h"
#include <SDL.h>
#include <memory>
#include <string>
#include <map>
class TextureManager
{
public:

	static TextureManager *instance();

	void draw(float x, float y, int w, int h, const std::string& textureID);
	void load(const std::string& textureID, std::string path);
	//SDL_Surface* loadSurface(const std::string& path);
	//SDL_Texture* loadTexture(const std::string& path);
	SDL_Texture* getPlayerTexture(const std::string& textureName) { return m_textures[textureName]; }

private:
	TextureManager();
	~TextureManager();
	std::map<std::string, SDL_Texture*> m_textures;
	std::map<std::string, std::unique_ptr<SDL_Texture, SDLDeleter>> m_newTextures;
	//std::unique_ptr<SDL_Texture, SDLDeleter> m_playerShipTexture;
	//std::unique_ptr<SDL_Texture, SDLDeleter> m_enemyShipTexture;

	static TextureManager *sm_instance;
};
#endif // !TEXTURE_MANAGER_H
