// TestTinyAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"

int main()
{
	Game game;
	while (game.getPlaying())
		game.playGame();
}
