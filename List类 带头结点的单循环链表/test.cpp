#include"List.h"

void test()
{
	cout << "第一组数据：1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 15, 16, 18" << endl;
	int A[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 15, 16, 18 };
	List list1(A, 15);
	cout << "List1:";
	list1.Print();
	if (list1.is_specialfunc())cout << "其中每个结点的元素值与其序号的差的绝对值不大于３" << endl;
	else cout << "不是每个结点的元素值与其序号的差的绝对值不大于３" << endl;

	cout << "第二组数据：1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 20, 18" << endl;
	int B[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 20, 18 };
	List list2(B, 16);
	cout << "List2:";
	list2.Print();
	if (list2.is_specialfunc())cout << "其中每个结点的元素值与其序号的差的绝对值不大于３" << endl;
	else cout << "不是每个结点的元素值与其序号的差的绝对值不大于３" << endl;
}

int main()
{
	test();
	return 0;
}
