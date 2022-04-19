#include "AccessibleGroup.h"

AccessibleGroup::AccessibleGroup()
{
	m_HeadListInd = m_TailListInd = EMPTY;
	m_HeadFreeInd = m_TailFreeInd = EMPTY;
}


AccessibleGroup::AccessibleCityNode AccessibleGroup::CreateCityNode(int i_CityNumber, int i_NextInd)
{
	AccessibleCityNode newCityNode;

	newCityNode.m_CityNumber = i_CityNumber;
	newCityNode.m_NextInd = i_NextInd;

	return newCityNode;
}

void AccessibleGroup::AddCityToList(int i_NewCityNumber)
{

	//Create node
	AccessibleCityNode newCityNode = CreateCityNode(i_NewCityNumber);

	int indToInsert = m_HeadFreeInd; //Temporary index holder

	//No spcace left in the list.
	if (indToInsert == ENDOFLIST)
	{
		cout << "Sorry, there no place in the list";
		exit(1);
	}

	if (m_HeadListInd == EMPTY) //List is empty
	{
		m_HeadListInd = m_TailListInd = m_HeadFreeInd; //Set new head
	}

	else //In case it's not the first node inserted
	{
		m_AccessibleCitiesListArr[m_TailListInd].m_NextInd = indToInsert; //Update the tail of the list to point the new node
	}

	m_HeadFreeInd = m_AccessibleCitiesListArr[m_HeadFreeInd].m_NextInd; //Set a new HeadFree to the current List.
	m_AccessibleCitiesListArr[indToInsert] = newCityNode;
	m_TailListInd = indToInsert; //Update the Tail to be the "just-added" node


}

void AccessibleGroup::InitAccessibleCitiesListArr(int i_NumOfCitiesInCountry)
{
	m_HeadFreeInd = 0;
	m_TailFreeInd = i_NumOfCitiesInCountry - 1;

	for (int i = 0; i < i_NumOfCitiesInCountry; i++)
	{
		AccessibleCityNode newCityNode;

		if (i == i_NumOfCitiesInCountry - 1)
			newCityNode = CreateCityNode(0);
		else
			newCityNode = CreateCityNode(0, i + 1);

		m_AccessibleCitiesListArr.push_back(newCityNode);
	}

}

void AccessibleGroup::PrintListArr(bool i_IsIterativePrint, int i_CityCenter) const
{
	int currNodeInd = m_HeadListInd;

	if (m_HeadListInd != EMPTY)
	{
		if (i_IsIterativePrint)
			std::cout << "Cities accessible from city source city " << i_CityCenter << " (iterative algorithm): ";
		else
			std::cout << "Cities accessible from source city " << i_CityCenter << " (recursive algorithm): ";

		while (currNodeInd != ENDOFLIST)
		{
			std::cout << m_AccessibleCitiesListArr[currNodeInd].m_CityNumber << " ";
			currNodeInd = m_AccessibleCitiesListArr[currNodeInd].m_NextInd;
		}
		std::cout << endl;
	}
}





