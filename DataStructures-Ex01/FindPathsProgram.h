#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "Country.h"

class FindPathsProgram
{

private:
	Country m_Country;

	const int NOT_VALID = -1;

public:
	void run();
	void InputProcedure();

	bool GetNumOfCitiesAndRoads(string i_InputRow);
	bool InitCityPairsRoadsFromString(vector<pair<int, int>>& cityPairs, string i_InputRow);
	int GetNumberFromIndexInString(string i_Str, int& index);
	bool IsADigit(char ch);
	bool IsRoadExist(vector<pair<int, int>> i_CityPairs, pair<int, int> i_RoadPair);


};