#include<SoundBufferAdapter.h>
using namespace aw;


void SoundBufferAdapter::loadFromFile(const char* path){
    this->path=path;
}
const char* SoundBufferAdapter::getPath(){
    return path;
}
