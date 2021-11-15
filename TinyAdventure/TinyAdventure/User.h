#pragma once

#include <LiquidCrystal.h>
#include <Arduino.h>
#include "Inventory.h"
#include "Weapon.h"
#include "GlobalBoys.h"
#include "Spell.h"
#include "Armour.h"
#include "Potion.h"



class User : public Inventory
{
private:
	
	int m_level;
	int m_expCurrent;
	int m_expNext;
	int m_health;
	int m_healthMax;
	int m_magic;
	int m_magicMax;
	int m_damageMin;
	int m_damageMax;
	int m_accuracy;
	int m_defence;

	Inventory inventory;
	Weapon weapon;
	Armour armour;
	Spell spell;

public:
	User(int level = 1,
	int expCurrent = 0,
	int expNext = 100,
	int health = 20,
	int healthMax = 20,
	int magic = 10,
	int magicMax = 10,
	int damageMin = 1,
	int damageMax = 3,
	int accuracy = 2,
	int defence = 1);
	
	void createCharacter();
	void printStats();
	void viewEquipped();
	void viewInventory();
	void manageInventory();
	void levelUp();

	inline void equipWeapon(Weapon wep) { weapon = wep; m_damageMin = wep.getDamageMin(); m_damageMax = wep.getDamageMax(); }
	inline void equipArmour(Armour arm) { armour = arm; m_defence = arm.getDefence();}
	inline void equipSpell(Spell spl) { spell = spl;}
	inline void usePotion(Potion potion)
	{
		if (potion.getHpMod() != 0)
		{
			if (m_health + potion.getHpMod() > m_healthMax)
				m_health = m_healthMax;
			else
				m_health += potion.getHpMod();
		}
		else if (potion.getMagicMod() != 0)
		{
			if (m_magic + potion.getMagicMod() > m_magicMax)
				m_magic = m_magicMax;
			else
				m_magic += potion.getMagicMod();
		}
	}

};

