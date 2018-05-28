#pragma once

#include <iostream>

#include "UnidirectionalCL.h"

class Queue

{

private:

	UnidirectionalCL * arr;

	int size = 0;

public:

	Queue();

	Queue(const Queue &other);

	Queue(Queue &&other);

	Queue &operator=(const Queue &other);

	Queue &operator=(Queue &&other);

	~Queue();

	int GetSize();

	void Push(const int element);

	int Pop();

	int Peek();

	friend ostream & operator<<(ostream & stream, const Queue &other);

};
