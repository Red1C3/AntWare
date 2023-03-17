#pragma once
#ifndef NOSOUND
#include <SDL2/SDL_mixer.h>
#endif
#include <SoundBufferAdapter.h>
namespace aw {

class SoundAdapter {
  #ifndef NOSOUND
  Mix_Chunk *chunk = nullptr;
  #endif
  bool loop = false;
  int channel=-2;

public:
  enum Status { PLAYING, PAUSED, DEAD};
  ~SoundAdapter();
  void setBuffer(SoundBufferAdapter soundBuffer);
  void play();
  void pause();
  void setLoop(bool loop);
  void setPitch(float pitch);
  Status getStatus();
};
} // namespace aw
