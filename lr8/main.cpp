#include "Queue.h"
#include "QueueBasedOnArray.h"
#include "QueueBasedOnUnidirectionalList.h"
#include "QueueBasedOnBidirectionalCircularList.h"
#include "FactoryMethod.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	int n = 10;
	//патерн "Стратегия"
	Queue<int> test;

	QueueBasedOnArray<int> test1(n);
	QueueBasedOnUnidirectionalList<int> test2(n);
	QueueBasedOnBidirectionalCircularList<int> test3(n);
	
	test.setStrategy(&test1);
	test.Push(20);
	test.Push(30);
	cout << test.Pop() << "\n"; 
	cout << test.Peek() << "\n"; 

	test.setStrategy(&test2);
	test.Push(33);
	test.Push(61);
	cout << test.Pop() << "\n";
	cout << test.Peek() << "\n"; 

	test.setStrategy(&test3);
	test.Push(100);
	test.Push(55);
	cout << test.Pop() << "\n";
	cout << test.Peek() << "\n";
	delete &test;
	//патерн "Фабричный метод"
	ConcreteCreatorQueueBasedOnArray<int> Creator1;
	ConcreteCreatorQueueBasedOnUnidirectionalList<int> Creator2;
	ConcreteCreatorQueueBasedOnBidirectionalCircularList<int> Creator3;
	Creator<int> *creators[3] = { &Creator1, &Creator2, &Creator3 };
	for (int i = 0; i < 3; i++)
	{
		Storage<int> *test = creators[i]->factoryMethod(n);
		test->Push(1);
		test->Push(0);
		cout << test->Pop() << "\n";
		cout << test->Peek() << "\n";
		delete test;
	}
	_getch();
}