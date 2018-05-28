#include "UnidirectionalCL.h"

UnidirectionalCL::UnidirectionalCL()

{

	first = nullptr;

	last = nullptr;

}

UnidirectionalCL::~UnidirectionalCL()

{

	while (first != last)

	{

		UnidirectionalCLNode* tmp = first;

		first = first->ptrprev;

		delete tmp;

	}

	delete last;

}

void UnidirectionalCL::AddBack(int dt)

{

	UnidirectionalCLNode* newlink = new UnidirectionalCLNode;

	newlink->data = dt;

	if (first)

	{

		newlink->ptrprev = first;

		first->ptrnext = newlink;

	}

	else last = newlink;

	newlink->ptrnext = last;

	last->ptrprev = newlink;

	first = newlink;

}

void UnidirectionalCL::AddFront(int dt)

{

	UnidirectionalCLNode* newlink = new UnidirectionalCLNode;

	newlink->data = dt;

	if (last)

	{

		newlink->ptrnext = last;

		last->ptrprev = newlink;

	}

	else first = newlink;

	newlink->ptrprev = first;

	first->ptrnext = newlink;

	last = newlink;

}

int UnidirectionalCL::RemoveFront()

{

	int data = first->data;

	DeleteLink(first);

	return data;

}

int UnidirectionalCL::RemoveBack()

{

	int data = last->data;

	DeleteLink(last);

	return data;

}

int UnidirectionalCL::ElementAt(int index)

{

	if (index > Length()) return -1;

	UnidirectionalCLNode* temp = first;

	int i = 0;

	do

	{

		if (i == index) return temp->data;

		temp = temp->ptrprev;

		i++;

	} while (temp != first);

}

void UnidirectionalCL::DeleteLink(UnidirectionalCLNode* temp)

{

	if (first)

	{

		if (temp->ptrnext == temp)

		{

			first = nullptr;

			last = nullptr;

		}

		else

		{

			if (temp == last) last = last->ptrnext;

			if (temp == first) first = first->ptrprev;

			(temp->ptrnext)->ptrprev = temp->ptrprev;

			(temp->ptrprev)->ptrnext = temp->ptrnext;

			delete temp;

		}

	}

}

UnidirectionalCL UnidirectionalCL::operator=(UnidirectionalCL& l)

{

	if (l.first)

	{

		UnidirectionalCLNode* temp = l.first;

		do

		{

			AddFront(temp->data);

			temp = temp->ptrprev;

		} while (temp != l.first);

	}

	return *this;

}

int UnidirectionalCL::Length()

{

	if (first)

	{

		UnidirectionalCLNode* temp = first;

		int i = 0;

		do

		{

			temp = temp->ptrprev;

			i++;

		} while (temp != first);

		return i;

	}

	else return 0;

}

void UnidirectionalCL::Clear()

{

	while (first->ptrprev != last)

	{

		UnidirectionalCLNode* temp = first->ptrprev;

		first = first->ptrprev;

		delete temp;

	}

	last = nullptr;

	first = nullptr;

}