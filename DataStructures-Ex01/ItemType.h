#pragma once

#include "City.h"

class ItemType
{
public:
	enum eLines { START, AFTER_FIRST, AFTER_SECOND, NONE };

private:
	City m_CityCenter; //Should be by ref?
	eLines m_Line;

public:
	ItemType() : m_Line(NONE) {}
	ItemType(const City& i_City, eLines i_Line); // Not a problem with copy Ctor!?
};

