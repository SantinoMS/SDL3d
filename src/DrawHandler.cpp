#include "DrawHandler.h"

DrawHandler::DrawHandler() {
  _window       = nullptr;
  _renderer     = nullptr;
  _screenWidth  = 0;
  _screenHeight = 0;
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

void DrawHandler::draw() {
  SDL_SetRenderDrawColor(_renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(_renderer);

  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawLine(_renderer, 5, 5, _screenWidth-5, _screenHeight-5);
}
