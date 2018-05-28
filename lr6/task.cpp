#include "Queue.h"

void main()

{

	Queue que;

	for (int i = 0; i < 6; i++)

		que.Push(i + 4);

	cout << que << "\n";

	cout << que.Pop() << "\n";

	for (int i = 0; i < 6; i++)

		que.Push(i + 1);

	cout << que << "\n";

	system("pause");

}