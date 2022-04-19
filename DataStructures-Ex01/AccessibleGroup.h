#pragma once
using namespace std;

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

class AccessibleGroup
{
public:
	static constexpr int EMPTY = -10;
	static constexpr int ENDOFLIST = -1;

private:
	struct AccessibleCityNode
	{
		int m_CityNumber;
		int m_NextInd;
	};

	vector<AccessibleCityNode> m_AccessibleCitiesListArr;
	int m_HeadListInd, m_TailListInd;
	int m_HeadFreeInd, m_TailFreeInd;

public:
	AccessibleGroup();
	AccessibleCityNode CreateCityNode(int i_CityNumber, int i_NextInd = ENDOFLIST);
	void AddCityToList(int i_NewCityNumber);
	void InitAccessibleCitiesListArr(int i_NumOfCitiesInCountry);
	void SetHeadList(int i_HeadList) { m_HeadListInd = i_HeadList; }
	int GetHeadList() { return m_HeadListInd; }
	void SetTailList(int i_TailList) { m_TailListInd = i_TailList; }
	int GetTailList() { return m_TailListInd; }
	void SetHeadFree(int i_HeadFree) { m_HeadFreeInd = i_HeadFree; }
	int GetHeadFree() { return m_HeadFreeInd; }
	void PrintListArr(bool i_IsIterativePrint, int i_CityCenter) const;

};

