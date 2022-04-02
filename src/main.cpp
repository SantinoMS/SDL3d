#ifndef MAIN_H
#define MAIN_H
#include "GameWindow.h"

int main(int argc, char** argv) {
  GameWindow gameWindow;
  gameWindow.run();

  std::cout<<"\nDone\n";
  return 0;
}

#endif

