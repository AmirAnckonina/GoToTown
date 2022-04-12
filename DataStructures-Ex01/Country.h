#pragma once
#include "City.h"
#include <iostream>
#include <vector>

using namespace std;

class Country
{

private:
	int m_NumOfCities;
	int m_NumOfRoads;
	City* m_CountryStructure;

public:
	Country() {};
	Country(int i_NumOfCities, int i_NumOfRoads);
	void SetNumOfCities(int i_NumOfCities) { m_NumOfCities = i_NumOfCities; }
	int GetNumOfCities() { return m_NumOfCities; }
	void SetNumOfRoads(int i_NumOfRoads) { m_NumOfRoads = i_NumOfRoads; }
	const City& GetCityFromCountryStructure(int i_NumOfCity) { return m_CountryStructure[i_NumOfCity - 1]; }
	int GetNumOfRoads() { return m_NumOfRoads; }
	void AssignCountryStructure();
	void FillCountryStructureByCityPairs(vector<pair<int, int>> i_CityPairs);

};
