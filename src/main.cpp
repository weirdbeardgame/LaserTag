#include <iostream>
#include <iomanip>
#include "game.h"

int main(int argc, char *argv[])
{

    Game game;
    if (game.Init())
    {
        std::cout << "Game is initalized" << std::endl;
        while(1)
        {
            game.Update();
        }
    }
    else
    {
        std::cerr << "Game init error" << std::endl;
    }

}