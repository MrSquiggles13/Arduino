#include "Armour.h"

Armour::Armour(std::string type,
	int level,
	int defence) :

	Item(type,
		level),
	m_defence{ defence }
{

}

Armour* Armour::cloneItem() const
{
	return new Armour(*this);
}

void Armour::printItem(Item& item) const
{
	std::cout << "type: " << m_type << "level: " << m_level;
}