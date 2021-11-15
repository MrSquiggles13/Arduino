#include "User.h"

User::User(int level,
	int expCurrent,
	int expNext,
	int health,
	int healthMax,
	int magic,
	int magicMax,
	int damageMin,
	int damageMax,
	int accuracy,
	int defence):

	m_level{ level },
	m_expCurrent{ expCurrent },
	m_expNext{ expNext },
	m_health{ health },
	m_healthMax{ healthMax },
	m_magic{ magic },
	m_magicMax{ magicMax },
	m_damageMin{ damageMin },
	m_damageMax{ damageMax },
	m_accuracy{ accuracy },
	m_defence{ defence },
	weapon{ Weapon("Fists", 1, 1, 2)},
	armour{ Armour("Cloth", 1, 1)},
	spell{ Spell("Flame", 1, 2, 3, 5)}
{

}

void User::createCharacter()
{
	lcd.setCursor(0, 0);
	lcd.print("What Weapon"); 
	lcd.setCursor(0, 1);
	lcd.print("do you choose?");
	delay(screenDelay);

	bool buttonPressed{ false };
	bool buttonValidate{ false };
	while (!buttonPressed)
	{
		buttonValidate = false;
		buttonChoice = analogRead(A0);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Sword       Cane");
		lcd.setCursor(0, 1);
		lcd.print("Bow       Knives");
		delay(100);
		if (buttonChoice >= button4Min && buttonChoice <= button4Max) //Bow
		{
			lcd.clear();
			lcd.setCursor(0, 1);
			lcd.print("Bow");
			delay(screenDelay);
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Do you want the Bow?");
			delay(500);
			for (int move{ 0 }; move < 5; ++move)
			{
				delay(300);
				lcd.scrollDisplayLeft();
			}
			lcd.setCursor(0, 1);
			lcd.print("      Yes         No ");
			while (!buttonValidate)
			{
				buttonChoice = analogRead(A0);
				if (buttonChoice >= button4Min && buttonChoice <= button4Max) // Yes
				{
					buttonValidate = true;
					buttonPressed = true;
					equipWeapon(Weapon("Bow", 1, 2, 4));
				}
				if (buttonChoice >= button3Min && buttonChoice <= button3Max) // No
				{
					buttonValidate = true;
					buttonPressed = false;
				}
			}
			delay(400);
		}
		if (buttonChoice >= button1Min && buttonChoice <= button1Max && !buttonValidate) //Sword
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Sword");
			delay(screenDelay);
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Do you want the Sword?");
			delay(500);
			for (int move{ 0 }; move < 7; ++move)
			{
				delay(300);
				lcd.scrollDisplayLeft();
			}
			lcd.setCursor(0, 1);
			lcd.print("        Yes         No ");
			while (!buttonValidate)
			{
				buttonChoice = analogRead(A0);
				if (buttonChoice >= button4Min && buttonChoice <= button4Max) // Yes
				{
					buttonValidate = true;
					buttonPressed = true;
					equipWeapon(Weapon("Sword", 1, 2, 4));
				}
				if (buttonChoice >= button3Min && buttonChoice <= button3Max) // No
				{
					buttonValidate = true;
					buttonPressed = false;
				}
			}
			delay(400);
		}
		if (buttonChoice >= button2Min && buttonChoice <= button2Max && !buttonValidate) //Staff
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("            Cane");
			delay(screenDelay);
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Do you want the Cane?");
			delay(500);
			for (int move{ 0 }; move < 7; ++move)
			{
				delay(300);
				lcd.scrollDisplayLeft();
			}
			lcd.setCursor(0, 1);
			lcd.print("        Yes         No ");
			while (!buttonValidate)
			{
				buttonChoice = analogRead(A0);
				if (buttonChoice >= button4Min && buttonChoice <= button4Max) // Yes
				{
					buttonValidate = true;
					buttonPressed = true;
					equipWeapon(Weapon("Cane", 1, 2, 4));
				}
				if (buttonChoice >= button3Min && buttonChoice <= button3Max) // No
				{
					buttonValidate = true;
					buttonPressed = false;
				}
			}
			delay(400);
		}
		if (buttonChoice >= button3Min && buttonChoice <= button3Max) //Knives
		{
			lcd.clear();
			lcd.setCursor(0, 1);
			lcd.print("          Knives");
			delay(screenDelay);
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Do you want the Knives?");
			delay(500);
			for (int move{ 0 }; move < 8; ++move)
			{
				delay(300);
				lcd.scrollDisplayLeft();
			}
			lcd.setCursor(0, 1);
			lcd.print("         Yes         No ");
			while (!buttonValidate)
			{
				buttonChoice = analogRead(A0);
				if (buttonChoice >= button4Min && buttonChoice <= button4Max) // Yes
				{
					buttonValidate = true;
					buttonPressed = true;
					equipWeapon(Weapon("Knives", 1, 2, 4));
				}
				if (buttonChoice >= button3Min && buttonChoice <= button3Max) // No
				{
					buttonValidate = true;
					buttonPressed = false;
				}
			}
			delay(400);
		}
	}
}

