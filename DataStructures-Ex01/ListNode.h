#pragma once

class ListNode
{
private:

	int m_NeighborCityNumber = 0;
	ListNode* m_NextNode;
	friend class MyList;

public:

	ListNode() : m_NextNode(nullptr) {}
	ListNode(int i_NeighborCityNumber, ListNode* i_NodePtr = nullptr);

	int GetNeighborCityNumber() { return m_NeighborCityNumber; }
	ListNode* GetNextNode() const { return m_NextNode; }
};
