#include "Inventory.h"

Inventory::Inventory()
{
	m_bulk = 6; m_numOfItem = 0; m_itemArr.reserve(m_bulk);
}

Inventory::Inventory(std::vector<Item*> itemArr, int bulk, int numOfItem) : m_itemArr{ itemArr }, m_bulk{ bulk }, m_numOfItem{ numOfItem }
{  }

/*void Inventory::viewInv()
{
	int button{ 0 };
	int index{ 0 };
	while (true)
	{
		button = analogRead(A0);
		viewItem(index);
		delay(500);
		if (button >= button2Min && button <= button2Max)
			if (index + 1 > m_numOfItem)
			{
				;
			}
			else
				++index;

		else if (button >= button3Min && button <= button3Max)
			if (index - 1 < 0)
			{
				;
			}
			else
				--index;

		else if (button >= button5Min && button <= button5Max)
			break;
		delay(400);
	}
}*/

void Inventory::viewItem(int item)
{
	if (m_numOfItem - 1 < item - 1)
		std::cout << "No such item exists";
	else
	{
		std::cout << *m_itemArr[item]->cloneItem();
	}
}

void Inventory::addItem(const Item& item)
{
	if (m_numOfItem + 1 > m_bulk)
	{
		std::cout << "Not Enough Room!";
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
		std::cout << "No such item exists";
	else
	{
		m_itemArr.erase(m_itemArr.begin() + index - 1);
		m_numOfItem--;
	}
}

Inventory::~Inventory()
{

}