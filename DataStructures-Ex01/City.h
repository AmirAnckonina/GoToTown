
#pragma once

#include "MyList.h"

class City
{

private:

	int m_CityNumber;
	MyList m_AdjacentCities;

	friend class Country;

public:

	void SetCityNumber(int i_NewCityNumber) { m_CityNumber = i_NewCityNumber; }
	int GetCityNumber() { return m_CityNumber; }
};