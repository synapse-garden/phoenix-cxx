#include <sstream>

#include "SDL.h"

#include "initError.hpp"
#include "initUtil.hpp"

using namespace sdl;

InitUtil::InitUtil(Uint32 flags) throw (error::InitError)
{
     std::stringstream ss;

     int initOk = SDL_Init(flags);

     if (initOk != 0) {
          ss << "SDL_Init failed with code " << initOk
             << ": " << SDL_GetError();

          throw error::InitError(ss.str());
     }
}

InitUtil::~InitUtil()
{
     SDL_Quit();
}
