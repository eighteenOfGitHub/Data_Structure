#include"List.h"

void test()
{
	cout << "第一组数据：1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60" << endl;
	int A[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60 };
	List list1(A, 15);
	cout << "List1:";
	list1.Print();

	cout << "第二组数据：10, 20, 30, 40, 50, 60, 70, 80, 90, 100" << endl;
	int B[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	List list2(B, 10);
	cout << "List2:";
	list2.Print();
}

int main()
{
	test();
	return 0;
}