#include"triple list.h"

int main()
{
	//≥ı ºªØ
	int a[MAX][MAX] = { 0 };
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (i == j)a[i][j] = 1;

	int b[MAX][MAX] = { 0 };
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (i + j == 4)b[i][j] = 1;

	TripleList triplelist1(a);
	TripleList triplelist2(b);
	TripleList triplelist3 = triplelist2 + triplelist1 + triplelist2;

	cout << "list1:" << endl;
	triplelist1.print();
	cout << "list2:" << endl;
	triplelist2.print();
	cout << "list3 = list1 + list2 + list2:" << endl;
	triplelist3.print();

	return 0;
}