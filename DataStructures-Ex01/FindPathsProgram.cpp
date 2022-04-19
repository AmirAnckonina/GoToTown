#include "FindPathsProgram.h"


void FindPathsProgram::run()
{
	//This function at first run the recursive solution, then the iterative one.
	//Each solution has it own data members.
	//Note that the accessibleCities list is a DATA-MEMBER which updated during the functions, and NOT "returned" from the functions.

	InputProcedure();

	//<----Recursive------>
	m_CitiesColorsRecursion = BuildCitiesColorsArr();
	m_AccessGrpRecursion.InitAccessibleCitiesListArr(m_Country.GetNumOfCities());
	GetToTownRecursion(m_Country.GetCityFromCountryStructure(m_CityCenter));
	m_AccessGrpRecursion.PrintListArr();

	//<----Iterative------>
	m_CitiesColorsIterative = BuildCitiesColorsArr();
	m_AccessGrpIterative.InitAccessibleCitiesListArr(m_Country.GetNumOfCities());
	GetToTownIterative();
	m_AccessGrpIterative.PrintListArr();
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

void FindPathsProgram::GetToTownRecursion(const City* i_CurrCityCenter)
{
	int currCityNum = i_CurrCityCenter->GetCityNumber();
	const MyList* cityAdjacentList = i_CurrCityCenter->GetAdjacentCitiesList();
	ListNode* currNodeInAdjCity = cityAdjacentList->GetDHead()->GetNextNode();
	int neighborCityNum;

	m_CitiesColorsRecursion[currCityNum - 1] = eColors::BLACK;
	m_AccessGrpRecursion.AddCityToList(currCityNum);

	while (currNodeInAdjCity != NULL)
	{
		neighborCityNum = currNodeInAdjCity->GetCityNumber();
		if (m_CitiesColorsRecursion[neighborCityNum - 1] == eColors::WHITE)
		{
			GetToTownRecursion(m_Country.GetCityFromCountryStructure(neighborCityNum));
		}

		currNodeInAdjCity = currNodeInAdjCity->GetNextNode();
	}

	return;
}

void FindPathsProgram::GetToTownIterative()
{
	Stack itemsStack;
	ListNode* currNodeInAdjCity = m_Country.GetCityFromCountryStructure(m_CityCenter)->GetAdjacentCitiesList()->GetDHead();
	ItemType curr(m_Country.GetCityFromCountryStructure(m_CityCenter), currNodeInAdjCity, eLine::START);

	itemsStack.Push(curr);

	while (!itemsStack.IsEmpty())
	{
		curr = itemsStack.Pop();

		if (curr.GetCurrLine() == eLine::START)
		{
			if (m_CitiesColorsIterative[(curr.GetCityCenter().GetCityNumber() - 1)] == eColors::WHITE)
			{
				// Make BLACK && Add to AccessibleCities
				m_CitiesColorsIterative[(curr.GetCityCenter().GetCityNumber() - 1)] = eColors::BLACK;
				m_AccessGrpIterative.AddCityToList(curr.GetCityCenter().GetCityNumber());
				currNodeInAdjCity = curr.GetCurrAdjCityNode()->GetNextNode();

				//Execute "Recursion" only if the adjCityNode isn't NULL
				if (currNodeInAdjCity != NULL) 
				{
					curr.SetCurrLine(eLine::AFTER_REC);
					itemsStack.Push(curr);
					ItemType next(m_Country.GetCityFromCountryStructure(currNodeInAdjCity->GetCityNumber()), 
						m_Country.GetCityFromCountryStructure(currNodeInAdjCity->GetCityNumber())->GetAdjacentCitiesList()->GetDHead(), eLine::START);
					itemsStack.Push(next);
				}
			}
		}

		else if (curr.GetCurrLine() == eLine::AFTER_REC)
		{
			//Check whteher the nextNode is NULL.
			if (curr.GetCurrAdjCityNode()->GetNextNode() != NULL)
			{	
				currNodeInAdjCity = curr.GetCurrAdjCityNode()->GetNextNode();
				curr.SetCurrAdjCityNode(currNodeInAdjCity); //Already with the correct City and Line.
				itemsStack.Push(curr);
				ItemType next(m_Country.GetCityFromCountryStructure(currNodeInAdjCity->GetCityNumber()),
					m_Country.GetCityFromCountryStructure(currNodeInAdjCity->GetCityNumber())->GetAdjacentCitiesList()->GetDHead(), eLine::START);
				itemsStack.Push(next);
			}
		}
	}
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

void FindPathsProgram::InitCityPairsRoadsFromUser(vector<pair<int, int>>& io_CityPairs, int i_NumOfRoads)
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
		if (fromCity == NOT_VALID || toCity == NOT_VALID)
			InvalidExit();
		else if (!IsRoadExist(io_CityPairs, { fromCity, toCity })) 
			io_CityPairs.push_back({ fromCity, toCity });
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

void FindPathsProgram::InvalidExit()
{
	cout << "invalid input" << endl;
	exit(0);
}