void User::printStats()
{
	int screen{ 0 };
	while (true)
	{
		buttonChoice = analogRead(A0);

		if (buttonChoice >= button2Min && buttonChoice <= button2Max)
			--screen;
		if (buttonChoice >= button3Min && buttonChoice <= button3Max)
			++screen;
		if (buttonChoice >= button5Min && buttonChoice <= button5Max)
			break;
		switch (screen)
		{
		case 0:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("LVL:" + String(m_level));
			lcd.setCursor(0, 1);
			lcd.print("EXP:" + String(m_expCurrent) + '/' + String(m_expNext));
			break;
		case 1:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("EXP:" + String(m_expCurrent) + '/' + String(m_expNext));
			lcd.setCursor(0, 1);
			lcd.print("HP:" + String(m_health) + '/' + String(m_healthMax));
			break;
		case 2:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("HP:" + String(m_health) + '/' + String(m_healthMax));
			lcd.setCursor(0, 1);
			lcd.print("MAG:" + String(m_magic) + '/' + String(m_magicMax));
			break;
		case 3:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("MAG:" + String(m_magic) + '/' + String(m_magicMax));
			lcd.setCursor(0, 1);
			lcd.print("DMG:" + String(m_damageMin) + '-' + String(m_damageMax));
			break;
		case 4:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("DMG:" + String(m_damageMin) + '-' + String(m_damageMax));
			lcd.setCursor(0, 1);
			lcd.print("ACC:" + String(m_accuracy));
			break;
		case 5:
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("ACC:" + String(m_accuracy));
			lcd.setCursor(0, 1);
			lcd.print("DEF:" + String(m_defence));
			break;
		case 6:
			screen = 5;
			break;
		case -1:
			screen = 0;
			break;
		default:
			break;
		}
		delay(150);
	}
}

void User::viewEquipped()
{

	int screen{ 0 };
	while (true)
	{
		buttonChoice = analogRead(A0);
		if (buttonChoice >= button2Min && buttonChoice <= button2Max)
		{
			--screen;
		}
		if (buttonChoice >= button3Min && buttonChoice <= button3Max)
		{
			++screen;
		}
		if (buttonChoice >= button5Min && buttonChoice <= button5Max)
		{
			break;
		}
		switch (screen)
		{
		case 0:
			weapon.printItem();
			if (buttonChoice >= button1Min && buttonChoice <= button1Max)
			{
				addItem(weapon);
				weapon = Weapon("Fists", 1, 1, 2);
			}
			else if (buttonChoice >= button4Min && buttonChoice <= button4Max)
				weapon = Weapon("Fists", 1, 1, 2);
			break;
		case 1:
			armour.printItem();
			if (buttonChoice >= button1Min && buttonChoice <= button1Max)
			{
				addItem(armour);
				armour = Armour("Cloth", 1, 1);
			}
			else if (buttonChoice >= button4Min && buttonChoice <= button4Max)
				armour = Armour("Cloth", 1, 1);
			break;
		case 2:
			spell.printItem();
			if (buttonChoice >= button1Min && buttonChoice <= button1Max)
			{
				addItem(spell);
				spell = Spell("Dust", 1, 1, 0, 0);
			}
			else if (buttonChoice >= button4Min && buttonChoice <= button4Max)
				spell = Spell("Dust", 1, 1, 0, 0);
			break;
		case 3:
			screen = 2;
			break;
		case -1:
			screen = 0;
			break;
		default:
			break;
		}
		delay(150);
	}
}

