#include "AccessibleCitiesGroup.h"

AccessibleGroup::AccessibleGroup()
{
	//m_AccessibleCitiesListNoPtr = nullptr;
	m_ListLen = 0;
	m_HeadList = m_HeadFree = 0;
}

void AccessibleGroup::AddCityToList(int i_NewCityNumber)
{
	//Build node
	AccessibleCityNode newCityNode;
	newCityNode.m_cityNumber = i_NewCityNumber;
	newCityNode.m_nextInd = -1;

	//Add node to list
	//We want to insert the new node in the headFree index.
	int indToInsert = m_HeadFree;
	m_AccessibleCitiesListNoPtr[m_HeadFree].m_nextInd = m_HeadFree;
	m_AccessibleCitiesListNoPtr[m_HeadFree] = newCityNode;

}


