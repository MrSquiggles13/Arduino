#pragma once

#include <iostream>
#include <string>

class Item
{
protected:

	std::string m_type;
	int m_level;

public:

	Item(std::string type = "",
		int level = 0);

	virtual Item* cloneItem() const = 0;
	virtual void printItem(Item& item) const = 0;

	friend void operator<<(std::ostream& out, Item& item);

	inline const std::string& getType() const { return m_type; }
};

