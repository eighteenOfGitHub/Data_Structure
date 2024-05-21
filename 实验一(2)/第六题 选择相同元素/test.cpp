#include"Linked List.h"

void test1()
{
	cout << "test01:" << endl;
	int A[10] = { 1, 3, 6, 10, 15, 16, 17, 18, 19, 20 };
	int B[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 18, 20, 30 };
	List list1(A, 10);
	List list2(B, 13);
	cout << "list1:"; list1.print();
	cout << "list2:"; list2.print();
	List objlist;
	list1.get_sameelement(list2, objlist);
	cout << "object list:"; objlist.print();

}

void test2()
{
	cout << "test02:" << endl;
	int A[10] = { 1, 3, 6, 10, 15, 16, 17, 18, 19, 20 };
	int B[8] = { 2, 4, 5, 7, 8, 9, 12, 22 };
	List list1(A, 10);
	List list2(B, 8);
	cout << "list1:"; list1.print();
	cout << "list2:"; list2.print();
	List objlist;
	list1.get_sameelement(list2, objlist);
	cout << "object list:"; objlist.print();

}
void test3()
{
	cout << "test03:" << endl;
	int B[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	List list1;
	List list2(B, 10);
	cout << "list1:"; list1.print();
	cout << "list2:"; list2.print();
	List objlist;
	list1.get_sameelement(list2, objlist);
	cout << "object list:"; objlist.print();

}

int main()
{
	test1();
	test2();
	test3();
	return 0;
}