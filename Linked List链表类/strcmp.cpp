#include"List.h"
#include<iostream>
using namespace std;



int strcmp(List list1, List list2)	//1大为1,1小为-1，相等为0
{
	if (list1.length() == list2.length())
	{
		Node* p1 = list1.get_head()->next;
		Node* p2 = list2.get_head()->next;
		while (p1 != NULL||p2 != NULL )
		{
			if (p1->data == p2->data)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			else if (p1->data > p2->data) return 1;
			else return -1;
		}
		return 0;
	}
	else if (list1.length() > list1.length())
		return 1;
	else
		return -1;
}

void print_result(List list1, List list2)
{
	int result = strcmp(list1, list2);
	if (result == 1)
		cout << "B is big" << endl;
	else if (result == 0)
		cout << "is equal" << endl;
	else
		cout << "B is small" << endl;
}
int main()
{
	char A[3] = { 'a','b','c' };
	char B[3] = { 'a','b','d' };
	char C[3] = { 'a','b','e' };
	char D[4] = { 'a','b','d','e'};

	cout << "A[3] = { 'a','b','c' };" << endl;
	cout << "B[3] = { 'a','b','d' };" << endl;
	cout << "C[3] = { 'a','b','e' };" << endl;
	cout << "D[4] = { 'a','b','d','e'};" << endl;

	List listA(A, 3);
	List listB(B, 3);
	List listC(C, 3);
	List listD(D, 4);

	cout << "compare B with A:" << endl;
	print_result(listB, listA);
	cout << "compare B with B:" << endl;
	print_result(listB, listB);
	cout << "compare B with C:" << endl;
	print_result(listB, listC);
	cout << "compare B with D:" << endl;
	print_result(listB, listD);

	return 0;
}