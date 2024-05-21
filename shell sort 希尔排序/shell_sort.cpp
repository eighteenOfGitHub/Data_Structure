#include<iostream>
using namespace std;

void Print(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void Shell_Sort(int A[],int n)
{
	int d = n / 2;			//步长
	for(;d>0;d /= 2)
	{
		for (int i = d; i < n; i++)	//分组
		{
			//插入排除
			int x = A[i];
			int j = i - d;
			for (;j >= 0 && x < A[j]; j -= d)
			{
				A[j + d] = A[j];
			}
			A[j + d] = x;
		}
		cout << "步长为：" << d << endl;
		Print(A, n);
	}
}


void test()
{
	int A[16] = { 78, 100, 120, 25, 85, 40, 90, 15, 60, 35, 105, 50, 30, 10, 28, 12};
	Shell_Sort(A, 16);
}
int main()
{
	test();
	return 0;
}