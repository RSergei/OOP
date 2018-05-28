#pragma once
#include "Node.h"
template<typename T>
class UnidirectionalList
{
	Node<T> *head;
	Node<T> *tail;
	int size = 0;
public:
	UnidirectionalList(); //инициализация
	UnidirectionalList(const UnidirectionalList &other);  //копирование
	UnidirectionalList(UnidirectionalList &&other); //перемещение
	UnidirectionalList &operator=(const UnidirectionalList &other); //присваивание
	UnidirectionalList &operator=(UnidirectionalList &&other); //присваивание с еремещением
	~UnidirectionalList(); //деструктор
	int GetSize();
	Node<T> *Find(int number);
	void Push(T element, int number);  //Вставка (добавление) элемента
	T Remove(int number);  //Удаление (взятие) элемента
	T Peek(int number);  //Просмотр (взятие без удаления) элемента
	bool CheckNoEmptyList();  //Проверка наличия элементов
	friend ostream & operator << <T>(ostream & stream, const UnidirectionalList<T> &a); //Вывод
};
template<typename T>
UnidirectionalList<T>::UnidirectionalList()
	: head(NULL)
{
	head = new Node<T>;
	tail = new Node<T>;
	head->next = tail;
}
template<typename T>
UnidirectionalList<T>::~UnidirectionalList() //деструктор
{
	Node<T> *node = head;
	while (node->next != tail)
	{
		Node<T> *deleteNode = node;
		node = node->next;
		delete deleteNode;
	}
	delete node;
	delete tail;
}
template<typename T>
UnidirectionalList<T>::UnidirectionalList(const UnidirectionalList &other) //конструктор копирования
{
	Node<T> oldOldNode = other.head;
	head = other.head;
	tail = other.tail;
	size = other.size;
	Node<T> newOldNode = head;
	while (newOldNode->next != tail)
	{
		Node<T> *newNewNode;
		newOldNode->next = newNewNode;
		newOldNode = newOldNode->next;
		oldOldNode = oldOldNode->next;
		newOldNode->data = oldOldNode->data;
	}
	newOldNode->next = tail;
}
template<typename T>
UnidirectionalList<T>::UnidirectionalList(UnidirectionalList &&other) //перемещение
{
	head = other.head;
	tail = other.tail;
	size = other.size;
	other.head = nullptr;
}
template<typename T>
UnidirectionalList<T> &UnidirectionalList<T>::operator=(const UnidirectionalList &other) //присваивание
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	delete tail;
	head = new Node<T>;
	tail = new Node<T>;
	Node<T> *node = head;
	while (node->next != tail)
	{
		Node<T> *newNode = new Node<T>;
		Node<T> *oldNode = node->next;
		node->next = newNode;
		newNode->data = oldNode->data;
	}
	node->next = tail;
}
template<typename T>
UnidirectionalList<T> &UnidirectionalList<T>::operator=(UnidirectionalList &&other) //присваивание с перемещением
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	head = other.head;
	other.head = nullptr;
}
template<typename T>
int UnidirectionalList<T>::GetSize()
{
	return this->size;
}
template<typename T>
Node<T> *UnidirectionalList<T>::Find(int number)
{
	Node<T> *node = head;
	for (int i = 0; i < number; i++)
	{
		node = node->next;
	}
	return node;
}
template<typename T>
void UnidirectionalList<T>::Push(T element, int number)  //Вставка (добавление) элемента
{
	Node<T> *previousNode = this->Find(number);
	Node<T> *nextNode = previousNode->next;
	Node<T> *newNode = new Node<T>;
	newNode->data = element;
	previousNode->next = newNode;
	newNode->next = nextNode;
	size++;
}
template<typename T>
T UnidirectionalList<T>::Remove(int number)  //Удаление (взятие) элемента
{
	if ((size > 0) && (number > 0) && (number <= size))
	{
		Node<T> *oldNode = this->Find(number);
		Node<T> *nextNode = oldNode->next;
		Node<T> *previousNode = this->Find(number - 1);
		T element = oldNode->data;
		previousNode->next = nextNode;
		delete oldNode;
		size--;
		return element;
	}
	return 0;
}
template<typename T>
T UnidirectionalList<T>::Peek(int number)  //Просмотр (взятие без удаления) элемента
{
	Node<T> *node = this->Find(number);
	return node->data;
}
template<typename T>
bool UnidirectionalList<T>::CheckNoEmptyList()  //Проверка наличия элементов
{
	return (size > 0);
}
template<typename T>
ostream & operator << (ostream & stream, const UnidirectionalList<T> &a) //Вывод
{
	UnidirectionalList<T> b = a;
	stream << "=====\n";
	for (int i = 0; i < b.size; i++)
	{
		stream << "| " << b.Remove() << "\n";
	}
	stream << "=====\n";
	return stream;
}