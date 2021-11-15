#include "Game.h"

Game::Game(bool playing) : m_playing{ playing } {}

void Game::playGame()
{
	player.addItem(Weapon("Sword", 1, 1, 1));
	player.addItem(Weapon("Knives", 1, 1, 1));
	player.addItem(Weapon("Dick", 1, 1, 1));
	player.addItem(Weapon("Balls", 1, 1, 1));
	int button{ 0 };
	int index{ 0 };
	while (true)
	{
		std::cin >> button;

		if (button == 1)
		{
			
			
			
			while (true)
			{
				player.viewItem(index);
				std::cin >> button;
				if (button == 2)
					if (index + 1 >= player.getNumOfItem())
					{
						std::cout << " ";
					}
					else
						++index;

				else if (button == 3)
					if (index - 1 < 0)
					{
						std::cout << " ";
					}
					else
						--index;

				else if (button == 4)
					break;
			}
		}
	}

	exit(0);
}