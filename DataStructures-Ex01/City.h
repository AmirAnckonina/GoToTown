
#pragma once

#include "MyList.h"

class City
{

private:

	friend class Country;

	int m_CityNumber;
	MyList m_AdjacentCities;


public:

	void SetCityNumber(int i_NewCityNumber) { m_CityNumber = i_NewCityNumber; }
	int GetCityNumber() { return m_CityNumber; }
};