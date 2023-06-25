#include <iostream>
#include "Headers/Game.hpp"
#include <locale>

int main()
{
    setlocale(LC_ALL, "");
    Game Maze;

    Maze.run();
    return 0;
}