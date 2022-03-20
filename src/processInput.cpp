#include "GameWindow.h"

void GameWindow::processInput (Inputs &eventHandler) {
  SDL_Event e;

  while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        _gameState = GameState::EXIT;
        break;
      case SDL_KEYDOWN:
        eventHandler.onKeyDown(e.key.keysym.scancode, e.key.repeat != 0);
        break;
      case SDL_KEYUP:
        eventHandler.onKeyUp(e.key.keysym.scancode, e.key.repeat != 0);
        break;
      case SDL_MOUSEBUTTONDOWN:
        eventHandler.onMouseDown(e.button.button, e.button.clicks);
        break;
      case SDL_MOUSEBUTTONUP:
        eventHandler.onMouseUp(e.button.button, e.button.clicks);
        break;
      case SDL_MOUSEMOTION:
        eventHandler.onMouseMove(e.motion.x, e.motion.y, e.motion.xrel, e.motion.yrel);
        break;
      default:
        break;
    }
  }
}
