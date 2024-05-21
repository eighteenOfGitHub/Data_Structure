#include<iostream>
using namespace std;

int strcmp(char A[], char B[],int length1,int length2)	//1大为1,1小为-1，相等为0
{
	int i1 = 0;
	int i2 = 0;

	while (1)
	{
		if (A[i1] == B[i2])
		{
			i1++;
			i2++;
			if (i1>length1 && i2 > length2)
				return 0;
			else if (i1 > length1)
				return -1;
			else if (i2 > length2)
				return 1;
		}
		else if (A[i1] > B[i2]) return 1;
		else return -1;
	}
}

void print_result(char list1[], char list2[],int length1,int length2)
{
	int result = strcmp(list1, list2, length1, length2);
	if (result == 1)
		cout << "B is big" << endl;
	else if (result == 0)
		cout << "is equal" << endl;
	else
		cout << "B is small" << endl;
}

void getarray(char A[],char* str, int length)
{
	for (int i = 0; i < length; i++)
	{
		A[i] = *(str + i);
	}
}

int main()
{
	int length1,length2;
	char A[100], B[100];
	char* str1 = new char,* str2 = new char;
	char c;

	while (1)
	{
		cout << "请输入字符串A长度(<100)：" << endl;
		cin >> length1;

		if (length1 == 0)break;

		cout << "请输入字符串A：" << endl;
		for (int i = 0; i < length1; i++)
		{
			cin >> c;
			*(str1 + i) = c;
		}

		cout << "请输入字符串B长度(<100)：" << endl;
		cin >> length2;
		cout << "请输入字符串B：" << endl;
		for (int i = 0; i < length2; i++)
		{
			cin >> c;
			*(str1 + i) = c;
		}

		getarray(A, str1, length1);
		getarray(B, str2, length2);

		cout << "compare A with B:" << endl;
		print_result(A, B,length1,length2);
	}
	return 0;
}