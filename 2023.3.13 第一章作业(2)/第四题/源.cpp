#include<iostream>
using namespace std;

void sort(int A[],int n)
{
	int head = 0;
	int rear = n-1;
	while (head < rear)
	{
		while (A[head] % 2 == 1)
			if (head < rear)
				head++;
			else
				return;
		while (A[rear] % 2 == 0)
			if (head < rear)
				rear--;
			else
				return;
		swap(A[head], A[rear]);
	}
}

int main()
{
	cout << "�����������Сn(n<100)��";
	int n;
	cin >> n;
	cout << "����������Ԫ�أ�";
	int A[100];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	sort(A,n);

	cout << "�������Ϊ��";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
}