#include"Double List.hpp"

int main()
{
	int A[5] = { 1,2,3,4,5 };
	DoubleList<int> list1(A, 5);
	cout << "list1:" << endl;
	list1.print();
	cout << "After inverted, list1:" << endl;
	list1.invert();
	list1.print();

	return 0;
}