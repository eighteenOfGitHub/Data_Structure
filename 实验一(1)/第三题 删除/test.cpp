#include"Linked List.h"

void test01()
{
	cout << "test01:" << endl;
	int A[10];
	for (int i = 0; i < 10; i++)
		A[i] = i + 1;

	List list1(A, 10);
	cout << "list1:";
	list1.print();
	cout << "链表长度为：" << list1.length() << endl;

	cout << "delete(5)" << endl;
	list1.Delete(5);
	list1.print();

	List list12(A, 10);
	cout << "delete(10)" << endl;
	list12.Delete(10);
	list12.print();

	List list13(A, 10);
	cout << "delete(1)" << endl;
	list13.Delete(1);
	list13.print();

	List list14(A, 10);
	cout << "delete(11)" << endl;
	if (!list14.Delete(11)) cout << "ptr is wrong!" << endl;
	list14.print();

	List list15(A, 10);
	cout << "delete(0)" << endl;
	if (!list15.Delete(0)) cout << "ptr is wrong!" << endl;
	list15.print();
}

void test02()
{
	cout << "test02:" << endl;
	List list2;
	cout << "list2:";
	list2.print();
	cout << "链表长度为：" << list2.length() << endl;

	cout << "delete(5)" << endl;
	if (!list2.Delete(11)) cout << "ptr is wrong!" << endl;
	list2.print();
}

int main()
{
	test01();
	test02();
	return 0;
}
