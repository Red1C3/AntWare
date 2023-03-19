#ifndef NOSOUND
#include <SDL2/SDL_mixer.h>
#endif
#include <SoundAdapter.h>
#include <assert.h>
using namespace aw;

SoundAdapter::~SoundAdapter() {
#ifndef NOSOUND
  Mix_FreeChunk(chunk);
#endif
}
void SoundAdapter::setBuffer(SoundBufferAdapter soundBuffer) {
#ifndef NOSOUND
  chunk = Mix_LoadWAV(soundBuffer.getPath());
  if (chunk == nullptr) {
    printf("Failed to load file %s , err: %s", soundBuffer.getPath(),
           Mix_GetError());
    assert(0);
  }
#endif
}
void SoundAdapter::play() {
#ifndef NOSOUND
  if (channel == -2) {
    int ch;
    if (loop) {
      ch = Mix_PlayChannel(-1, chunk, -1);
      channel = ch;
    } else {
      ch = Mix_PlayChannel(-1, chunk, 0);
    }
    if (ch == -1) {
      printf("Failed to find an empty channel to play on, err: %s",
             Mix_GetError());
      assert(0);
    }
  } else {
    Mix_Resume(channel);
  }
#endif
}
void SoundAdapter::setLoop(bool loop) {
#ifndef NOSOUND
  this->loop = loop;
#endif
}
void SoundAdapter::setPitch(float pitch) {
  // FIXME No direct way to do it in SDL
}
SoundAdapter::Status SoundAdapter::getStatus() {
#ifndef NOSOUND
  if (channel == -2)
    return DEAD;
  if (!Mix_Paused(channel)) {
    return PLAYING;
  } else {
    return PAUSED;
  }
#else
  return PLAYING;
#endif
}
void SoundAdapter::pause() {
#ifndef NOSOUND
  if (channel >= 0)
    Mix_Pause(channel);
#endif
}
