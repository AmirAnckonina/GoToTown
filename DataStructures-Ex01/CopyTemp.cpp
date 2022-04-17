#pragma once

void FindPathsProgram::GetToTownRecursion(const City& i_CurrCityCenter)
{
	int currCityNum = i_CurrCityCenter.GetCityNumber();
	MyList cityAdjacentList = i_CurrCityCenter.GetAdjacentCitiesList();
	ListNode* currNodeInAdjCity = cityAdjacentList.GetDHead()->GetNextNode();
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