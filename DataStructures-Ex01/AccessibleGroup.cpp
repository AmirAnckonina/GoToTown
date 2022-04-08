#include "AccessibleGroup.h"

AccessibleGroup::AccessibleGroup()
{
	//m_AccessibleCitiesListNoPtr = nullptr;
	m_ListLen = 0;
	m_HeadListInd = m_HeadFreeInd = 0;
	m_TailListInd = m_TailFreeInd = 0;
}

AccessibleGroup::AccessibleGroup(int i_NumOfCitiesInCountry)
{
	m_ListLen = 0; 
	m_HeadFreeInd = 0;
	m_TailFreeInd = i_NumOfCitiesInCountry - 1;
	m_HeadListInd = m_TailListInd = EMPTY;
	m_AccessibleCitiesListNoPtr.reserve(i_NumOfCitiesInCountry);
}

AccessibleGroup::AccessibleCityNode AccessibleGroup::CreateCityNode(int i_NewCityNumber)
{
	AccessibleCityNode newCityNode;

	newCityNode.m_CityNumber = i_NewCityNumber;
	newCityNode.m_NextInd = FULL_FLAG;

	return newCityNode;
}

void AccessibleGroup::AddCityToList(int i_NewCityNumber)
{
	
	//Create node
	AccessibleCityNode newCityNode = CreateCityNode(i_NewCityNumber);


	int indToInsert = m_HeadFreeInd; //Temporary index holder

	//No spcace left in the list.
	if (indToInsert == FULL_FLAG)
	{
		cout << "Sorry, there no place in the list";
		exit(1);
		//exception instead ???
	}

	if (m_HeadListInd == EMPTY) //List is empty
		m_HeadListInd = m_TailListInd = m_HeadFreeInd; //Set new head

	m_HeadFreeInd = m_AccessibleCitiesListNoPtr[m_HeadFreeInd].m_NextInd; //Set a new HeadFree to the current List.
	m_AccessibleCitiesListNoPtr[indToInsert] = newCityNode;
	m_AccessibleCitiesListNoPtr[m_TailListInd].m_NextInd = indToInsert; //Update the tail of the list to point the new node
	m_TailListInd = indToInsert; //Update the Tail to be the "just-added" node
}




