#pragma once
#include <SDL2/SDL_mixer.h>
namespace aw {
class MusicAdapter {
  Mix_Music *music = nullptr;

private:
  bool loop = true;

public:
  ~MusicAdapter();
  void openFromFile(const char *path);
  void setVolume(int volume);
  void setLoop(bool loop);
  void play();
};
} // namespace aw