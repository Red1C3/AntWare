#include <MusicAdapter.h>
#ifndef NOSOUND
#include <SDL2/SDL_mixer.h>
#endif
#include <assert.h>

using namespace aw;

void MusicAdapter::openFromFile(const char *path) {
#ifndef NOSOUND
  music = Mix_LoadMUS(path);
  if (music == nullptr) {
    printf("Failed to load music file, err:%s", Mix_GetError());
    assert(0);
  }
#endif
}
void MusicAdapter::setVolume(int volume) {
#ifndef NOSOUND
  Mix_VolumeMusic(volume);
#endif
}
void MusicAdapter::setLoop(bool loop) {
#ifndef NOSOUND
  this->loop = loop;
#endif
}
void MusicAdapter::play() {
#ifndef NOSOUND
  if (loop) {
    Mix_PlayMusic(music, -1);
  } else {
    Mix_PlayMusic(music, 0);
  }
#endif
}
MusicAdapter::~MusicAdapter() {
#ifndef NOSOUND
  Mix_FreeMusic(music);
#endif
}
void MusicAdapter::stop() {
#ifndef NOSOUND
  Mix_HaltMusic();
#endif
}