#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SDL2/SDL.h>
#include "DrawHandler.h"
#include "Inputs.h"
#include "TempEventHandler.h"

enum class GameState {STARTED, EXIT};
enum class GameState2 {SPLASH, MAINMENU, GAME};

class GameWindow
{
public:
  GameWindow();
  ~GameWindow();

  void run();
  void check(); //temp func

private:
  void initSystems();
  void gameLoop();
  void processInput(Inputs &eventHandler);

  SDL_Window* _window;
  SDL_Renderer* _renderer;
  GameState _gameState;

  TempEventHandler _eventHandler;
  DrawHandler _drawHandler; //tempObject

  int _screenWidth;
  int _screenHeight;
  int _fps;
};

#endif
