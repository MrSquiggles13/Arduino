#pragma once

#include "Item.h"


class Weapon : public Item
{
private:

	int m_damageMin;
	int m_damageMax;

public:

	Weapon(String type = "",
		int level = 1,
		int damageMin = 1,
		int damageMax = 1);

	Weapon(int level);

	virtual Weapon* cloneItem() const;
	virtual void printItem() const;
	virtual const int getItemClass() const { return WEAPON; }

	static std::vector<Weapon> commonWep;
	static std::vector<Weapon> rareWep;
	static std::vector<Weapon> epicWep;

	static void listWeapons();

	inline const int getDamageMin() const { return m_damageMin; }
	inline const int getDamageMax() const { return m_damageMax; }
};

