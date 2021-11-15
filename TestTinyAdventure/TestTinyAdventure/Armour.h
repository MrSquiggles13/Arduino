#pragma once
#include "Item.h"

class Armour : public Item
{
private:

	int m_defence;

public:

	Armour(std::string type = "",
		int level = 1,
		int defence = 1);

	virtual Armour* cloneItem() const;
	virtual void printItem(Item& item) const;
};