void User::viewInventory()
{
	lcd.clear();
	int index{ 0 };
	while (true)
	{
		lcd.clear();
		if (getItemArr().size() == 0)
			break;
		else
			viewItem(index);
		buttonChoice = analogRead(A0);
		delay(200);
		if (buttonChoice >= button3Min && buttonChoice <= button3Max)
		{
			if (index + 1 >= getNumOfItem())
			{
				lcd.print("");
			}
			else
			{
				++index;
			}
			delay(200);
		}
		if (buttonChoice >= button2Min && buttonChoice <= button2Max)
		{
			if (index - 1 < 0)
			{
				lcd.print("");
			}
			else
			{
				--index;
			}
			delay(200);
		}
		if (buttonChoice >= button1Min && buttonChoice <= button1Max)
		{
			Armour* NewArm{ &Armour() };
			Weapon* NewWep{ &Weapon() };
			Potion* NewPotion{ &Potion() };
			Spell* NewSpell{ &Spell() };
			if (getItemArr()[index]->cloneItem()->getItemClass() == 4)
			{
				addItem(weapon);
				NewWep = (Weapon*)getItemArr()[index]->cloneItem();
				equipWeapon(*NewWep);

				lcd.setCursor(0, 0);
				lcd.print("You have equipped:");
				lcd.setCursor(0, 1);
				lcd.print(NewWep->getType());
			}
			if (getItemArr()[index]->cloneItem()->getItemClass() == 1)
			{
				addItem(armour);
				NewArm = (Armour*)getItemArr()[index]->cloneItem();
				equipArmour(*NewArm);

				lcd.setCursor(0, 0);
				lcd.print("You have equipped:");
				lcd.setCursor(0, 1);
				lcd.print(NewArm->getType());
			}
			if (getItemArr()[index]->cloneItem()->getItemClass() == 3)
			{
				addItem(spell);
				NewSpell = (Spell*)getItemArr()[index]->cloneItem();
				equipSpell(*NewSpell);

				lcd.setCursor(0, 0);
				lcd.print("You have equipped:");
				lcd.setCursor(0, 1);
				lcd.print(NewSpell->getType());
			}
			if (getItemArr()[index]->cloneItem()->getItemClass() == 2)
			{
				removeItem(index);
				NewPotion = (Potion*)getItemArr()[index]->cloneItem();
				usePotion(*NewPotion);

				lcd.setCursor(0, 0);
				lcd.print("You have used:");
				lcd.setCursor(0, 1);
				lcd.print(NewPotion->getType());
			}
		}
		if (buttonChoice >= button4Min && buttonChoice <= button4Max)
		{
			removeItem(index);
		}
		if (buttonChoice >= button5Min && buttonChoice <= button5Max)
		{
			break;
		}
	}
}

void User::manageInventory()
{
	while (true)
	{
		buttonChoice = analogRead(A0);
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("Equipped    Pack");
		delay(150);
		if (buttonChoice >= button1Min && buttonChoice <= button1Max)
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Equipped");
			delay(screenDelay);
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Unuse         Up");
			lcd.setCursor(0, 1);
			lcd.print("Drop        Down");
			delay(screenDelay);
			viewEquipped();
		}
		if (buttonChoice >= button2Min && buttonChoice <= button2Max)
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("            Pack");
			delay(screenDelay);
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Use           Up");
			lcd.setCursor(0, 1);
			lcd.print("Drop        Down");
			delay(screenDelay);
			viewInventory();
		}
		if (buttonChoice >= button5Min && buttonChoice <= button5Max)
		{ 
			break;;
		}
	}
}

void User::levelUp()
{
	while (m_expCurrent >= m_expNext)
	{
		m_expCurrent -= m_expNext;
		m_level++;
		m_expNext = static_cast<int>((50 / 3) * ((pow(m_level, 3) - 6 * pow(m_level, 2)) + 17 * m_level - 12) + 100);
		m_healthMax +=  (rand() % 8);
		m_magicMax += (rand() % 4);
	}
}