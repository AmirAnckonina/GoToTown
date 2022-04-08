#pragma once
using namespace std;

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
//#include "AccessibleCityNode.h"



class AccessibleGroup
{

private:
	const int EMPTY = -10;
	const int FULL_FLAG = -1;
	struct AccessibleCityNode
	{
		int m_CityNumber;
		int m_NextInd;
	};

	vector<AccessibleCityNode> m_AccessibleCitiesListNoPtr;

	int m_ListLen;
	int m_HeadListInd, m_TailListInd;
	int m_HeadFreeInd, m_TailFreeInd;

public:
	//C'tors
	AccessibleGroup();
	AccessibleGroup(int i_ListLen);

	AccessibleCityNode CreateCityNode(int i_NewCityNumber);
	void AddCityToList(int i_NewCityNumber);

	//Get-Set
	void SetListLen(int i_ListLen) { m_ListLen = i_ListLen; }
	int GetListLen() { return m_ListLen; }
	void SetHeadList(int i_HeadList) { m_HeadListInd = i_HeadList; }
	int GetHeadList() { return m_HeadListInd; }
	void SetTailList(int i_TailList) { m_TailListInd = i_TailList; }
	int GetTailList() { return m_TailListInd; }
	void SetHeadFree(int i_HeadFree) { m_HeadFreeInd = i_HeadFree; }
	int GetHeadFree() { return m_HeadFreeInd; }
	//void allocateList(int i_Len);
};

