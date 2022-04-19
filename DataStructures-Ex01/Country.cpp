#include "Country.h"

Country::Country()
{
	m_NumOfCities = 0;
	m_NumOfRoads = 0;
	m_CountryStructure = nullptr;
}

Country::Country(int i_NumOfCities, int i_NumOfRoads)
{
	m_NumOfCities = i_NumOfCities;
	m_NumOfRoads = i_NumOfRoads;
	m_CountryStructure = new City[i_NumOfCities];
}

void Country::AssignCountryStructure()
{
	m_CountryStructure = new City[m_NumOfCities];

	//Fill cities numbers in city structure.
	for (int index = 0; index < m_NumOfCities; index++) 
		m_CountryStructure[index].SetCityNumber(index + 1); //Cities numbers between 1->n.
	
}

void Country::FillCountryStructureByCityPairs(vector<pair<int, int>> i_CityPairs)
{
	pair<int, int> nullRoad = { 0,0 };

	for (int index = 0; index < i_CityPairs.size(); index++)
	{
		pair<int, int> currRoad = i_CityPairs[index];
		int fromCityNum = currRoad.first, toCityNum = currRoad.second;

		if (currRoad != nullRoad)
		{
			ListNode* newCityNode = new ListNode(toCityNum); // New list node contain the ajdacent city number.
			ListNode* currAdjCityTail = m_CountryStructure[fromCityNum - 1].GetAdjacentCitiesList()->GetTail();
			m_CountryStructure[fromCityNum - 1].AddAdjacentCityToList(newCityNode, currAdjCityTail); // Adding the adjacent city to the current adjacent cities list.
		}
	}
}
