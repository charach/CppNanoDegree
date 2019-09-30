#include <vector>
#include "wall.h"
#include "SDL.h"


Wall::Wall(int grid_width, int grid_height,vector<SDL_Point> snakeBody, vector<Wall> wallVector)  : 
      engine(dev()),
      random_w(0, static_cast<int>(grid_width -1)),
      random_h(0, static_cast<int>(grid_height -1))
{
    int x,y;
    vector<SDL_Point> vectorBuf = snakeBody;
    vector<Wall>::iterator wallVectorIter;

    for(wallVectorIter = wallVector.begin(); wallVectorIter != wallVector.end(); wallVectorIter++){
        vectorBuf.emplace_back(wallVectorIter->getPos());
    }


    while(true){
        vector<SDL_Point>::iterator listIter;
        x = random_w(engine);
        y = random_h(engine);
        for(listIter = vectorBuf.begin(); listIter != vectorBuf.end(); listIter++){
            if(sqrt(pow(x - listIter->x ,2) + pow(y - listIter->y, 2)) < 3){
                break;
            }
        }    
        if(listIter == vectorBuf.end())
        {
            break;
        }
    }
    pos.x = x;
    pos.y = y;
}
Wall::Wall(const Wall& wall){
    pos = wall.getPos();
}

SDL_Point Wall::getPos() const{
    return pos;
}

void Wall::setPos(SDL_Point pos){
    pos.x = pos.x;
    pos.y = pos.y;
}