#pragma once

#include "User.h"

class Game
{
private:
	bool m_playing;
	User player;

public:

	Game(bool playing = true);

	void playGame();

	inline const bool getPlaying() const { return m_playing; }
};


