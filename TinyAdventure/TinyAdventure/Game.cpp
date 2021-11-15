#include "Game.h"
Game::Game(bool playing): m_playing{playing}{}

void Game::fightEncounter()
{
	
}

void Game::lootAndExp()
{

}

void Game::puzzleEncounter()
{

}

void Game::nothingEncounter()
{

}

void Game::randomEncounter()
{
	int encounter{ rand() % 3 };
	switch (encounter)
	{
	case 1:// Fight
		lcd.clear();
		lcd.println("Prepare To Fight!");
		delay(screenDelay);
		fightEncounter();
		break;
	case 2:// Loot
		break;
	case 3:// Puzzle
		break;
	case 4:// Nothing with description
		break;
	}
}

void Game::mainMenu()
{
	lcd.clear();
	while (true)
	{
		buttonChoice = analogRead(A0);
		lcd.setCursor(0, 0);
		lcd.print("Travel     Stats");
		lcd.setCursor(0, 1);
		lcd.print("Inventory   Quit");
		if (buttonChoice >= button1Min && buttonChoice <= button1Max)
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Travel");
			delay(1300);
			randomEncounter();
		}
		if (buttonChoice >= button2Min && buttonChoice <= button2Max)
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("           Stats");
			delay(1300);
			player.printStats();
		}
		if (buttonChoice >= button4Min && buttonChoice <= button4Max)
		{
			lcd.clear();
			lcd.setCursor(0, 1);
			lcd.print("Inventory");
			delay(1300);
			player.manageInventory();
		}
		if (buttonChoice >= button3Min && buttonChoice <= button3Max)
		{
			lcd.clear();
			lcd.setCursor(0, 1);
			lcd.print("            Quit");
			delay(1300);
			m_playing = false;
			break;
		}
	}
}

void Game::playGame()
{
	//player.createCharacter();
	player.addItem(*Weapon(2).cloneItem());
	while (m_playing)
	{
		mainMenu();
	}
}






