#pragma once
#include "Item.h"


class Weapon : public Item
{
private:

	int m_damageMin;
	int m_damageMax;

public:

	Weapon(std::string type = "",
		int level = 1,
		int damageMin = 1,
		int damageMax = 1);

	virtual Weapon* cloneItem() const;
	virtual void printItem(Item& item) const;
};

