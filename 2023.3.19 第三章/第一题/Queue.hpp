#pragma once
#include<iostream>
using namespace std;
const int maxlen = 100;

template<class T>
class Queue		//ѭ���������
{
public:
	Queue();
	Queue(Queue<T>& Q);
	bool empty()const;
	bool full()const;			//ԭ��Ϊ����ӿգ���һ����(rear + 1) % maxlen == front
	bool get_front(T& x)const;
	bool append(const T x);
	bool serve();				//����
private:
	int count;
	int front, rear;			//��ͷ����β,ͷָ�벻��Ԫ��
	T data[maxlen];
};

template<class T>
Queue<T>::Queue()
{
	count = 0;
	front = rear = 0;
	cout << "QueueĬ�Ϲ��캯������" << endl;
}

template<class T>
Queue<T>::Queue(Queue<T>& Q)
{
	count = Q.count;
	front = Q.count;
	rear = Q.rear;

	for (int i = front + 1; i % maxlen == rear; i++)
	{
		data[i] = Q.data[i];
	}
	cout << "Queue�������캯������" << endl;
}

template<class T>
bool Queue<T>::empty()const
{
	//if (count == 0)
	//	return true;
	//return false;
	return front == rear;
}

template<class T>
bool Queue<T>::full()const
{
	//if (count == maxlen - 1)
	//	return true;
	//return false;
	return (rear + 1) % maxlen == front;
}

template<class T>
bool Queue<T>::get_front(T& x)const
{
	if (empty())
		return false;
	x = data[(front + 1) % maxlen];
	return true;
}

template<class T>
bool Queue<T>::append(const T x)
{
	if (full())
		return false;
	rear = (rear + 1) % maxlen;
	data[rear] = x;
	count++;
	return true;
}

template<class T>
bool Queue<T>::serve()				//����
{
	if (empty())
		return false;
	front = (front + 1) % maxlen;
	count--;
	return false;
}