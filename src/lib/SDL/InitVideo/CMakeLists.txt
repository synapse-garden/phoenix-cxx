project(Phoenix CXX C)

set(SDLInitVideo_SRCS
  initVideo.cxx
)

add_library(SDLInitVideo STATIC ${SDLInitVideo_SRCS})

find_package(SDL2 REQUIRED)

target_include_directories(SDLInitVideo PUBLIC
  ${SDL2_INCLUDE_DIR}
  ${Phoenix_INCLUDE_DIR}/error
  ${Phoenix_INCLUDE_DIR}/sdl
)

target_link_libraries(SDLInitVideo
  ${SDL2_LIBRARY}
  Error
)

set_property(TARGET SDLInitVideo PROPERTY CXX_STANDARD 11)
set_property(TARGET SDLInitVideo PROPERTY CXX_STANDARD_REQUIRED ON)
