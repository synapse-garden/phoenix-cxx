#ifndef SDLTEXTURE_H
#define SDLTEXTURE_H

#include "SDL.h"

#include "initError.hpp"

namespace sdl
{
     class Texture
     {
     public:
          Texture(SDL_Renderer* renderer,
                  int w = 640, int h = 480) throw (error::InitError);
          ~Texture();

          void update(const SDL_Rect*, const void*, int);

          SDL_Texture* handle() { return texture; }

     private:
          SDL_Texture* texture;
     };
}

#endif
