#ifndef SDLDISPLAY_H
#define SDLDISPLAY_H

#include "SDL.h"

#include "initError.hpp"

namespace sdl
{
     class Display
     {
     public:
          Display() throw(error::InitError);

          int w() { return display.w; };
          int h() { return display.h; };

          const SDL_DisplayMode* handle();

     private:
          SDL_DisplayMode display;
     };
}

#endif
