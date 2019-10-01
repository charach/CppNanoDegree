# CPPND: Capstone Snake Game 

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

# Game point 
* You can save the max point of the game.(writing file)
* The wall occured every 2 seconds, and the player should avoid it.(If snake head attached it, then die)

# Rublic point
* ReadMe
* Compiling and testing
* The project demonstrates an understanding of C++ functions and control structures. (All codes)
* The project reads data from a file and process the data, or the program writes data to a file. (fileIO.cpp, fileIO.h)
* The project accepts user input and processes the input. (controller.cpp : HandleInput)
* The project uses Object Oriented Programming techniques.( fileIO.cpp, fileIO.h, wall.cpp, wall.h)
* Classes use appropriate access specifiers for class members. ( all classes)
* Class constructors utilize member initialization lists.(wall.cpp, fileIO.cpp and other classes)
* Classes encapsulate behavior.( wall.cpp, fileIO.cpp)
* The project uses move semantics to move data, instead of copying it, where possible.(game.cpp : wallVector.push_back(std::move(Wall(grid_width,grid_height,snake.body,wallVector)));)

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


