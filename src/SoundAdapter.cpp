#include<SDL2/SDL_mixer.h>
#include <SoundAdapter.h>
#include <assert.h>
using namespace aw;

SoundAdapter::~SoundAdapter() { Mix_FreeChunk(chunk); }
void SoundAdapter::setBuffer(SoundBufferAdapter soundBuffer) {
  chunk = Mix_LoadWAV(soundBuffer.getPath());
  if (chunk == nullptr) {
    printf("Failed to load file %s , err: %s", soundBuffer.getPath(),
           Mix_GetError());
    assert(0);
  }
}
void SoundAdapter::play() {
  if (channel == -2) {
    int ch;
    if (loop) {
      ch = Mix_PlayChannel(-1, chunk, -1);
      channel=ch;
    } else {
      ch=Mix_PlayChannel(-1, chunk, 0);
    }
    if (ch == -1) {
      printf("Failed to find an empty channel to play on, err: %s",
             Mix_GetError());
      assert(0);
    }
  } else {
    Mix_Resume(channel);
  }
}
void SoundAdapter::setLoop(bool loop) { this->loop = loop; }
void SoundAdapter::setPitch(float pitch) {
  // FIXME No direct way to do it in SDL
}
SoundAdapter::Status SoundAdapter::getStatus() {
  if(channel==-2) return DEAD;
  if (!Mix_Paused(channel)) {
    return PLAYING;
  } else {
    return PAUSED;
  }
}
void SoundAdapter::pause() {
  if (channel >= 0)
    Mix_Pause(channel);
}
