#pragma once

#include "Item.h"

class Spell : public Item
{
private:

	int m_damageMin;
	int m_damageMax;
	int m_magicCost;

public:

	Spell(String type = "",
		int level = 1,
		int magicaCost = 1,
		int damageMin = 1,
		int damageMax = 1);

	virtual Spell* cloneItem() const;
	virtual void printItem() const;
	virtual const int getItemClass() const { return SPELL; }
};

