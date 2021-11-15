#include "Weapon.h"

Weapon::Weapon(String type,
	int level,
	int damageMin,
	int damageMax) :

	Item(type,
		level),
	m_damageMin{ damageMin },
	m_damageMax{ damageMax }
{

}

Weapon::Weapon(int level) : Item(level)
{
	int rarity;
	rarity = rand() % 3 + 1;
	if (rarity != 1)
	{
		rarity = rand() % 3 + 1;
		if (rarity != 1)
		{
			rarity = rand() % 3 + 1;
			if (rarity == 3)
				rarity = rand() % 3 + 1;
		}
	}

	if (level < 4)
	{
		int randLevel = (rand() % (level + 2)) + 1;
		if (randLevel > level)
			int randLevel = (rand() % (level + 2)) + 1;
		m_level = randLevel;
	}
	else
	{
		int randLevel = (rand() % (level + 2)) + (level - 3);
		if (randLevel > level)
			int randLevel = (rand() % (level + 2)) + (level - 3);
		m_level = randLevel;
	}
	int randType;
	if (rarity == 1)
	{
		randType = (rand() % (Weapon::commonWep.size() - 1));
		m_type = Weapon::commonWep[randType].getType();
	}

	if (rarity == 2)
	{
		randType = (rand() % (Weapon::rareWep.size() - 1));
		m_type = Weapon::rareWep[randType].getType();
	}

	if (rarity == 3)
	{
		randType = (rand() % (Weapon::epicWep.size() - 1));
		m_type = Weapon::epicWep[randType].getType();
	}

	m_damageMax = rand() % (static_cast<int>(((31.0 / 1295.0 * m_level * m_level + 9881.0 / 11655.0 * m_level + 7292.0 / 2331.0) * (1.0 / 30.0 * rarity * rarity * 11.0 / 30.0 * rarity + 3.0 / 5.0)) * 1.25)) + (static_cast<int>(((31.0 / 1295.0 * m_level * m_level + 9881.0 / 11655.0 * m_level + 7292.0 / 2331.0) * (1.0 / 30.0 * rarity * rarity * 11.0 / 30.0 * rarity + 3.0 / 5.0)) * 0.75));
	m_damageMin = m_damageMax / 2 + (m_damageMax / 4);
}
Weapon* Weapon::cloneItem() const
{
	return new Weapon(*this);
}

std::vector<Weapon> Weapon::commonWep;
std::vector<Weapon> Weapon::rareWep;
std::vector<Weapon> Weapon::epicWep;

void Weapon::listWeapons()
{
	Weapon::commonWep.push_back(Weapon("Sword"));
	Weapon::commonWep.push_back(Weapon("Pike"));
	Weapon::commonWep.push_back(Weapon("Knives"));
	Weapon::commonWep.push_back(Weapon("Cane"));
	Weapon::commonWep.push_back(Weapon("Bow"));
	Weapon::commonWep.push_back(Weapon("Club"));

	Weapon::rareWep.push_back(Weapon("Gladius"));
	Weapon::rareWep.push_back(Weapon("Trident"));
	Weapon::rareWep.push_back(Weapon("Dirks"));
	Weapon::rareWep.push_back(Weapon("Staff"));
	Weapon::rareWep.push_back(Weapon("Recurve"));
	Weapon::rareWep.push_back(Weapon("Mace"));

	Weapon::epicWep.push_back(Weapon("Katana"));
	Weapon::epicWep.push_back(Weapon("Glaive"));
	Weapon::epicWep.push_back(Weapon("Kukris"));
	Weapon::epicWep.push_back(Weapon("Baston"));
	Weapon::epicWep.push_back(Weapon("Yumi"));
	Weapon::epicWep.push_back(Weapon("Flail"));
}

void Weapon::printItem() const
{
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(m_type + " Level: " + String(m_level));
	lcd.setCursor(0, 1);
	lcd.print(" Damage: " + String(m_damageMin) + '-' + String(m_damageMax));
	delay(500);
}

