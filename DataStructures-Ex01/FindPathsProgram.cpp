#include "FindPathsProgram.h"


void FindPathsProgram::run()
{
	InputProcedure();
}

void FindPathsProgram::InputProcedure()
{
	int nCity, nRoads;

	cout << "Please enter the number of cities in the country, and the number of the roads, separeted by space: " << endl;
	cin >> nCity >> nRoads;
	m_Country.SetNumOfCities(nCity);
	m_Country.SetNumOfRoads(nRoads);
	m_Country.AssignCountryStructure();

	//------------------------------------//

	vector<pair<int, int>> cityPairs(nRoads,std::make_pair(0, 0));

	cout << "Please enter " << nRoads;
	cout << " pairs of cities (i.e.: A B), so each pair represent one-direction road from A to B: " << endl;
	
	for (int index = 0; index < nRoads; index++)
	{
		//Add input check
		int cityA, cityB;
		cin >> cityA >> cityB;
		cityPairs.push_back({ cityA, cityB });
		//Another vector check
	}

	//FillCountryStructureByCityPairs(cityPairs);
}