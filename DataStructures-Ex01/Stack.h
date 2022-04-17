#pragma once

#include "StackNode.h"

class Stack
{
private:
	StackNode* m_Top;

public:
	Stack() { m_Top = nullptr; } // Necessary?
	~Stack() { MakeEmpty(); }

	bool IsEmpty();
	void MakeEmpty();
	void Push(ItemType i_NewItem);
	ItemType Pop();
	ItemType Top() { return m_Top->m_Item; }
};

