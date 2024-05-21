#include"Liinked List.h"

void test01()
{
	cout << "test01:" << endl;
	int A[15] = { 1,2,3,4,5,6,7,8,9,10,20,30,40,50,60 };
	int B[10] = { 10,20,30,40,50,60,70,80,90,100 };

	List list1(A, 15);
	List list2(B, 10);
	cout << "list1:";
	list1.print();

	List list11;
	List list12;
	list1.depart(list11, list12);
	cout << "Ææ of list1:";
	list11.print();
	cout << "Å¼ of list1:";
	list12.print();

	cout << "list2:";
	list2.print();

	List list21;
	List list22;
	list2.depart(list21, list22);

	cout << "Ææ of list2:";
	list21.print();
	cout << "Å¼ of list2:";
	list22.print();
}

int main()
{
	test01();
	return 0;
}