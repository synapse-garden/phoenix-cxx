project(Phoenix CXX C)

set(SDLInitUtil_SRCS
  initUtil.cxx
)

add_library(SDLInitUtil STATIC ${SDLInitUtil_SRCS})

find_package(SDL2 REQUIRED)

target_include_directories(SDLInitUtil PUBLIC
  ${SDL2_INCLUDE_DIR}
  ${Phoenix_INCLUDE_DIR}/error
  ${Phoenix_INCLUDE_DIR}/sdl
)

target_link_libraries(SDLInitUtil
  ${SDL2_LIBRARY}
  Error
)

set_property(TARGET SDLInitUtil PROPERTY CXX_STANDARD 11)
set_property(TARGET SDLInitUtil PROPERTY CXX_STANDARD_REQUIRED ON)
