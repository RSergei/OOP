#include "Queue.h"

Queue::Queue()

{

	arr = new UnidirectionalCL();

	size = 0;

}

Queue::~Queue()

{

	delete arr;

}

Queue::Queue(const Queue &other)

{

	arr = new UnidirectionalCL();

	size = other.size;

	for (int i = 0; i < size; ++i)

		arr->AddBack(other.arr->ElementAt(size - i - 1));

}

Queue::Queue(Queue &&other)

{

	arr = other.arr;

	size = other.size;

	other.arr = nullptr;

}

Queue &Queue::operator=(const Queue &other)

{

	if (this == &other) return *this;

	arr = new UnidirectionalCL();

	size = other.size;

	for (int i = 0; i < size; ++i)

		arr->AddFront(other.arr->ElementAt(i));

}

Queue &Queue::operator=(Queue &&other)

{

	if (this == &other) return *this;

	delete arr;

	arr = other.arr;

	size = other.size;

	other.arr = nullptr;

}

int Queue::GetSize()

{

	return size;

}

void Queue::Push(int element)

{

	arr->AddFront(element);

	size++;

}

int Queue::Pop()

{

	if (size > 0)

	{

		int element = arr->RemoveFront();

		size--;

		return element;

	}

	return 0;

}

int Queue::Peek()

{

	int element = arr->RemoveBack();

	arr->AddBack(element);

	return element;

}

ostream& operator<<(ostream & stream, const Queue &other)

{

	Queue *b = new Queue(other);

	while (b->size >0)

	{

		stream << b->Pop() << " ";

	}

	return stream;

}