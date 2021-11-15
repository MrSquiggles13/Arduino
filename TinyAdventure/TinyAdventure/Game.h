#pragma once

#include "User.h"

class Game
{
private:
	bool m_playing;
	User player;

public:

	Game(bool playing = true);

	void randomEncounter();
	void fightEncounter();
	void lootAndExp();
	void puzzleEncounter();
	void nothingEncounter();
	void playGame();
	void mainMenu();
};

