#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "Country.h"
#include "AccessibleGroup.h"



enum class eColors {BLACK, WHITE};

class FindPathsProgram
{
public:
	const int NOT_VALID = -1;


private:
	Country m_Country;
	int m_CityCenter;

public:
	void run();
	void InputProcedure();
	//void BuildCitiesColorsArr(eColors& i_CitiesColors);
	eColors* BuildCitiesColorsArr();
	
	AccessibleGroup GetToTownWrapper();
	void GetToTown(const Country& i_Country, const City& i_CurrCityCenter, eColors& io_CitiesColors, AccessibleGroup* io_AccessGrp);
	void GetNumOfCitiesAndRoads();
	void InitCityPairsRoadsFromUser(vector<pair<int, int>>& i_CityPairs, int i_NumOfRoads);
	void GetCityCenterNumberFromUser();
	int GetNumberFromIndexInString(string i_Str, int& index);
	bool IsADigit(char ch);
	bool IsRoadExist(vector<pair<int, int>> i_CityPairs, pair<int, int> i_RoadPair);
	bool IsNumInRange(int num, int from, int to);
	void InvalidExit();


};