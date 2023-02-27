#pragma once
#include<SDL2/SDL_mixer.h>
#include<SoundBufferAdapter.h>
namespace aw{
  
    class SoundAdapter{
        Mix_Chunk* chunk=nullptr;
        public:
        ~SoundAdapter();
        void setBuffer(SoundBufferAdapter soundBuffer);
        
    };
}
