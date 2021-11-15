#pragma once
#include <vector>
#include "Item.h"

class Inventory
{
private:
	std::vector<Item*> m_itemArr;
	int m_bulk;
	int m_numOfItem;


public:
	Inventory();
	Inventory(std::vector<Item*> itemArr, int bulk = 6, int numOfItem = 0);

	//void viewInv();
	void addItem(const Item& item);
	void removeItem(int index);
	void viewItem(int index);

	inline std::vector<Item*> getItemArr() const { return m_itemArr; }
	inline const int getNumOfItem() const { return m_numOfItem; }
	inline const int getBulk() const { return m_bulk; }

	~Inventory();
};

