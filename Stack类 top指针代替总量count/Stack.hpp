#pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
	//数据
	int maxlen;			//最大
	T* top;				//栈顶指针
	int count;			//总量
	T* data;			//数据
public:
	Stack(int m);							//构造函数
	Stack(Stack& st);						//拷贝构造
	Stack& operator=(const Stack& st);		//=号 深拷贝
	~Stack();								//析构

	bool empty() const;						//栈空
	bool full() const;						//栈满

	bool get_top(T& x)const;			//得到栈顶元素
	bool push(const T x);				//入栈
	bool pop();							//出栈
};

template<class T>
Stack<T>::Stack(int m)
{
	maxlen = m;
	data = new T[maxlen];
	count = 0;
	top = data - 1;
}

template<class T>
Stack<T>::Stack(Stack& st)
{
	maxlen = st.maxlen;
	count = st.count;
	this->data = new T[maxlen];
	top = data - 1;

	for (int i = 0; i < count; i++)
	{
		data[i] = st.data[i];
		top++;
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& st)
{
	//删
	if (this->data != NULL)
	{
		delete[] this->data;
		this->data = NULL;
		this->top = NULL;
		this->maxlen = 0;
		this->count = 0;
	}

	//深拷贝
	this->count = st.count;
	this->maxlen = st.maxlen;
	this->data = new T[this->maxlen];
	this->top = data - 1;

	for (int i = 0; i < this->maxlen; i++)
	{
		this->data[i] = st.data[i];
		top++;
	}

	return *this;
}

template<class T>
Stack<T>::~Stack()
{
	if (this->data != NULL)
	{
		delete[] this->data;
		this->data = NULL;
		this->top = NULL;
	}
}

template<class T>
bool Stack<T>::empty() const
{
	return top == data - 1;
}

template<class T>
bool Stack<T>::full() const
{
	return top == data + maxlen - 1;
}

template<class T>
bool Stack<T>::get_top(T& x)const
{
	if (empty())
		return false;
	else
	{
		x = *top;
		return true;
	}
}

template<class T>
bool Stack<T>::push(const T x)
{
	if (full())
		return false;
	else
	{
		top++;
		*top = x;
		count++;
		return true;
	}
}

template<class T>
bool Stack<T>::pop()
{
	if (empty())
		return false;
	top--;
	count--;
	return true;
}