#pragma once
#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;		//������
	node<T>* next;	//ָ����
};

template<class T>
class Queue
{
public:
	Queue();						//Ĭ�Ϲ���
	Queue(Queue<T>& queue);			//��������
	~Queue();						//����
	bool empty() const;				//�ӿ�
	bool get_front(T& x)const;		//��ȡ��Ԫ��
	bool append(const T x);			//���
	bool serve();					//����
private:
	int count;						//����
	node<T>* front, * rear;			//ͷָ�룬βָ��
};

template<class T>
Queue<T>::Queue()
{
	front = new node<T>;		//ͷָ��ָ��ͷ��㣬ͷ�����������
	rear = front;			//βָ��ӵ�ͷָ����
	front->next = NULL;		//ͷָ�����ÿ�
	count = 0;
}

template<class T>
Queue<T>::Queue(Queue<T>& queue)
{
	front = new node<T>;		//ͷָ��ָ��ͷ��㣬ͷ�����������
	rear = front;			//βָ��ӵ�ͷָ����
	front->next = NULL;		//ͷָ�����ÿ�
	count = 0;

	//���
	node<T>* ptr = queue.front;
	while (ptr->next != NULL)
	{
		append(const T ptr->next->data);
		ptr = ptr->next;
	}

}

template<class T>
bool Queue<T>::empty()const
{
	return rear == front;
}

template<class T>
bool Queue<T>::get_front(T& x)const
{
	if (empty())
		return false;
	x = front->next->data;
	return true;
}

template<class T>
bool Queue<T>::append(const T x)
{
	node<T>* s = new node<T>;	//�����½��
	s->data = x;			//��������
	s->next = NULL;			//next�ÿ�

	rear->next = s;			//���½�����ӵ�β����next

	rear = s;				//����β���
	count++;				//����������

	return true;
}

template<class T>
bool Queue<T>::serve()				//����
{
	node<T>* temp;
	if (empty())
		return false;
	temp = front->next;				//�ݴ��׽��
	front->next = temp->next;		//ͷָ�����ӵڶ������
	delete temp;					//ɾ��ͷ���
	count--;						//����������

	if (front->next == NULL)		//����ӿգ���β�������ͷ���	
		rear = front;

	return true;
}

template<class T>
Queue<T>::~Queue()
{
	while (!empty())serve();
	delete front;
}