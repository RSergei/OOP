#pragma once
#include "Storage.h"
#include "BidirectionalCircularList.h"
template<typename T>
class QueueBasedOnBidirectionalCircularList : public Storage<T>
{
	BidirectionalCircularList<T> *Queue;
	int count;
public:
	QueueBasedOnBidirectionalCircularList(int count)
		: Queue(), count(count) { }
	QueueBasedOnBidirectionalCircularList(const QueueBasedOnBidirectionalCircularList &other) //конструктор копирования
	{
		Queue = other.Queue;
		count = other.count;
	}
	QueueBasedOnBidirectionalCircularList(QueueBasedOnBidirectionalCircularList &&other)
	{
		Queue = other.Queue;
		count = other.count;
	}
	QueueBasedOnBidirectionalCircularList<T> &operator=(const QueueBasedOnBidirectionalCircularList &other)
	{
		if (this == &other)
		{
			return *this;
		}
		count = other.count;
		Queue = other.Queue;
	}
	QueueBasedOnBidirectionalCircularList<T> &operator=(QueueBasedOnBidirectionalCircularList &&other)
	{
		if (this == &other)
		{
			return *this;
		}
		count = other.count;
		Queue = other.Queue;
	}

	~QueueBasedOnBidirectionalCircularList();

	void Push(T element) override  //Вставка (добавление) элемента
	{
		if (Queue->GetSize() < count)
		{
			Queue->Push(element, Queue->GetSize());
		}
	}

	T Pop() override  //Удаление (взятие) элемента
	{
		return Queue->Remove(1);
	}

	T Peek() override  //Просмотр (взятие без удаления) элемента
	{
		return Queue->Peek(1);
	}

	bool CheckNoEmptyQueue() override  //Проверка наличия элементов
	{
		return Queue->CheckNoEmptyList();
	}

	friend ostream & operator << <T>(ostream & stream, const QueueBasedOnBidirectionalCircularList<T> &a); //Вывод
};
template<typename T>
QueueBasedOnBidirectionalCircularList<T>::~QueueBasedOnBidirectionalCircularList()
{
	delete Queue;
}
template<typename T>
ostream & operator << (ostream & stream, const QueueBasedOnBidirectionalCircularList<T> &a) //Вывод
{
	QueueBasedOnBidirectionalCircularList<T> b = a;
	stream << "=====\n";
	for (int i = 0; i < b.count; i++)
	{
		stream << "| " << b.Pop() << "\n";
	}
	stream << "=====\n";
	return stream;
}