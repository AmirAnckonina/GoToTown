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

	//Init cities numbers in city structure.
	for (int index = 0; index < m_NumOfCities; index++) {
		m_CountryStructure[index].m_CityNumber = index + 1; //Cities numbers between 1->n.
	}
}

void Country::FillCountryStructureByCityPairs(vector<pair<int, int>> i_CityPairs)
{
	pair<int, int> nullRoad = { 0,0 };

	for (int index = 0; index < i_CityPairs.size(); index++)
	{
		pair<int, int> currRoad = i_CityPairs[index];
		int fromCityNum = currRoad.first, toCityNum = currRoad.second;

		if (currRoad != nullRoad)
		{   // Need to check if adjacent city already exist in list ?!
			MyList currCityList = m_CountryStructure[fromCityNum - 1].m_AdjacentCities; // Getting the adjacent cities list of current city.
			ListNode* newCityNode = new ListNode(toCityNum); // New list node contain the ajdacent city number.

			currCityList.InsertAfter(newCityNode, currCityList.GetTail()); // Adding the adjacent city to the current adjacent cities list.
		}
	}
}
