#include<iostream>
using namespace std;

const int Count = 41;			//�����������
const int killnumber = 3;		//����Ϊ killnumber ���˱�ɱ
const int survivenumber = 2;	//Ҫ���� survivenumber ����

void kill()
{
	bool A[Count];			// 1 ��ʾ�� 0 ��ʾ��ɱ
	for (int i = 0; i < Count; i++)
	{
		A[i] = 1;
	}
	int curcount = Count;		//�����ŵ���
	int curnumber = 0;			//����ָ��
	int curkillnumber = 1;				
	while (curcount != survivenumber)
	{
		if (A[curnumber] == 1)
		{
			if (curkillnumber == killnumber)
			{
				A[curnumber] = 0;
				curkillnumber = 0;
				curcount--;
			}
			curkillnumber++;
		}
		curnumber = (curnumber + 1) % Count;
	}
	cout << "�� " << Count << " �����У�ɱ������Ϊ " << killnumber << " ���˺����ܴ������Ϊ " << survivenumber << " �����Ϊ��" << endl;
	for (int i = 0; i < Count; i++)
	{
		if (A[i] == 1)
			cout << i + 1 << " ";
	}
}

int main()
{
	kill();
	return 0;
}