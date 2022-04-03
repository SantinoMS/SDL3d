#include "GameWindow.h"

GameWindow::GameWindow()
{
  _window       = nullptr;
  _renderer     = nullptr;
  _screenWidth  = 1024;
	_fps					= 60;
  _screenHeight = 768;
  _gameState    = GameState::STARTED;
}

GameWindow::~GameWindow() {
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  _window = nullptr;
  _renderer = nullptr;
  SDL_Quit();
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

void GameWindow::check() {
  if (_eventHandler.w==1) {
    _drawHandler.y-=10;
  }
  if (_eventHandler.a==1) {
    _drawHandler.x-=10;
  }
  if (_eventHandler.s==1) {
    _drawHandler.y+=10;
  }
  if (_eventHandler.d==1) {
    _drawHandler.x+=10;
  }
  // if (_eventHandler.keyDown == 2) {
  //   _drawHandler.color++;
  // } else if (_eventHandler.keyDown == 1) {
  //   _drawHandler.color--;
  // } else if (_eventHandler.mouseMoved) {
  _drawHandler.x2 = _eventHandler.x2;
  _drawHandler.y2 = _eventHandler.y2;
  //}
};

void GameWindow::gameLoop() {
  while (_gameState != GameState::EXIT) {
    processInput(_eventHandler);
    check();
    _drawHandler.draw();
    SDL_Delay(16);
  }
}
