#pragma once
#include<iostream>
using namespace std;
const int MAXLEN = 1000;

template<class T>
class List
{
public:
	List();										//构造函数
	List(List<T>& list);						//拷贝构造函数
	int length()const;							//求长度
	bool get_element(const int i, T& x)const;	//按序号取元素
	int Locate(const T x)const;					//按值查找元素，返回元素顺序
	bool insert(const int i, const T x);		//插入元素，第i个往后移
	bool delete_element(const int i);			//删除第i个元素
private:
	T data[MAXLEN];
	int count;
};

template<class T>
List<T>::List()
{
	count = 0;
}

template<class T>
List<T>::List(List<T>& list)
{
	count = list.count;
	for (int i = 0; i < count; i++)
	{
		data[i] = list.data[i];
	}
}

template<class T>
int List<T>::length()const
{
	return count;
}

template<class T>
bool List<T>::get_element(const int i, T& x)const
{
	if (i <= 0 || i > count || count == 0) 
		return false;
	x = data[i-1];
	return true;
}

template<class T>
int List<T>::Locate(const T x)const
{
	for (int i = 0; i < length(); i++)
		if (data[i] == x) return (i + 1);
	return 0;
}

template<class T>
bool List<T>::insert(const int i, const T x)
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

template<class T>
bool List<T>::delete_element(const int i)
{
	if (length() == 0) return false;
	if (i < 1 || i > length()) return false;
	for (int j = i + 1; j <= length(); j++)
		data[j - 2] = data[j - 1];
	count--;
	return true;
}
