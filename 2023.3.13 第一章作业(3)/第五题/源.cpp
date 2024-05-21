#include<iostream>
using namespace std;
int m = 0;
int n = 1;

void getdown(int max, int A[]);
void getup(int max, int A[]);

void getup(int max, int A[])
{
	while (A[n] <= A[n + 1] && n < max - 1)
		n++;

	cout << "{";
	for (int i = m; m <= n; m++)
		if (m != n)
			cout << A[m] << ",";
		else
			cout << A[m];
	cout << "}";
	if (n == max - 1)return;
	n++;
	m--;
	getdown(max, A);
}

void getdown(int max, int A[])
{
	while (A[n] >= A[n + 1] && n < max - 1)
		n++;

	cout << "{";
	for (int i = m; m <= n; m++)
		if (m != n)
			cout << A[m] << ",";
		else
			cout << A[m];
	cout << "}";
	if (n == max - 1)return;
	n++;
	m--;
	getup(max, A);
}

int main()
{
	cout << "请输入数组大小n(n<100)：";
	int max;
	cin >> max;
	cout << "请输入数组元素：";
	int A[100];
	for (int i = 0; i < max; i++)
	{
		cin >> A[i];
	}
	while (A[m] == A[n])
		n++;
	if (A[m] < A[n])
		getup(max, A);
	else
		getdown(max, A); 

	return 0;
}