#include "FindPathsProgram.h"


void FindPathsProgram::run()
{
	InputProcedure();

	AccessibleGroup accessibleGrp = GetToTownWrapper();
	//GetToTown

	//Should be returned -> AccessibleCities (namely, Linked-List without pointers)
}

eColors* FindPathsProgram::BuildCitiesColorsArr()
{
	eColors* citiesColorsArr = new eColors[m_Country.GetNumOfCities()];

	for (int ind = 0; ind < m_Country.GetNumOfCities(); ind++)
	{
		citiesColorsArr[ind] = eColors::WHITE;
	}

	return citiesColorsArr;
}

AccessibleGroup FindPathsProgram::GetToTownWrapper()
{
	AccessibleGroup accessibleGrp;
	eColors* citiesColors = BuildCitiesColorsArr();
	//Recursive implementaion 
	//GetToTown(m_Country, m_CityCenter);
	return accessibleGrp;
}

void FindPathsProgram::GetToTown(const Country& i_Country,const City& i_CurrCityCenter, eColors& io_CitiesColors, AccessibleGroup& io_AccessGrp)
{
	//Implement 
}

void FindPathsProgram::InputProcedure()
{
	vector<pair<int, int>> cityPairs;
	GetNumOfCitiesAndRoads();
	m_Country.AssignCountryStructure();
	InitCityPairsRoadsFromUser(cityPairs, m_Country.GetNumOfRoads());
	m_Country.FillCountryStructureByCityPairs(cityPairs);
	GetCityCenterNumberFromUser();
}

void FindPathsProgram::GetNumOfCitiesAndRoads()
{
	string inputRow;

	int strIndex = 0;
	int nCities = 0, mRoads = 0;
	bool isValidInput = true;

	cout << "Please enter the number of cities in the country, and the number of the roads, separeted by space: " << endl;
	getline(cin, inputRow);

	nCities = GetNumberFromIndexInString(inputRow, strIndex);
	mRoads = GetNumberFromIndexInString(inputRow, strIndex);

	if (nCities != NOT_VALID && mRoads != NOT_VALID)
	{
		m_Country.SetNumOfCities(nCities);
		m_Country.SetNumOfRoads(mRoads);
	}
	else
		InvalidExit();
}

void FindPathsProgram::InitCityPairsRoadsFromUser(vector<pair<int, int>>& i_CityPairs, int i_NumOfRoads)
{
	string inputRow;
	int strIndex = 0;

	cout << "Please enter " << m_Country.GetNumOfRoads();
	cout << " pairs of cities (i.e.: A B), so each pair represent one-direction road from A to B: " << endl;
	getline(cin, inputRow);

	for (int index = 0; index < i_NumOfRoads; index++)
	{
		int fromCity = GetNumberFromIndexInString(inputRow, strIndex);
		int toCity = GetNumberFromIndexInString(inputRow, strIndex);

		//Adding check if the cities is in the country range.
		if (fromCity == NOT_VALID || toCity == NOT_VALID || IsRoadExist(i_CityPairs, { fromCity, toCity }))
			InvalidExit();
		else
			i_CityPairs.push_back({ fromCity, toCity });
	}
}

void FindPathsProgram::GetCityCenterNumberFromUser()
{
	string inputRow;
	int index = 0;

	cout << "Please enter the city center: ";
	getline(cin, inputRow);

	int cityCenterNum = GetNumberFromIndexInString(inputRow, index); // Needs to be VALID

	if (cityCenterNum != NOT_VALID && IsNumInRange(cityCenterNum, 1, m_Country.GetNumOfCities()))
		m_CityCenter = cityCenterNum;
	else
		InvalidExit();

}

int FindPathsProgram::GetNumberFromIndexInString(string i_Str, int& io_Index)
{
	int num = 0;
	int strLen = i_Str.length();

	while (io_Index < strLen && i_Str[io_Index] == ' ')
		io_Index++;

	if (io_Index == strLen || !IsADigit(i_Str[io_Index]))
		return NOT_VALID;

	while (io_Index < strLen && IsADigit(i_Str[io_Index]))
	{
		num *= 10;
		num += i_Str[io_Index] - '0';
		io_Index++;
	}

	return num;
}


bool FindPathsProgram::IsADigit(char i_Char)
{
	return (i_Char >= '0' && i_Char <= '9');
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

bool FindPathsProgram::IsNumInRange(int i_Num, int i_From, int i_To) {
	return (i_Num >= i_From && i_Num <= i_To);
}

void  FindPathsProgram::InvalidExit()
{
	cout << "invalid input" << endl;
	exit(0);
}