#pragma once

class ListNode
{
private:

	int m_CityNumber = 0;
	ListNode* m_NextNode;
	friend class MyList;

public:

	ListNode() : m_CityNumber(0), m_NextNode(nullptr) {}
	ListNode(int i_NeighborCityNumber, ListNode* i_NodePtr = nullptr);

	int GetCityNumber() { return m_CityNumber; }
	ListNode* GetNextNode() const { return m_NextNode; }
};
