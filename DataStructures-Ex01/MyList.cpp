#include "MyList.h"

MyList::MyList()
{
	m_DHead = new ListNode();
	m_Tail = m_DHead;
}

MyList::~MyList()
{
	MakeEmpty();
}

void MyList::MakeEmpty()
{
	ListNode* currNode = m_DHead;
	while (currNode->m_NextNode != nullptr)
	{
		DeleteAfter(currNode);
	}
	delete m_DHead;
}

bool MyList::IsEmpty()
{
	return m_DHead->m_NextNode == nullptr;
}

void MyList::DeleteAfter(ListNode* i_ToDeleteAfter)
{
	if (i_ToDeleteAfter->m_NextNode == nullptr)
		return;

	ListNode* newNext = i_ToDeleteAfter->m_NextNode->m_NextNode;
	delete(i_ToDeleteAfter->m_NextNode);

	i_ToDeleteAfter->m_NextNode = newNext;

	if (newNext == nullptr)
		m_Tail = i_ToDeleteAfter;

	if (IsEmpty())
		m_Tail = nullptr;
}

void MyList::InsertAfter(ListNode* i_NewNode, ListNode* i_AfterNode)
{
	i_NewNode->m_NextNode = i_AfterNode->m_NextNode;
	i_AfterNode->m_NextNode = i_NewNode;

	if (i_NewNode->m_NextNode == nullptr)
		m_Tail = i_NewNode;
}
