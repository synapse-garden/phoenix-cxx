#ifndef APP_H
#define APP_H

#include "initError.hpp"
#include "world.hpp"
#include "graphics.hpp"
#include "sdlUtil.hpp"

namespace app {
     class App {
     public:
          App(const std::string& title = "Phoenix") throw (error::InitError);

          void run();

     private:
          const std::string title;

          sdl::SDLUtil sdlUtil;

          world::World world;
          gfx::Graphics graphics;
     };
}

#endif
