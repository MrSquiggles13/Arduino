#pragma once

#include "Item.h"

class Potion : public Item
{
private:
	int m_healthMod;
	int m_magicMod;
public:

	Potion(String type = "",
		int level = 1,
		int healthMod = 1,
		int magicMod = 1);

	virtual Potion* cloneItem() const;
	virtual void printItem() const;
	virtual const int getItemClass() const { return POTION; }

	inline const int getHpMod() const { return m_healthMod; }
	inline const int getMagicMod() const { return m_magicMod; }
};

