#include "ItemType.h"

ItemType::ItemType(const City& i_City, ListNode* i_CurrAdjCityNode, eLine i_Line)
{
	m_CityCenter = i_City;
	m_CurrAdjCityNode = i_CurrAdjCityNode;
	m_CurrLine = i_Line;
}

ItemType ItemType::operator=(ItemType otherItem)
{
	if (this != &otherItem)
	{
		this->m_CityCenter = otherItem.GetCityCenter();
		this->m_CurrLine = otherItem.GetCurrLine();
	}

	return *this;

}

void ItemType::CreateItemType(const City& i_City, eLine i_Line)
{
	m_CityCenter = i_City;
	m_CurrLine = i_Line;
}
