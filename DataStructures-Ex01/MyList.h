#pragma once
#include "ListNode.h"
#include <iostream>



class MyList
{

private:
	ListNode* m_DHead; 
	ListNode* m_Tail; 


public:
	MyList();
	~MyList();
	void MakeEmpty();
	bool IsEmpty();
	void DeleteAfter(ListNode* i_ToDeleteAfter);
	void InsertAfter(ListNode* i_NewNode, ListNode* i_AfterNode);
	ListNode* GetDHead() const { return m_DHead; }
	ListNode* GetTail() const { return m_Tail; }
	
};
