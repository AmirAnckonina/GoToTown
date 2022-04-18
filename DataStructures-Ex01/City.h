
#pragma once

#include "MyList.h"

class City
{

private:
	friend class Country;
	int m_CityNumber;
	MyList* m_AdjacentCities;

public:

	City();
	void SetCityNumber(int i_NewCityNumber) { m_CityNumber = i_NewCityNumber; }
	int GetCityNumber() const { return m_CityNumber; }
	const MyList* GetAdjacentCitiesList() const { return m_AdjacentCities; }
	void AddAdjacentCityToList(ListNode* i_NewNode, ListNode* i_AfterNode);
};