#include"Queue.hpp"

void test()
{
	Queue<int> q;
	if (q.empty())
		cout << "q is empty" << endl;
	for (int i = 0; i < maxlen; i++)
		q.append(i);
	int front;
	q.get_front(front);
	cout << "front of q is : " << front << endl;
	if (q.full())
		cout << "q is full" << endl;
	q.serve();
	q.get_front(front);
	cout << "after serve, front of q is : " << front << endl;
	if (!q.full())
		cout << "q is not full" << endl;
	Queue<int> p(q);
	q.get_front(front);
	cout << "front of p is : " << front << endl;
}

int main()
{
	test();
	return 0;
}