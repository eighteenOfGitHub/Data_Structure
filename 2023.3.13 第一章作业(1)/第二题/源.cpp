#include<iostream>
using namespace std;

double fun(int n, double x, double a[])
{
	if (n == 0)
		return a[n];
	return fun(n - 1, x, a) * x + a[n];
}

int main()
{
	cout << "������n(n<=100): ";
	int n;
	cin >> n;
	cout << "������x��";
	double x;
	cin >> x;
	cout << "�������������(��an��ʼ)��";
	double coefficient[100];
	for (int i = 0; i < n+1; i++)
	{
		cin >> coefficient[i];
	}

	cout <<"����ǣ�" << fun(n,x, coefficient) << endl;

	return 0;
}
