#include "SDL_mixer.h"
#include<assert.h>
#include<MusicAdapter.h>

using namespace aw;

void MusicAdapter::openFromFile(const char* path){
    music=Mix_LoadMUS(path);
    if (music==nullptr){
        printf("Failed to load music file, err:%s",Mix_GetError());
        assert(0);
    }
}
void MusicAdapter::setVolume(int volume){
    Mix_VolumeMusic(volume);
}
void MusicAdapter::setLoop(bool loop){
    this->loop=loop;
}
void MusicAdapter::play(){
    if(loop){
        Mix_PlayMusic(music,-1);
    }else{
        Mix_PlayMusic(music,0);
    }
}
MusicAdapter::~MusicAdapter(){
    Mix_FreeMusic(music);
}
void MusicAdapter::stop(){
  Mix_HaltMusic();
}