#pragma once
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_video.h>
#define WINDOW aw::Window::instance()
namespace aw {
class Window {
private:
  class WindowAdapter {
    friend Window;
    class SizeAdapter{
      public:
      SizeAdapter(int x,int y);
      int x,y;
    };
  private:
    SDL_GLContext ctx = nullptr;
    SDL_Window *window = nullptr;
    public:
    SDL_Window* getHandle();
    int pollEvent(SDL_Event& event);
    void display();
    SizeAdapter getSize();
  };

  Window();
  void initAudio();
  void initImageLoading();

public:
  WindowAdapter internal;
  static Window &instance();
  void init(int height, int width);
  void terminate();
};
} // namespace aw