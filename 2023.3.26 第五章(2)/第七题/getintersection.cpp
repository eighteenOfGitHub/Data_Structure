#include"List.hpp"

int main()
{
	int A[5] = { 0,1,3,6,8 };
	int B[5] = { 5,6,8,9,17 };
	List<int> listA(A, 5);
	List<int> listB(B, 5);
	List<int> listA_B((listA.getintersection(listB)));
	cout << "listA: " << endl;
	listA.print();
	cout << "listB: " << endl;
	listB.print();
	cout << "listA_B: " << endl;
	listA_B.print();

	return 0;
}