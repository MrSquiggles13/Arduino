#include "Spell.h"

Spell::Spell(String type,
	int level,
	int magicCost,
	int damageMin,
	int damageMax) :

	Item(type,
		level),
	m_magicCost{ magicCost },
	m_damageMin{ damageMin },
	m_damageMax{ damageMax }
{

}

Spell* Spell::cloneItem() const
{
	return new Spell(*this);
}

void Spell::printItem() const
{
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(m_type + " Level: " + String(m_level));
	lcd.setCursor(0, 1);
	lcd.print("Damage: " + String(m_damageMin) + '-' + String(m_damageMax));
	delay(750);
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(m_type + " Level: " + String(m_level));
	lcd.setCursor(0, 1);
	lcd.print("Magic Cost: " + String(m_magicCost));
	delay(750);
}