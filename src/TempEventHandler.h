#ifndef TEMPEVENTHANDLER_H
#define TEMPEVENTHANDLER_H

#include "Inputs.h"

class TempEventHandler : public Inputs
{
public:
  int w=0;
  int a=0;
  int s=0;
  int d=0;
  int x, y, kp, x2, y2;
  int keyDown = 0;
  bool mouseMoved = false;
  TempEventHandler() {}
  virtual void onKeyDown(Uint32 keyCode, bool isRepeat)
  {
    keyDown = 1;
    switch (keyCode) {
			case 4:
        a = 1;
        break;
      case 7:
        d = 1;
        break;
      case 26:
        w = 1;
        break;
      case 22:
        s = 1;
        break;
      default:
        keyDown = 0;
        w = a = s = d = 0;
        break;
    }
  }
  virtual void onKeyUp(Uint32 keyCode, bool isRepeat)
  {
    keyDown = 0;
    switch (keyCode) {
      case 4:
        a = 0;
        break;
      case 7:
        d = 0;
        break;
      case 26:
        w = 0;
        break;
      case 22:
        s = 0;
        break;
      default:
        break;
    }
  }
  virtual void onMouseMove(Sint32 mousePosX, Sint32 mousePosY, Sint32 deltaX, Sint32 deltaY)
  {
    if ((deltaX != 0) || (deltaY != 0)) {
      mouseMoved = true;
      x2 = mousePosX;
      y2 = mousePosY;
    } else {mouseMoved = false;}
  }
};

#endif
