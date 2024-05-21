#pragma once
#include<iostream>
using namespace std;
const int MAXLEN = 1000;

class List
{
public:
	List(int A[],int n);						//已有数组构造
	List(List& list);							//拷贝构造函数
	int length()const;							//求长度
	bool get_element(const int i, int& x)const;	//按序号取元素
	int Locate(const int x)const;					//按值查找元素，返回元素顺序
	bool insert(const int i, const int x);		//插入元素，第i个往后移
	bool delete_element(const int i);			//删除第i个元素
	int delete_repetitive_element();			//（已升序或降序排好）删除相同元素
	void print();								//打印输出
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
	int number[MAXLEN] = { 0 };	//记录不重复元素的位置
	int newcount = 0;
	int temp = data[0];			//记录前一个数大小，用于比较是否相同，不相同更新
	number[0] = 1;
	newcount++;
	if (count <= 1)return false;
	for (int i = 1; i < count; i++)
	{
		if (data[i] == temp)
		{
			data[i] = -1;	//用于标记被删除的元素，如果数据为负数，自定义数据类型，添加判断是否已删除添加的变量（bool）
		}
		else
		{
			temp = data[i];				//更新
			number[newcount++] = i+1;	//记录位置，并更新总数量
		}
	}
	count = newcount;
	for (int i = 1; i < newcount; i++)
	{
		data[i] = data[number[i] - 1];	//更新数据
	}
	return count - 1;	//返回元素
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