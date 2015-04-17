#ifndef SDLRENDERER_H
#define SDLRENDERER_H

#include "SDL.h"

#include "initError.hpp"

namespace sdl
{
     class Renderer
     {
     public:
          Renderer(SDL_Window*, Uint32 flags = 0) throw (error::InitError);

          SDL_Renderer* handle();

          ~Renderer();

     private:
          SDL_Renderer* renderer;
     };
}

#endif
