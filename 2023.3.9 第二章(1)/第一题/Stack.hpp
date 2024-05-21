#pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
	//����
	int maxlen;			//���
	int count;			//����
	T* data;			//����
public:
	Stack(int m);							//���캯��
	Stack(Stack& st);						//���ƹ���
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
	count = 0;
	data = new T[maxlen];

}

template<class T>
Stack<T>::Stack(Stack& st)
{
	this->count = st.count;
	this->maxlen = st.maxlen;
	this->data = new T[this->maxlen];

	for (int i = 0; i < this->maxlen; i++)
	{
		this->data[i] = st.data[i];
	}
}


template<class T>
Stack<T>::~Stack()
{
	if (this->data != NULL)
	{
		delete[] this->data;
		this->data = NULL;
	}
}

template<class T>
bool Stack<T>::empty() const
{
	return count == 0;
}

template<class T>
bool Stack<T>::full() const
{
	return count == maxlen;
}

template<class T>
bool Stack<T>::get_top(T& x)const
{
	if (empty())
		return false;
	else
	{
		x = *(data + count - 1);
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
		*(data + count) = x;
		count++;
		return true;
	}
}

template<class T>
bool Stack<T>::pop()
{
	if (empty() == 1)
		return false;
	this->count--;
	return true;
}