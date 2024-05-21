#include"List.hpp"

int main()
{
	int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int B[5] = { 1, 3, 4, 6, 7 };
	int C[5] = { 1, 2, 5, 7, 11 };
	List<int> lista(A, 10);
	List<int> listb(B, 5);
	List<int> listc(C, 5);

	cout << "ListA: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10" << endl;
	cout << "ListB: 1, 3, 4, 6, 7" << endl;
	cout << "ListC: 1, 2, 5, 7, 11" << endl;
	
	if (lista.isson(listb))
		cout << "ListB is ListA's son" << endl;
	else
		cout << "ListB isn't ListA's son" << endl;

	if (lista.isson(listc))
		cout << "ListC is ListA's son" << endl;
	else
		cout << "ListC isn't ListA's son" << endl;

	return 0;
}