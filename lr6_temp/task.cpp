#include "Queue.h"

int main()

{

	Queue<double> que;

	for (double i = 0.5; i < 6; i++)

		que.Push((double)(i + 4));

	cout << que << "\n";

	cout << que.Pop() << "\n";

	for (int i = 0.5; i < 6; i++)

		que.Push((double)(i + 1));

	cout << que << "\n";

	system("pause");
	return 0;
}
