#include"Linked List.h"

void test01()
{
	cout << "test01:" << endl;
	int A[10];
	for (int i = 0; i < 10; i++)
		A[i] = (i + 1) * 10;

	List list1(A, 10);
	cout << "list1:";
	list1.print();
	cout << "链表长度为：" << list1.length() << endl;

	list1.insert(25);
	list1.insert(85);
	list1.insert(110);
	list1.insert(8);

	list1.print();
	cout << "链表长度为：" << list1.length() << endl;
}

int main()
{
	test01();
	return 0;
}
