#include "Country.h"

Country::Country(int i_NumOfCities, int i_NumOfRoads)
{
	m_NumOfCities = i_NumOfCities;
	m_NumOfRoads = i_NumOfRoads;
	m_CountryStructure = new City[i_NumOfCities];
}

void Country::AssignCountryStructure()
{
	m_CountryStructure = new City[m_NumOfCities];
}
