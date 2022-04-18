#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "Country.h"
#include "AccessibleGroup.h"
#include "Stack.h"
#include "ItemType.h"



enum class eColors {BLACK, WHITE};

class FindPathsProgram
{
public:
	const int NOT_VALID = -1;


private:
	Country m_Country;
	int m_CityCenter;
	AccessibleGroup m_AccessGrpRecursion;
	AccessibleGroup m_AccessGrpIterative;
	eColors* m_CitiesColorsRecursion;
	eColors* m_CitiesColorsIterative;


public:
	void run();
	void InputProcedure();
	//void BuildCitiesColorsArr(eColors& i_CitiesColors);
	eColors* BuildCitiesColorsArr();
	void GetToTownRecursion(const City* i_CurrCityCenter);
	void GetToTownIterative();
	void GetNumOfCitiesAndRoads();
	void InitCityPairsRoadsFromUser(vector<pair<int, int>>& i_CityPairs, int i_NumOfRoads);
	void GetCityCenterNumberFromUser();
	int GetNumberFromIndexInString(string i_Str, int& index);
	bool IsADigit(char ch);
	bool IsRoadExist(vector<pair<int, int>> i_CityPairs, pair<int, int> i_RoadPair);
	bool IsNumInRange(int num, int from, int to);
	void InvalidExit();


};
