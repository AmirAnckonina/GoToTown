#pragma once
using namespace std;

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

class AccessibleGroup
{
private:
	struct AccessibleCityNode
	{
		int m_cityNumber;
		int m_nextInd;
	};

	vector<AccessibleCityNode> m_AccessibleCitiesListNoPtr;
	int m_ListLen;
	int m_HeadList;
	int m_HeadFree;
	int m_TailList;

public:
	AccessibleGroup();

	void SetListLen(int i_ListLen) { m_ListLen = i_ListLen; }
	int GetListLen() { return m_ListLen; }
	void SetHeadList(int i_HeadList) { m_HeadList = i_HeadList; }
	int GetHeadList() { return m_HeadList; }
	void SetTailList(int i_TailList) { m_TailList = i_TailList; }
	int GetTailList() { return m_TailList; }
	void SetHeadFree(int i_HeadFree) { m_HeadFree = i_HeadFree; }
	int GetHeadFree() { return m_HeadFree; }
	//void allocateList(int i_Len);
	void AddCityToList(int i_NewCityNumber);
};

