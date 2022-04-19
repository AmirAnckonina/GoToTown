#pragma once

#include "City.h"
#include "eLine.h"

class ItemType
{

private:
	const City* m_CityCenter; 
	ListNode* m_CurrAdjCityNode;
	eLine m_CurrLine;

public:
	ItemType() : m_CityCenter(nullptr), m_CurrAdjCityNode(nullptr), m_CurrLine(eLine::NONE) {}
	ItemType(const City* i_City, ListNode* i_CurrAdjCityNode, eLine i_Line); 
	const City& GetCityCenter() { return *m_CityCenter; }
	void SetCurrLine(eLine i_NewCurrLine) { m_CurrLine = i_NewCurrLine; }
	eLine GetCurrLine() { return m_CurrLine; }
	void SetCurrAdjCityNode(ListNode* i_NewCurrAdjCityNode) { m_CurrAdjCityNode = i_NewCurrAdjCityNode; }
	ListNode* GetCurrAdjCityNode() { return m_CurrAdjCityNode; };
	void CreateItemType(const City* i_City, eLine i_Line);
};

