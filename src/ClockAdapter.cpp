#include "SDL_timer.h"
#include<ClockAdapter.h>
using namespace aw;
ClockAdapter::ClockAdapter(){
  startTime=SDL_GetTicks();
}
ClockAdapter::TimeAdapter::TimeAdapter(Uint32 milliseconds){
  this->milliseconds=milliseconds;
}
float ClockAdapter::TimeAdapter::asSeconds(){
  return (float)milliseconds/1000.0f;
}
ClockAdapter::TimeAdapter ClockAdapter::getElapsedTime(){
  return TimeAdapter(SDL_GetTicks()-startTime);
}
ClockAdapter::TimeAdapter ClockAdapter::restart(){
  TimeAdapter time=TimeAdapter(SDL_GetTicks()-startTime);
  startTime=SDL_GetTicks();
  return time;
}
