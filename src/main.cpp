#pragma once

#include "Game.h"

int main() 
{
    srand(static_cast<unsigned>(time(0)));

    Game game;

    while (game.getWindowIsOpen())
    {
        //Update
        game.Update();
        //Render
        game.Render();
    }
	return 0;
}