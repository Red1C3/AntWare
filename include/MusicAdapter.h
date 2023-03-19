#pragma once
#ifndef NOSOUND
#include <SDL2/SDL_mixer.h>
#endif
namespace aw {
class MusicAdapter {
  #ifndef NOSOUND
  Mix_Music *music = nullptr;
  #endif 

private:
  bool loop = true;

public:
  ~MusicAdapter();
  void openFromFile(const char *path);
  void setVolume(int volume);
  void setLoop(bool loop);
  void play();
  void stop();
};
} // namespace aw