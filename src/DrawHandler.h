#ifndef DRAWHANDLER_H
#define DRAWHANDLER_H

#include <SDL2/SDL.h>

class DrawHandler
{
public:
  DrawHandler(); // Constructor function
  ~DrawHandler(); // Destructor function

  void init(
    SDL_Window*   window,
    SDL_Renderer* renderer,
    int           screenWidth,
    int           screenHeight);

  void draw();

  //tempVars
  int color;
  int color2;
  int x, y, x2, y2;

private:
  SDL_Window* _window;
  SDL_Renderer* _renderer;

  int _screenWidth;
  int _screenHeight;
};

#endif
