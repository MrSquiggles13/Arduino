#pragma once

#include "Item.h"

class Armour : public Item
{
private:

	int m_defence;

public:

	Armour(String type = "",
		int level = 1,
		int defence = 1);

	virtual Armour* cloneItem() const;
	virtual void printItem() const;
	virtual const int getItemClass() const { return ARMOUR; }

	inline const int getDefence() const { return m_defence; }
};

