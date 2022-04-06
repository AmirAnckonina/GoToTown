#include "FindPathsProgram.h"


void FindPathsProgram::run()
{
	InputProcedure();
	//GetToTown

	//Should be returned -> AccessibleCities (namely, Linked-List without pointers)
}

void FindPathsProgram::InputProcedure()
{
	string inputRow;
	int nCity, nRoads;

	cout << "Please enter the number of cities in the country, and the number of the roads, separeted by space: " << endl;

	getline(cin, inputRow);
	if (!GetNumOfCitiesAndRoads(inputRow))
	{
		cout << "invalid input" << endl;
		exit(0);
	}

	m_Country.AssignCountryStructure();

	//------------------------------------//

	vector<pair<int, int>> cityPairs(m_Country.GetNumOfCities(), std::make_pair(0, 0));

	cout << "Please enter " << m_Country.GetNumOfRoads();
	cout << " pairs of cities (i.e.: A B), so each pair represent one-direction road from A to B: " << endl;

	getline(cin, inputRow);
	if (!InitCityPairsRoadsFromString(cityPairs, inputRow))
	{
		cout << "invalid input" << endl;
		exit(0);
	}

	m_Country.FillCountryStructureByCityPairs(cityPairs);
}

bool FindPathsProgram::GetNumOfCitiesAndRoads(string i_InputRow)
{
	int index = 0;
	int nCities = 0, mRoads = 0;
	bool isValidInput = true;

	nCities = GetNumberFromIndexInString(i_InputRow, index);
	mRoads = GetNumberFromIndexInString(i_InputRow, index);

	if (nCities != NOT_VALID && mRoads != NOT_VALID)
	{
		m_Country.SetNumOfCities(nCities);
		m_Country.SetNumOfRoads(mRoads);
	}
	else
		isValidInput = false;

	return isValidInput;
}

bool FindPathsProgram::InitCityPairsRoadsFromString(vector<pair<int, int>>& i_CityPairs, string i_InputRow)
{
	int strIndex = 0;

	for (int index = 0; index < i_CityPairs.size(); index++)
	{
		int fromCity = GetNumberFromIndexInString(i_InputRow, strIndex);
		int toCity = GetNumberFromIndexInString(i_InputRow, strIndex);

		if (fromCity == NOT_VALID || toCity == NOT_VALID || IsRoadExist(i_CityPairs, { fromCity, toCity }))
			return false;

		i_CityPairs[index].first = fromCity;
		i_CityPairs[index].second = toCity;
	}

	return true;
}

int FindPathsProgram::GetNumberFromIndexInString(string i_Str, int& index)
{
	int num = 0;
	int strLen = i_Str.length();

	while (index < strLen && i_Str[index] == ' ')
		index++;

	if (index == strLen || !IsADigit(i_Str[index]))
		return NOT_VALID;

	while (index < strLen && IsADigit(i_Str[index]))
	{
		num *= 10;
		num += i_Str[index] - '0';
		index++;
	}

	return num;
}

bool FindPathsProgram::IsADigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

bool FindPathsProgram::IsRoadExist(vector<pair<int, int>> i_CityPairs, pair<int, int> i_RoadPair)
{
	for (int index = 0; index < i_CityPairs.size(); index++)
	{
		if (i_CityPairs[index] == i_RoadPair)
			return true;
	}
	return false;
}
