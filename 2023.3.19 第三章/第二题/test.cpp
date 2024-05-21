#include"Queue.hpp"

int main()
{
	Queue<int> queue;
	for (int i = 0; i < 50; i++)
	{
		queue.append(i);
	}
	cout << "count of queue : " << queue.length() << endl;
	int length,head,rear;
	head = queue.getfrontsign();
	rear = queue.getrearsign();

	length = (head < rear) ? rear - head : rear - head + maxlen;
	
	cout << "from front to rear of queue : " << length << endl;
	return 0;
}