#include<iostream>
using namespace std;

int Ack(int m, int n)
{
	if (m == 0)					//��������
		return n + 1;
	else if (n == 0)			//ѭ�����
		return Ack(m - 1, 1);
 	else						//ѭ����һ
		return  Ack(m - 1, Ack(m, n - 1));
}

void test()
{
	int m, n;
	while (1)
	{
		cout << "������ m �� n��";
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