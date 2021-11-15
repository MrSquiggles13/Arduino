#include "Inventory.h"

Inventory::Inventory()
{
	m_bulk = 6; m_numOfItem = 0; m_itemArr.reserve(m_bulk);
}

Inventory::Inventory(std::vector<Item*> itemArr, int bulk, int numOfItem) : m_itemArr{ itemArr }, m_bulk{ bulk }, m_numOfItem{ numOfItem }
{  }



void Inventory::viewItem(int item)
{
	if (m_numOfItem < item)
	{
		lcd.print("No such item exists");
		delay(500);
	}
	else
	{
		m_itemArr[item]->cloneItem()->printItem();
	}
}

void Inventory::addItem(Item& item)
{
	if (m_numOfItem + 1 > m_bulk)
	{
		lcd.clear();
		lcd.print("Not Enough Room!");
		delay(500);
	}
	else
	{
		m_itemArr.push_back(item.cloneItem());
		m_numOfItem++;
	}
}

void Inventory::removeItem(int index)
{
	if (m_numOfItem - 1 < index)
		lcd.print("No such item exists");
	else
	{
		m_itemArr.erase(m_itemArr.begin() + index - 1);
		m_numOfItem--;
	}
}

Inventory::~Inventory()
{

}