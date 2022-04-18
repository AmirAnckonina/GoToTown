#include "City.h"

City::City()
{
	m_CityNumber = 0;
	m_AdjacentCities = new MyList;
}

void City::AddAdjacentCityToList(ListNode* i_NewNode, ListNode* i_AfterNode)
{
	m_AdjacentCities->InsertAfter(i_NewNode, i_AfterNode);
}
