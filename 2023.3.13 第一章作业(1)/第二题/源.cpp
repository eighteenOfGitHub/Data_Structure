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
	cout << "请输入n(n<=100): ";
	int n;
	cin >> n;
	cout << "请输入x：";
	double x;
	cin >> x;
	cout << "请输入参数数组(从an开始)：";
	double coefficient[100];
	for (int i = 0; i < n+1; i++)
	{
		cin >> coefficient[i];
	}

	cout <<"结果是：" << fun(n,x, coefficient) << endl;

	return 0;
}
