#include"List.h"

void test()
{
	cout << "��һ�����ݣ�1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 15, 16, 18" << endl;
	int A[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 15, 16, 18 };
	List list1(A, 15);
	cout << "List1:";
	list1.Print();
	if (list1.is_specialfunc())cout << "����ÿ������Ԫ��ֵ������ŵĲ�ľ���ֵ�����ڣ�" << endl;
	else cout << "����ÿ������Ԫ��ֵ������ŵĲ�ľ���ֵ�����ڣ�" << endl;

	cout << "�ڶ������ݣ�1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 20, 18" << endl;
	int B[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 20, 18 };
	List list2(B, 16);
	cout << "List2:";
	list2.Print();
	if (list2.is_specialfunc())cout << "����ÿ������Ԫ��ֵ������ŵĲ�ľ���ֵ�����ڣ�" << endl;
	else cout << "����ÿ������Ԫ��ֵ������ŵĲ�ľ���ֵ�����ڣ�" << endl;
}

int main()
{
	test();
	return 0;
}
