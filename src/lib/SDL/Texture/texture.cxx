#include <sstream>

#include "SDL.h"

#include "initError.hpp"
#include "texture.hpp"

using namespace sdl;

Texture::Texture(SDL_Renderer* renderer,
                 int w, int h) throw (error::InitError)
{
     std::stringstream ss;

     texture = SDL_CreateTexture(renderer,
                                 SDL_PIXELFORMAT_ARGB8888,
                                 SDL_TEXTUREACCESS_STREAMING,
                                 w, h);
     if (texture == NULL) {
          ss << "SDL_CreateTexture failed: " << SDL_GetError();

          throw error::InitError(ss.str());
     }
}

void Texture::update(const SDL_Rect* rect,
                     const void*     pixels,
                     int             pitch)
{
     SDL_UpdateTexture(texture, rect, pixels, pitch);
}

Texture::~Texture()
{
     SDL_DestroyTexture(texture);
}
