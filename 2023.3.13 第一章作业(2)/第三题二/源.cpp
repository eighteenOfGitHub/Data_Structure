#include<iostream>
using namespace std;
int j = 0;
void getson(int A[], int max)
{
	//标记输出
	A[1] += 1;
	for (int i = 1; i <= max; i++)
	{
		if (A[i] == 2)
		{
			A[i] = 0;
			A[i + 1] += 1;
		}
	}

	//输出
	cout << "{";
	for (int i = 1; i <= max; i++)
	{
		if (A[i] == 1)
			cout << i << ", ";
	}
	cout << "\b\b}" << endl;
	j++;
	if (j % 5 == 0)cout << endl;
	
	
	//结束标志
	int over = 0;
	for (int i = 1; i <= max; i++)
	{
		over += A[i];
	}
	if (over == max)return;
	
	getson(A, max);
}

int main()
{
	int A[100]{ 0 };
	int max;
	cin >> max;
	getson(A,max);
	cout << "{}";

	return 0;
}