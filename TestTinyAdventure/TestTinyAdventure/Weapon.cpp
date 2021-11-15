#include "Weapon.h"

Weapon::Weapon(std::string type,
	int level,
	int damageMin,
	int damageMax) :

	Item(type,
		level),
	m_damageMin{ damageMin },
	m_damageMax{ damageMax }
{

}

Weapon* Weapon::cloneItem() const
{
	return new Weapon(*this);
}

void Weapon::printItem(Item& item) const
{
	std::cout << "Type: " << m_type << " Level: " << m_level << " Damage: " << m_damageMin << '-' << m_damageMax;
}