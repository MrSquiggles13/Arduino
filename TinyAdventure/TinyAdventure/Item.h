#pragma once

#include "Arduino.h"
#include "ArduinoSTL.h"
#include "GlobalBoys.h"
#include <LiquidCrystal.h>

class Item
{
protected:

	String m_type;
	int m_level;

public:

	enum itemType
	{
		ARMOUR = 1,
		POTION = 2,
		SPELL = 3,
		WEAPON = 4
	};

	Item(String type = "",
		int level = 0);

	Item(int level);

	virtual Item* cloneItem() const = 0;
	virtual void printItem() const = 0;

	virtual const int getItemClass() const = 0;

	inline const String& getType() const { return m_type; }
};

