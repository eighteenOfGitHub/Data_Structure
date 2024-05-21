#pragma once
#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	node<T>* next;
};

template<class T>
class Stack
{
public:
	Stack();					//默认构造函数
	~Stack();					//析构函数
	bool empty();				//判断栈空
	bool get_top(T& x);			//取栈顶元素
	bool push(const T x);		//入栈
	bool pop();					//出栈
	int length()const;			//长度
	bool isequal(Stack<T> s);	//是否相等		
	node<T>* getptop(){ return top; }//取栈顶结点指针
private:
	int count;					//总数
	node<T>* top;				//栈顶指针
};

template<class T>
Stack<T>::Stack()
{
	count = 0;
	top = NULL;
}

template<class T>
bool Stack<T>::empty()
{
	return count == 0;		//return top == NULL
}

template<class T>
bool Stack<T>::get_top(T& x)
{
	if (empty())
		return false;
	x = top->data;
	return true;
}

template<class T>
bool Stack<T>::push(const T x)
{
	node<T>* s = new node<T>;
	s->data = x;
	s->next = top;
	top = s;
	count++;

	return true;
}

template<class T>
bool Stack<T>::pop()
{
	if (empty())
		return false;
	node<T>* temp = top;
	top = top->next;
	delete temp;
	count--;
	return true;
}

template<class T>
Stack<T>::~Stack()
{
	while (empty())
		pop();
}

template<class T>
int Stack<T>::length()const			//长度
{
	return count;
}

template<class T>
bool Stack<T>::isequal(Stack<T> s)	//是否相等
{
	if (count != s.count)
		return false;
	else
	{
		node<T>* PA, * PB;
		PA = top;
		PB = s.top;
		if (count == 0)
			return true;
		else
		{
			while (PA != NULL)
			{
				if (PA->data != PB->data)
					return false;
				PA = PA->next;
				PB = PB->next;
			}
			return true;
		}
	}
}