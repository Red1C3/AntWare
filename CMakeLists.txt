cmake_minimum_required(VERSION 3.26)

project('antware')

option(NOSOUND "Disables Sound" OFF)

if(NOSOUND)
  add_definitions(-DNOSOUND)
endif(NOSOUND)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

link_libraries(
  GL
  GLEW
  SDL2
  SDL2_image
  assimp
)

if(NOT NOSOUND)
  link_libraries(SDL2_mixer)
endif(NOT NOSOUND)

add_executable(AntWare ${sources})

file(COPY ${PROJECT_SOURCE_DIR}/default_settings.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/scenes DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/Shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
