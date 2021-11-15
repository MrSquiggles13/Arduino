#include "Armour.h"

Armour::Armour(String type,
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

void Armour::printItem() const
{
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(m_type + " Level: " + String(m_level));
	lcd.setCursor(0, 1);
	lcd.print("Defence: " + String(m_defence));
}