#pragma once
#include<iostream>
using namespace std;
const int MAXLEN = 1000;

class List
{
public:
	List(int A[],int n);						//�������鹹��
	List(List& list);							//�������캯��
	int length()const;							//�󳤶�
	bool get_element(const int i, int& x)const;	//�����ȡԪ��
	int Locate(const int x)const;					//��ֵ����Ԫ�أ�����Ԫ��˳��
	bool insert(const int i, const int x);		//����Ԫ�أ���i��������
	bool delete_element(const int i);			//ɾ����i��Ԫ��
	int delete_repetitive_element();			//������������źã�ɾ����ͬԪ��
	void print();								//��ӡ���
private:
	int data[MAXLEN];
	int count;
};

List::List(int A[], int n)
{
	count = n;
	for (int i = 0; i < count; i++)
	{
		data[i] = A[i];
	}
}

int List::delete_repetitive_element()
{
	int number[MAXLEN] = { 0 };	//��¼���ظ�Ԫ�ص�λ��
	int newcount = 0;
	int temp = data[0];			//��¼ǰһ������С�����ڱȽ��Ƿ���ͬ������ͬ����
	number[0] = 1;
	newcount++;
	if (count <= 1)return false;
	for (int i = 1; i < count; i++)
	{
		if (data[i] == temp)
		{
			data[i] = -1;	//���ڱ�Ǳ�ɾ����Ԫ�أ��������Ϊ�������Զ����������ͣ�����ж��Ƿ���ɾ����ӵı�����bool��
		}
		else
		{
			temp = data[i];				//����
			number[newcount++] = i+1;	//��¼λ�ã�������������
		}
	}
	count = newcount;
	for (int i = 1; i < newcount; i++)
	{
		data[i] = data[number[i] - 1];	//��������
	}
	return count - 1;	//����Ԫ��
}

List::List(List& list)
{
	count = list.count;
	for (int i = 0; i < count; i++)
	{
		data[i] = list.data[i];
	}
}

int List::length()const
{
	return count;
}

bool List::get_element(const int i, int& x)const
{
	if (i <= 0 || i > count || count == 0)
		return false;
	x = data[i-1];
	return true;
}

int List::Locate(const int x)const
{
	for (int i = 0; i < length(); i++)
		if (data[i] == x) return (i + 1);
	return 0;
}

bool List::insert(const int i, const int x)
{
	if (count == MAXLEN)
		return false;
	if (i < 1 || i > length() + 1)
		return false;
	for (int j = count; j >= i; j--)
		data[j] = data[j - 1];
	data[i - 1] = x;
	count++;
	return true;
}

bool List::delete_element(const int i)
{
	if (length() == 0) return false;
	if (i < 1 || i > length()) return false;
	for (int j = i + 1; j <= length(); j++)
		data[j - 2] = data[j - 1];
	count--;
	return true;
}

void List::print()
{
	for (int i = 0; i < count; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}