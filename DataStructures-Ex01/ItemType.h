#pragma once

#include "City.h"
#include "eLine.h"

class ItemType
{

private:
	City& m_CityCenter; //Should be by ref?
	ListNode* m_CurrAdjCityNode;
	eLine m_CurrLine;

public:
	ItemType() : m_CurrLine(eLine::NONE) {}
	ItemType(const City& i_City, ListNode* i_CurrAdjCityNode, eLine i_Line); // Not a problem with copy Ctor!?

	ItemType operator=(ItemType otherItem);
	const City& GetCityCenter() { return m_CityCenter; }

	void SetCurrLine(eLine i_NewCurrLine) { m_CurrLine = i_NewCurrLine; }
	eLine GetCurrLine() { return m_CurrLine; }

	void SetCurrAdjCityNode(ListNode* i_NewCurrAdjCityNode) { m_CurrAdjCityNode = i_NewCurrAdjCityNode; }
	ListNode* GetCurrAdjCityNode() { return m_CurrAdjCityNode; };

	void CreateItemType(const City& i_City, eLine i_Line);
};

