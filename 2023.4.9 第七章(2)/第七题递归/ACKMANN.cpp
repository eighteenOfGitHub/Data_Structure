#include<iostream>
using namespace std;

int Ack(int m, int n)
{
	if (m == 0)					//结束条件
		return n + 1;
	else if (n == 0)			//循环体二
		return Ack(m - 1, 1);
 	else						//循环体一
		return  Ack(m - 1, Ack(m, n - 1));
}

void test()
{
	int m, n;
	while (1)
	{
		cout << "请输入 m 和 n：";
		cin >> m >> n;
		if (m!= 0||n!=0)
			cout << "Ack( " << m << ", " << n << " ) = " << Ack(m, n) << endl;
		else
		{
			cout << "Ack( " << m << ", " << n << " ) = " << Ack(m, n) << endl;
			break;
		}
	}
}

int main()
{
	test();
	return 0;
}