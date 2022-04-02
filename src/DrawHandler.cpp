#include "DrawHandler.h"

DrawHandler::DrawHandler() {
  _window       = nullptr;
  _renderer     = nullptr;
  _screenWidth  = 0;
  _screenHeight = 0;
  color = 0; color2 = 0;
  x = 0; y = 0;
}

DrawHandler::~DrawHandler() {

}

void DrawHandler::init(
  SDL_Window*   window,
  SDL_Renderer* renderer,
  int           screenWidth,
  int           screenHeight
) {
  _window       = window;
  _renderer     = renderer;
  _screenWidth  = screenWidth;
  _screenHeight = screenHeight;
}

SDL_Rect rect;

void DrawHandler::draw() {
  SDL_SetRenderDrawColor(_renderer, 255+color2, 0+color, 255, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(_renderer);

  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawLine(_renderer, x, y, x2, y2);
  SDL_RenderPresent(_renderer);
}
