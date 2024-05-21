#include"List.h"

void test01()
{
	cout << "----------test01----------" << endl;
	int A[10] = { 1, 3, 6, 10, 15, 16, 17, 18, 19, 20 };
	int B[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 18, 20, 30 };
	List listA(A, 10), listB(B, 13), list1, list2;
	cout << "listA:";
	listA.Print();
	cout << "listB:";
	listB.Print();

	list1.Get_Intersection(listA, listB);
	list2.Get_Unionset(listA, listB);
	cout << "交集：";
	list1.Print();
	cout << "并集：";
	list2.Print();
}

void test02()
{
	cout << "----------test02----------" << endl;
	int A[10] = { 1, 3, 6, 10, 15, 16, 17, 18, 19, 20 };
	int B[8] = { 2, 4, 5, 7, 8, 9, 12, 22 };
	List listA(A, 10), listB(B, 8), list1, list2;
	cout << "listA:";
	listA.Print();
	cout << "listB:";
	listB.Print();

	list1.Get_Intersection(listA, listB);
	list2.Get_Unionset(listA, listB);
	cout << "交集：";
	list1.Print();
	cout << "并集：";
	list2.Print();
}

void test03()
{
	cout << "----------test03----------" << endl;
	int B[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	List listA, listB(B, 10), list1, list2;
	cout << "listA:";
	listA.Print();
	cout << "listB:";
	listB.Print();

	list1.Get_Intersection(listA, listB);
	list2.Get_Unionset(listA, listB);
	cout << "交集：";
	list1.Print();
	cout << "并集：";
	list2.Print();
}

int main()
{
	test01();
	test02();
	test03();
	return 0;
}