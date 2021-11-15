#include "Potion.h"

Potion::Potion(String type,
	int level,
	int healthMod,
	int magicMod) :

	Item(type,
		level),
	m_healthMod{ healthMod },
	m_magicMod{ magicMod }
{

}

Potion* Potion::cloneItem() const
{
	return new Potion(*this);
}

void Potion::printItem() const
{
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(m_type + " Level: " + String(m_level));
	lcd.setCursor(0, 1);
	if(m_magicMod == 0)
		lcd.print("Health: " + String(m_healthMod));
	if (m_healthMod)
		lcd.print("Magic: " + String(m_magicMod));
}