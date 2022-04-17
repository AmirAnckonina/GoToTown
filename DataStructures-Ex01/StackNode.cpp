#include "StackNode.h"

StackNode::StackNode(ItemType i_NewItem, StackNode* i_NodePtr)
{
	m_Item = i_NewItem;
	m_NextNode = i_NodePtr;
}
