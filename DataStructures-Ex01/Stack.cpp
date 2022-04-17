#include "Stack.h"

bool Stack::IsEmpty()
{
	return (m_Top == nullptr ? true : false);
}

void Stack::MakeEmpty()
{
	StackNode* temp;

	while (m_Top != nullptr)
	{
		temp = m_Top;
		m_Top = m_Top->m_NextNode;
		delete temp;
	}
}

void Stack::Push(ItemType i_NewItem)
{
	m_Top = new StackNode(i_NewItem, m_Top);
}

ItemType Stack::Pop()
{
	if (IsEmpty())
		StackError(); 

	StackNode * temp = m_Top;
	ItemType item = m_Top->m_Item; //?

	m_Top = m_Top->m_NextNode;
	delete(temp);

	return item;;
}

void Stack::StackError()
{
	std::cout << "Invalid procedure!" << std::endl;
	exit(0);
}
