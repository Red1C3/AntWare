#include "SDL_mixer.h"
#include<assert.h>
#include<SoundAdapter.h>
using namespace aw;


SoundAdapter::~SoundAdapter(){
    Mix_FreeChunk(chunk);
}
void SoundAdapter::setBuffer(SoundBufferAdapter soundBuffer){
    chunk=Mix_LoadWAV(soundBuffer.getPath());
    if(chunk==nullptr){
        printf("Failed to load file %s , err: %s",soundBuffer.getPath(),Mix_GetError());
        assert(0);
    }
}
void SoundAdapter::play(){
  Mix_PlayChannel(-1,chunk,0);
}