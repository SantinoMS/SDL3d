#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SDL2/SDL.h>
#include "DrawHandler.h"

enum class GameState {STARTED, EXIT};
enum class GameState2 {SPLASH, MAINMENU, GAME};

class GameWindow
{
public:
  GameWindow();
  ~GameWindow();

  void run();

private:
  void initSystems();
  void gameLoop();
  void processInput();

  SDL_Window* _window;
  SDL_Renderer* _renderer;
  GameState _gameState;

  DrawHandler _drawHandler;

  int _screenWidth;
  int _screenHeight;
};

#endif
