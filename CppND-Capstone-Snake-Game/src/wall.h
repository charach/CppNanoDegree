#ifndef WALL_H
#define WALL_H

#include <random>
#include <vector>
#include "SDL.h"

using std::vector;

class Wall{
    public :
        Wall(int grid_width, int grid_height,vector<SDL_Point> snakeBody, vector<Wall> wallVector);
        Wall(const Wall& wall);
        SDL_Point getPos() const;
        void setPos(SDL_Point pos);
    private :
        SDL_Point pos;
        std::random_device dev;
        std::mt19937 engine;
        std::uniform_int_distribution<int> random_w;
        std::uniform_int_distribution<int> random_h;
};

#endif