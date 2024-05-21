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
	//��ʼ��
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
	//��ӡA
	cout << "A: " << endl;
	print(A);

	//AתB
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

	//��ӡB
	cout << "B: " << endl;
	print(B);

	//��洢ֵ
	int i = 0, j = 0;
	int number = 0, val = 0;	//λ�ã�Ԫ��ֵ

	while (1)
	{
		cout << "input i & j(0<=i<MAX,0<=j<MAX(MAX = " << MAX << ")) (���i>MAX,j>MAX,���˳�ѭ��): " << endl;
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

		cout << "A���е� (" << i << "," << j << ") Ԫ��λ��B���е� " << number << " λ����СΪ" << val << endl;
	}

	return 0;
}