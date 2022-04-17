#pragma once

#include "ItemType.h"

class StackNode
{
private:
	ItemType m_Item;
	StackNode* m_NextNode;

	friend class Stack;

public:
	StackNode() : m_NextNode(nullptr) {}
	StackNode(ItemType i_NewItem, StackNode* i_NodePtr = nullptr);


};

