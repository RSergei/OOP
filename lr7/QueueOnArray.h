#pragma once

#include <iostream>

#include "QueueBase.h"

using namespace std;

template<typename T>

class QueueOnArray : public QueueBase<T>

{

	T *array;

	int count;

	int end = 0, start = 0, size = 0;

public:

	QueueOnArray(int count); //инициализация

	QueueOnArray(const QueueOnArray &other); //копирование

	QueueOnArray(QueueOnArray &&other); //перемещение

	QueueOnArray &operator=(const QueueOnArray &other); //присваивание

	QueueOnArray &operator=(QueueOnArray &&other); //присваивание с еремещением

	~QueueOnArray();

	int GetSize() override

	{

		return size;

	}

	void Push(T element) override //Вставка элемента

	{

		if (size < count)

		{

			array[end] = element;

			end = (end + 1) % count;

			size++;

		}

	}

	T Pop() override //Взятие элемента

	{

		if (size > 0)

		{

			T element = array[start];

			start = (start + 1) % count;

			size--;

			return element;

		}

		return 0;

	}

	T Peek() override //Просмотр элемента

	{

		return array[start];

	}

	friend ostream & operator << <T>(ostream & stream, const QueueOnArray<T> &a);

};

template<typename T>

QueueOnArray<T>::QueueOnArray(int size)

{

	count = size;

	array = new T[count];

}

template<typename T>

QueueOnArray<T>::QueueOnArray(const QueueOnArray &other)

{

	array = new T[other.count];

	count = other.count;

	end = other.end;

	start = other.start;

	size = other.size;

	for (int i = 0; i < count; ++i)

		array[i] = other.array[i];

}

template<typename T>

QueueOnArray<T>::QueueOnArray(QueueOnArray &&other)

{

	array = other.array;

	count = other.count;

	other.array = nullptr;

}

template<typename T>

QueueOnArray<T>::~QueueOnArray()

{

	delete[] array;

}

template<typename T>

QueueOnArray<T> &QueueOnArray<T>::operator=(const QueueOnArray &other)

{

	if (this == &other) return *this;

	delete[] array;

	array = new T[other.count];

	count = other.count;

	for (int i = 0; i < count; ++i)

		array[i] = other.array[i];

}

template<typename T>

QueueOnArray<T> &QueueOnArray<T>::operator=(QueueOnArray &&other)

{

	if (this == &other) return *this;

	delete[] array;

	array = other.array;

	count = other.count;

	other.array = nullptr;

}

template<typename T>

ostream & operator<<(ostream &stream, const QueueOnArray<T> &a)

{

	QueueOnArray<T> b = a;

	for (int i = 0; i < b.count; i++)

		stream << b.Pop() << " ";

	return stream;

}
