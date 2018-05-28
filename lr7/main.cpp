#include"QueueOnArray.h"
#include"QueueOnUnidirectionalCL.h"

int main()
{
	int data = 10;
	QueueOnArray<double> que(data);
	QueueOnUnidirectionalCL<double> que1;

	for (int i = 0; i < 5; i++)
	{
		que1.Push((double)(i + 2)/10);
		que.Push((double)(i + 2)/10);
	}
	cout << que1 << "\n" << que << "\n";

	cout << que1.Pop() << "\n"<<que.Pop()<< "\n";

	for (int i = 0; i < 5; i++)
	{
		que1.Push((double)(i + 1));
		que.Push((double)(i + 1));
	}
	cout << que1 << "\n" << que << "\n";

	system("pause");
}
