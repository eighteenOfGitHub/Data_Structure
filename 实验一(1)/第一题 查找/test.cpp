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
	cout << "������Ϊ��" << list1.length() << endl;
	cout << "�� 5 �����\t��ַ��" << list1.get_pnode(5) << "\t" << "���ݣ�" << list1.get_pnode(5)->data << endl;
	cout << "�� 10 �����\t��ַ��" << list1.get_pnode(10) << "\t" << "���ݣ�" << list1.get_pnode(10)->data << endl;;
	cout << "�� 0 �����\t��ַ��" << list1.get_pnode(0) << "\t" << "���ݣ�" << list1.get_pnode(0)->data << endl;;
	cout << "�� 11 �����\t��ַ��" << list1.get_pnode(11) << endl;
	cout << "�� 12 �����\t��ַ��" << list1.get_pnode(12) << endl;
	cout << endl;
}

void test02()
{
	cout << "test02:" << endl;
	List list2;
	cout << "list2:";
	list2.print();
	cout << "������Ϊ��" << list2.length() << endl;
	cout << "�� 0 �����\t��ַ��" << list2.get_pnode(0) << endl;
	cout << "�� 2 �����\t��ַ��" << list2.get_pnode(2) << endl;
	cout << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}