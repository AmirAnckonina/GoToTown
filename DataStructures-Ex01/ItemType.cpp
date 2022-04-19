#include "ItemType.h"

ItemType::ItemType(const City* i_City, ListNode* i_CurrAdjCityNode, eLine i_Line)
{
	m_CityCenter = i_City;
	m_CurrAdjCityNode = i_CurrAdjCityNode;
	m_CurrLine = i_Line;
}

void ItemType::CreateItemType(const City* i_City, eLine i_Line)
{
	m_CityCenter = i_City;
	m_CurrLine = i_Line;
}
