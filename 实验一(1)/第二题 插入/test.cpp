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

	List list12(A, 10);
	cout << "insert(1,100)" << endl;
	list12.insert(1, 100);
	list12.print();

	cout << "insert(5,100)" << endl;
	list1.insert(5, 100);
	list1.print();
	
	List list2(A, 10);
	cout << "insert(10,100)" << endl;
	list2.insert(10, 100);
	list2.print();

	List list3(A, 10);
	cout << "insert(0,100)" << endl;
	if (!list3.insert(0, 100))cout << "ptr is wrong!" << endl;
	list3.print();

	List list4(A, 10);
	cout << "insert(11,100)" << endl;
	if (!list4.insert(11, 100))cout << "ptr is wrong!" << endl;
	list4.print();
}

void test02()
{
	cout << "test02:" << endl;
	List list2;
	cout << "list2:";
	list2.print();
	cout << "链表长度为：" << list2.length() << endl;
	cout << "insert(5,100)" << endl;
	if (!list2.insert(5, 100))cout << "ptr is wrong!" << endl;
	list2.print();
	cout << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}
