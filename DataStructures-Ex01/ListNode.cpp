#include "ListNode.h"

ListNode::ListNode(int i_NeighborCityNumber, ListNode* i_NodePtr)
{
	m_NeighborCityNumber = i_NeighborCityNumber;
	m_NextNode = i_NodePtr;
}

//ListNode::~ListNode()
//{
//	delete m_NextNode;
//}
