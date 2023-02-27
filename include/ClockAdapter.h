#pragma once
#include<SDL2/SDL.h>
namespace aw{
  class ClockAdapter{
  class TimeAdapter{
    private:
    Uint32 milliseconds;
    public:
    TimeAdapter(Uint32 milliseconds);
    float asSeconds();
  };
  private:
  Uint32 startTime;
  public:
  ClockAdapter();
  TimeAdapter getElapsedTime();
  TimeAdapter restart();
};
}
