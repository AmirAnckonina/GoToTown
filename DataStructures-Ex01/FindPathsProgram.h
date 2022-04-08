#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "Country.h"
#include "AccessibleGroup.h"

//#define NOT_VALID -1

class FindPathsProgram
{

private:
	const int NOT_VALID = -1;

	Country m_Country;
	int m_CityCenter;

public:

	void run();
	void InputProcedure();
	AccessibleGroup GetToTownWrapper();
	//void GetToTown();
	void GetNumOfCitiesAndRoads();
	void InitCityPairsRoadsFromUser(vector<pair<int, int>>& i_CityPairs, int i_NumOfRoads);
	void GetCityCenterNumberFromUser();
	int GetNumberFromIndexInString(string i_Str, int& index);
	bool IsADigit(char ch);
	bool IsRoadExist(vector<pair<int, int>> i_CityPairs, pair<int, int> i_RoadPair);

	bool IsNumInRange(int num, int from, int to);

	void InvalidExit();


};