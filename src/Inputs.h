#ifndef INPUTS_H
#define INPUTS_H

#include "SDL2/SDL.h"

class Inputs
{
public:
  Inputs(){}
  virtual ~Inputs(){}

  virtual void onKeyUp(Uint32 keyCode, bool isRepeat) {}
  virtual void onKeyDown(Uint32 keyCode, bool isRepeat) {}
  virtual void onMouseDown(Uint32 mouseButton, int numClicks) {}
  virtual void onMouseUp(Uint32 mouseButton, int numClicks) {}
  virtual void onMouseMove(Sint32 mousePosX, Sint32 mousePosY, Sint32 deltaX, Sint32 deltaY) {}

private:
  void NULL_COPY_AND_ASSIGN(Inputs);
};

#endif
