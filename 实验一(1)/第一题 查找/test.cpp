#include"Linked List.h"

void test01()
{
	cout << "test01:" << endl;
	int A[10];
	for (int i = 0; i < 10; i++)
		A[i] = i+1;
	List list1(A, 10);
	cout << "list1:";
	list1.print();
	cout << "链表长度为：" << list1.length() << endl;
	cout << "第 5 个结点\t地址：" << list1.get_pnode(5) << "\t" << "数据：" << list1.get_pnode(5)->data << endl;
	cout << "第 10 个结点\t地址：" << list1.get_pnode(10) << "\t" << "数据：" << list1.get_pnode(10)->data << endl;;
	cout << "第 0 个结点\t地址：" << list1.get_pnode(0) << "\t" << "数据：" << list1.get_pnode(0)->data << endl;;
	cout << "第 11 个结点\t地址：" << list1.get_pnode(11) << endl;
	cout << "第 12 个结点\t地址：" << list1.get_pnode(12) << endl;
	cout << endl;
}

void test02()
{
	cout << "test02:" << endl;
	List list2;
	cout << "list2:";
	list2.print();
	cout << "链表长度为：" << list2.length() << endl;
	cout << "第 0 个结点\t地址：" << list2.get_pnode(0) << endl;
	cout << "第 2 个结点\t地址：" << list2.get_pnode(2) << endl;
	cout << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}