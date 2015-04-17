#include "SDL.h"

#include "app.hpp"

using namespace app;

void App::run()
{
     bool finished = false;
     bool lmbDown = false;

     int prevX = 0, prevY = 0;
     int currX = 0, currY = 0;

     SDL_Event event = SDL_Event{ 0 };

     while (!finished) {
          graphics.update();

          while (SDL_PollEvent(&event)) {
               switch(event.type) {
               case SDL_QUIT:
                    finished = true;
                    break;
               case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                         finished = true;
                    }
                    break;
               case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT)
                         lmbDown = false;
                    break;
               case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                         lmbDown = true;
                         prevX = currX = event.button.x, prevY = currY = event.button.y;
                         graphics.drawPoint(currX, currY);
                    }
                    break;
               case SDL_MOUSEMOTION:
                    if (lmbDown)
                    {
                         currX = event.motion.x, currY = event.motion.y;
                         graphics.drawLine(prevX, prevY, currX, currY);
                    }
                    prevX = currX, prevY = currY;
                    break;
               }
          }

          graphics.draw();
     }
}
