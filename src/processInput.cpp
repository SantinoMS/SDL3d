#include "GameWindow.h"

void GameWindow::processInput () {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        _gameState = GameState::EXIT;
        break;
      default:
        break;
    }
  }
}
