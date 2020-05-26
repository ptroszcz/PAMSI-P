#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <chrono>
#include "Board.hh"


class Game {
  Board board;
  sf::RenderWindow window;
  sf::Texture textures[10];
  sf::Sprite sprites[10];
public:
  Game(){}
  void start();
  void draw();
  int mouse();
  void FreeBlack();
  void FreeWhite();
  bool CheckWindow();
  void BlackCapture();
  void WhiteCapture();
  void Computer(bool white);
  int minmax(int depth, bool white);
};
