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
	int GetNumOfRoads() { return m_NumOfCities; }
	void AssignCountryStructure();
	void FillCountryStructureByCityPairs(vector<pair<int, int>> i_CityPairs);

};
