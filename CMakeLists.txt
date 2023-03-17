cmake_minimum_required(VERSION 3.26)

project('antware')

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

link_libraries(
  GL
  GLEW
  SDL2
  SDL2_image
  SDL2_mixer
  assimp
)

add_executable(AntWare ${sources})

file(COPY ${PROJECT_SOURCE_DIR}/default_settings.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/scenes DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/Shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
