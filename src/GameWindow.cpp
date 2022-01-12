#include "GameWindow.h"

GameWindow::GameWindow()
{
  _window       = nullptr;
  _renderer     = nullptr;
  _screenWidth  = 1024;
  _screenHeight = 768;
  _gameState    = GameState::STARTED;
}

GameWindow::~GameWindow()
{

}

void GameWindow::run() {
  initSystems();
  gameLoop();
}

void GameWindow::initSystems() {
  SDL_Init(SDL_INIT_EVERYTHING);

  _window = SDL_CreateWindow("Shooting Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

  _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

  _drawHandler.init(_window, _renderer, _screenWidth, _screenHeight);
}

void GameWindow::gameLoop() {
  while (_gameState != GameState::EXIT) {
    processInput();
    _drawHandler.draw();
  }
}
