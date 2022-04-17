#pragma once

#include "City.h"

class ItemType
{
public:
	enum eLines { START, AFTER_FIRST, AFTER_SECOND };

private:
	City m_CityCenter;
	eLines m_Line;

public:
	ItemType(const City& i_City, eLines i_Line); // Not a problem with copy Ctor!?
};

