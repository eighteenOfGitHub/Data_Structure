#include<iostream>
using namespace std;
const int v = 0;
const int MAX = 5;

int cum1(int i)
{
	if (i == 0)return 0;
	return (i + cum1(i-1));
}

int cum2(int i)
{
	if (i == 0)return 0;
	return (MAX - i + cum2(i - 1));
}

void print(int A[][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}

void print(int A[MAX*MAX])
{
	for (int i = 0; i < MAX * MAX ; i++)
	{
		cout << A[i] << "\t";
		if (i % 10 == 9)cout << endl;
	}
	cout << endl;
}

int main()
{
	int A[MAX][MAX]{0};
	int value = 1;
	//初始化
	for (int i = 0; i < MAX; i++)
	{
		for (int j = i; j < MAX; j++)
		{
			A[i][j] = v;
		}
		for (int j = 0; j < i; j++)
		{
			A[i][j] = value++;
		}
	}
	//打印A
	cout << "A: " << endl;
	print(A);

	//A转B
	int B[MAX * MAX];
	int n = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			B[n++] = A[i][j];
		} 
	}
	for (; n < MAX * MAX; n++)
		B[n] = v;

	//打印B
	cout << "B: " << endl;
	print(B);

	//求存储值
	int i = 0, j = 0;
	int number = 0, val = 0;	//位置，元素值

	while (1)
	{
		cout << "input i & j(0<=i<MAX,0<=j<MAX(MAX = " << MAX << ")) (如果i>MAX,j>MAX,则退出循环): " << endl;
		cin >> i >> j;

		if (i >= j && j >= 0 && i < MAX)
		{
			number = cum1(i) + j + 1;
			val = B[number - 1];
		}
		else if(i >= MAX || j >= MAX)
			break;
		else
		{
			number = cum1(MAX) + cum2(i) + (j - i);
			val = v;
		}

		cout << "A组中的 (" << i << "," << j << ") 元素位于B组中第 " << number << " 位，大小为" << val << endl;
	}

	return 0;
}