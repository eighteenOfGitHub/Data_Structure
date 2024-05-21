#include<iostream>
using namespace std;

const int Count = 41;			//井里的总人数
const int killnumber = 3;		//报数为 killnumber 的人被杀
const int survivenumber = 2;	//要求存活 survivenumber 个人

void kill()
{
	bool A[Count];			// 1 表示存活， 0 表示被杀
	for (int i = 0; i < Count; i++)
	{
		A[i] = 1;
	}
	int curcount = Count;		//还活着的人
	int curnumber = 0;			//遍历指针
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
	cout << "在 " << Count << " 个人中，杀死报数为 " << killnumber << " 的人后，所能存活人数为 " << survivenumber << " 的序号为：" << endl;
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