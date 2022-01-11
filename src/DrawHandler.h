#ifndef DRAWHANDLER_H
#define DRAWHANDLER_H
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class DrawHandler{
public:
  DrawHandler(); // Constructor function
  ~DrawHandler(); // Destructor function

  void init(
    SDL_Window*   window,
    SDL_Renderer* renderer,
    int           screenWidth,
    int           screenHeight);

  void draw();

private:
  SDL_Window* _window;
  SDL_Renderer* _renderer;

  int _screenWidth;
  int _screenHeight;
};

#endif
