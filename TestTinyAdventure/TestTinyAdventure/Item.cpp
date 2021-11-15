#include "Item.h"

void operator<<(std::ostream& out, Item& item)
{
	return item.printItem(*item.cloneItem());
}

Item::Item(std::string type,
	int level) :
	m_type{ type },
	m_level{ level }
{

}