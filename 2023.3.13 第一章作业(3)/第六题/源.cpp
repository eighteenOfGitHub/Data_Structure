#include<iostream>
using namespace std;


struct thing
{
	int data;
	int sign;
};

void getresult(thing A[], int max,int S)
{
	//标记拿出
	A[1].sign += 1;
	for (int i = 1; i <= max; i++)
	{
		if (A[i].sign == 2)
		{
			A[i].sign = 0;
			A[i + 1].sign += 1;
		}
	}

	//判断是否等于S
	int sum = 0;
	for(int i = 1; i <= max; i++)
	{
		if (A[i].sign == 1)
			sum += A[i].data;
	}
	if (sum == S)
	{
		for (int i = 1; i <= max; i++)
		{
			if (A[i].sign == 1)
				cout << "(" << i << ", " << A[i].data << ")"<<"\t";
		}
		cout <<endl<< endl;
	}


	//结束标志
	int over = 0;
	for (int i = 1; i <= max; i++)
	{
		over += A[i].sign;
	}
	if (over == max)return;

	getresult(A, max,S);
}

int main()
{
	int S;
	cout << "input S:";
	cin >> S;
	cout << "input n:";
	int max;
	cin >> max;
	cout << "input A[n]:"<<endl;
	thing A[100];
	for (int i = 1; i <= max; i++)
	{
		cin >> A[i].data;
		A[i].sign = 0;
	}
	
	getresult(A, max,S);


	return 0;
}