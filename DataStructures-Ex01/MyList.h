#pragma once
#include "ListNode.h"

class MyList
{
	ListNode* m_DHead = new ListNode();
	ListNode* m_Tail = m_DHead; //Check! -Added for the first adding to list 
	//Test

public:

	~MyList();
	void MakeEmpty();
	bool IsEmpty();
	void DeleteAfter(ListNode* i_ToDeleteAfter);
	void InsertAfter(ListNode* i_NewNode, ListNode* i_AfterNode);
	ListNode* GetDHead() { return m_DHead; }
	ListNode* GetTail() { return m_Tail; }
};
