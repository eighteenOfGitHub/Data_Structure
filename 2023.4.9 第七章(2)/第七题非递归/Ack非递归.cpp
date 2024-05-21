#include<iostream>
#include"Stack.h"
using namespace std;

int Ack2(int m, int n)
{
	Stack stack;
	do
	{
	L1://递归入口
		if (m > 0 && n > 0)
		{
			stack.push(m-1);
			n--;
			goto L1;
		}
		if (n == 0 && m > 0)
		{
			n = 1;
			m--;
			goto L1;
		}
		if (m == 0)
		{
			m = stack.get_top()->_m;
			n++;
			stack.pop();
			goto L1;
		}
	} while (!stack.Empty() && m == 0);
	return n;
//Ack(2, 1) = Ack(1, Ack(2, 0))
	//		= Ack(1, Ack(1, 1))
	//		= Ack(1, Ack(0, Ack(1, 0)))
	//		= Ack(1, Ack(0, Ack(0, 1)))
	//		= Ack(1, Ack(0, 2))
	//		= Ack(1, 3)
	//		= Ack(0, Ack(1, 2))
	//		= Ack(0, Ack(0, Ack(1, 1)))
	//		= Ack(0, Ack(0, Ack(0, Ack(1, 0))))
	//		= Ack(0, Ack(0, Ack(0, Ack(0, 1))))
	//	 	= Ack(0, Ack(0, Ack(0, 2)))
	//		= Ack(0, Ack(0, 3))
	//		= Ack(0, 4)
	//		= 5
}

int Ack1(int m, int n)
{
	if (m == 0)				
	return n + 1;
else if (n == 0)			
	return Ack1(m - 1, 1);
else						
	return  Ack1(m - 1, Ack1(m, n - 1));
}

void test01()
{
	int m, n;
	while (1)
	{
		cout << "请输入 m 和 n：";
		cin >> m >> n;
		if (m != 0 || n != 0)
		{
			cout << "Ack1( " << m << ", " << n << " ) = " << Ack1(m, n) << "\t";
			cout << "Ack2( " << m << ", " << n << " ) = " << Ack2(m, n) << endl; 
		}
		else
		{
			cout << "Ack1( " << m << ", " << n << " ) = " << Ack1(m, n) << "\t";
			cout << "Ack2( " << m << ", " << n << " ) = " << Ack2(m, n) << endl;
			break;
		}
	}
}

int main()
{
	test01();
	return 0;
}
