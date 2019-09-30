#ifndef GAME_H
#define GAME_H

#include <vector>
#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "fileIO.h"
#include "wall.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  int GetMaxScore() const;
 private:
  Snake snake;
  SDL_Point food;
  vector<Wall> wallVector;
  string scoreFilePath = "scoreFile";
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  std::size_t grid_width;
  std::size_t grid_height;
  int score{0};
  FileIO fileIO;
  void PlaceFood();
  void Update();
};

#endif