#include<iostream>
using namespace std;

bool match(char a1, char a2)
{
	switch (a1)
	{
	case '(':
		if (a2 == ')')
			return true;
		break;
	case '[':
		if (a2 == ']')
			return true;
		break;
	case '{':
		if (a2 == '}')
			return true;
		break;
	default:
		cout << "�����ɶ����" << endl;
		break;
	}
	return false;
}

int main()
{
	char a1;
	char a2;
	cout << "��������0���˳�ѭ��" << endl;
	while (1)
	{
		cin >> a1;
		cin >> a2;

		if (a1 == '0' && a2 == '0')
			break;

		if (match(a1, a2))
			cout << a1 << " �� " << a2 << " ��ƥ��" << endl;
		else
			cout << a1 << " �� " << a2 << " ��ƥ��" << endl;
	}


	return 0;
}