#pragma once

using namespace std;

template<typename T>

struct UnidirectionalCLNode

{

	T data;

	UnidirectionalCLNode* ptrnext;

	UnidirectionalCLNode* ptrprev;

};

template<typename T>

class UnidirectionalCL

{

private:

	UnidirectionalCLNode<T>* first;

	UnidirectionalCLNode<T>* last;

public:

	UnidirectionalCL()

	{

		first = nullptr;

		last = nullptr;

	}

	~UnidirectionalCL()

	{

		while (first != last)

		{

			UnidirectionalCLNode<T>* tmp = first;

			first = first->ptrprev;

			delete tmp;

		}

		delete last;

	}

	void AddBack(T dt)

	{

		UnidirectionalCLNode<T>* newlink = new UnidirectionalCLNode<T>;

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

	void AddFront(T dt)

	{

		UnidirectionalCLNode<T>* newlink = new UnidirectionalCLNode<T>;

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

	T RemoveFront()

	{

		T data = first->data;

		DeleteLink(first);

		return data;

	}

	T RemoveBack()

	{

		T data = last->data;

		DeleteLink(last);

		return data;

	}

	T ElementAt(int index)

	{

		if (index > Length()) return -1;

		UnidirectionalCLNode<T>* temp = first;

		int i = 0;

		do

		{

			if (i == index) return temp->data;

			temp = temp->ptrprev;

			i++;

		} while (temp != first);

	}

	void DeleteLink(UnidirectionalCLNode<T>* temp)

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

	UnidirectionalCL operator=(UnidirectionalCL& l)

	{

		if (l.first)

		{

			UnidirectionalCLNode<T>* temp = l.first;

			do

			{

				AddFront(temp->data);

				temp = temp->ptrprev;

			} while (temp != l.first);

		}

		return *this;

	}

	int Length()

	{

		if (first)

		{

			UnidirectionalCLNode<T>* temp = first;

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

	void Clear()

	{

		while (first->ptrprev != last)

		{

			UnidirectionalCLNode<T>* temp = first->ptrprev;

			first = first->ptrprev;

			delete temp;

		}

		last = nullptr;

		first = nullptr;

	}

};
