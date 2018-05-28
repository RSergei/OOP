#pragma once

#include <iostream>

#include "QueueBase.h"

#include "UnidirectionalCL.h"

using namespace std;

template<typename T>

class QueueOnUnidirectionalCL : public QueueBase<T>

{

	UnidirectionalCL<T> *arr;

	int size = 0;

public:

	QueueOnUnidirectionalCL(); //�������������

	QueueOnUnidirectionalCL(const QueueOnUnidirectionalCL &other); //�����������

	QueueOnUnidirectionalCL(QueueOnUnidirectionalCL &&other); //�����������

	QueueOnUnidirectionalCL &operator=(const QueueOnUnidirectionalCL &other); //������������

	QueueOnUnidirectionalCL &operator=(QueueOnUnidirectionalCL &&other); //������������ � �����������

	~QueueOnUnidirectionalCL();

	int GetSize() override

	{

		return size;

	}

	void Push(T element) override //������� (����������) ��������

	{

		arr->AddFront(element);

		size++;

	}

	T Pop() override //�������� (������) ��������

	{

		if (size > 0)

		{

			T element = arr->RemoveFront();

			size--;

			return element;

		}

		return 0;

	}

	T Peek() override //�������� (������ ��� ��������) ��������

	{

		T element = arr->RemoveBack();

		arr->AddBack(element);

		return element;

	}

	friend ostream & operator << <T>(ostream & stream, const QueueOnUnidirectionalCL<T> &a); //�����

};

template<typename T>

QueueOnUnidirectionalCL<T>::QueueOnUnidirectionalCL()

{

	arr = new UnidirectionalCL<T>();

	size = 0;

}

template<typename T>

QueueOnUnidirectionalCL<T>::QueueOnUnidirectionalCL(const QueueOnUnidirectionalCL &other)

{

	arr = new UnidirectionalCL<T>();

	size = other.size;

	for (int i = 0; i < size; ++i)

		arr->AddBack(other.arr->ElementAt(size - i - 1));

}

template<typename T>

QueueOnUnidirectionalCL<T>::QueueOnUnidirectionalCL(QueueOnUnidirectionalCL &&other)

{

	arr = other.arr;

	size = other.size;

	other.arr = nullptr;

}

template<typename T>

QueueOnUnidirectionalCL<T>::~QueueOnUnidirectionalCL()

{

	delete arr;

}

template<typename T>

QueueOnUnidirectionalCL<T> &QueueOnUnidirectionalCL<T>::operator=(const QueueOnUnidirectionalCL &other)

{

	if (this == &other) return *this;

	arr = new UnidirectionalCL<T>();

	size = other.size;

	for (int i = 0; i < size; ++i)

		arr->AddFront(other.arr->ElementAt(i));

}

template<typename T>

QueueOnUnidirectionalCL<T> &QueueOnUnidirectionalCL<T>::operator=(QueueOnUnidirectionalCL &&other)

{

	if (this == &other) return *this;

	delete arr;

	arr = other.arr;

	size = other.size;

	other.arr = nullptr;

}

template<typename T>

ostream & operator<<(ostream & stream, const QueueOnUnidirectionalCL<T> &other)

{

	QueueOnUnidirectionalCL<T> *b = new QueueOnUnidirectionalCL<T>(other);

	while (b->size > 0)

	{

		stream << b->Pop() << " ";

	}

	return stream;

}