#pragma once

#include <iostream>

#include "UnidirectionalCL.h"

using namespace std;

template<typename T>

class Queue

{

private:

	UnidirectionalCL<T> *arr;

	int size = 0;

public:

	Queue(); //инициализация

	Queue(const Queue &other); //копирование

	Queue(Queue &&other); //перемещение

	Queue &operator=(const Queue &other); //присваивание

	Queue &operator=(Queue &&other); //присваивание с еремещением

	~Queue(); //деструктор

	int GetSize();

	void Push(T element); //Вставка (добавление) элемента

	T Pop(); //Удаление (взятие) элемента

	T Peek(); //Просмотр (взятие без удаления) элемента

	friend ostream & operator << <T>(ostream & stream, const Queue<T> &a); //Вывод

};

template<typename T>

Queue<T>::Queue()

{

	arr = new UnidirectionalCL<T>();

	size = 0;

}

template<typename T>

Queue<T>::~Queue()

{

	delete arr;

}

template<typename T>

Queue<T>::Queue(const Queue &other)

{

	arr = new UnidirectionalCL<T>();

	size = other.size;

	for (int i = 0; i < size; ++i)

		arr->AddBack(other.arr->ElementAt(size - i - 1));

}

template<typename T>

Queue<T> &Queue<T>::operator=(const Queue &other)

{

	if (this == &other) return *this;

	arr = new UnidirectionalCL<T>();

	size = other.size;

	for (int i = 0; i < size; ++i)

		arr->AddFront(other.arr->ElementAt(i));

}

template<typename T>

Queue<T> &Queue<T>::operator=(Queue &&other)

{

	if (this == &other) return *this;

	delete arr;

	arr = other.arr;

	size = other.size;

	other.arr = nullptr;

}

template<typename T>

Queue<T>::Queue(Queue &&other)

{

	arr = other.arr;

	size = other.size;

	other.arr = nullptr;

}

template<typename T>

int Queue<T>::GetSize()

{

	return size;

}

template<typename T>

void Queue<T>::Push(T element)

{

	arr->AddFront(element);

	size++;

}

template<typename T>

T Queue<T>::Pop()

{

	if (size > 0)

	{

		T element = arr->RemoveFront();

		size--;

		return element;

	}

	return 0;

}

template<typename T>

T Queue<T>::Peek()

{

	T element = arr->RemoveBack();

	arr->AddBack(element);

	return element;

}

template<typename T>

ostream & operator<<(ostream & stream, const Queue<T> &other)

{

	Queue<T> *b = new Queue<T>(other);

	while (b->size > 0)

	{

		stream << b->Pop() << " ";

	}

	return stream;

}
