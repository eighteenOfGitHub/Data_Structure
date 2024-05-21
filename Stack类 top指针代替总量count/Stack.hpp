#pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
	//����
	int maxlen;			//���
	T* top;				//ջ��ָ��
	int count;			//����
	T* data;			//����
public:
	Stack(int m);							//���캯��
	Stack(Stack& st);						//��������
	Stack& operator=(const Stack& st);		//=�� ���
	~Stack();								//����

	bool empty() const;						//ջ��
	bool full() const;						//ջ��

	bool get_top(T& x)const;			//�õ�ջ��Ԫ��
	bool push(const T x);				//��ջ
	bool pop();							//��ջ
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
	//ɾ
	if (this->data != NULL)
	{
		delete[] this->data;
		this->data = NULL;
		this->top = NULL;
		this->maxlen = 0;
		this->count = 0;
	}

	//���
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