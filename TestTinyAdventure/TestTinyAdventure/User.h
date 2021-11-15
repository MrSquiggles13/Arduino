#pragma once
#include "Inventory.h"
#include "Weapon.h"
#include "Armour.h"



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
};

