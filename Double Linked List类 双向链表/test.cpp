#include"Double Linked List.hpp"

int main()
{
	int A[9] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	DoubleList<int>	list1(A, 9);
	int B[10] = { 1, 2, 3, 4, 5, 5, 4, 3, 2, 1 };
	DoubleList<int>	list2(B, 10);
	int C[9] = { 1, 2, 3, 4, 5, 6, 3, 2, 1 };
	DoubleList<int>	list3(C, 9);
	int D[11] = { 1, 2, 3, 4, 5, 5, 6, 4, 3, 2, 1 };
	DoubleList<int>	list4(D, 11);

	cout << "list1: " << endl;
	list1.print();
	if (list1.is_symmetric())cout << " list1 is symmetric." << endl;
	else cout<< " list1 is not symmetric." << endl;
	cout << "list2: " << endl;
	list2.print();
	if (list2.is_symmetric())cout << " list2 is symmetric." << endl;
	else cout << " list2 is not symmetric." << endl;
	cout << "list3: " << endl;
	list3.print();
	if (list3.is_symmetric())cout << " list3 is symmetric." << endl;
	else cout << " list3 is not symmetric." << endl;
	cout << "list4: " << endl;
	list4.print();
	if (list4.is_symmetric())cout << " list4 is symmetric." << endl;
	else cout << " list4 is not symmetric." << endl;

	return 0;
}