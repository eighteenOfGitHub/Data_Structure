#pragma once
#include<iostream>
using namespace std;

template<class T>
struct DoubleNode
{
	DoubleNode<T>* prior;
	T data;
	DoubleNode<T>* next;
};

template<class T>
class DoubleList
{
public:
	DoubleList();							//���캯��
	DoubleList(const T A[], const int n);	//���鹹�캯��
	DoubleList(DoubleList<T>& list);		//�������캯��
	~DoubleList();							//��������
	DoubleNode<T>* get_front() const;		//�õ�ͷ���ָ��
	DoubleNode<T>* get_rear() const;		//�õ�β���ָ��
	int length() const;						//�õ�������
	void print() const;						//����̨���Ԫ��
	bool invert();							//����
private:
	DoubleNode<T>* front;
	DoubleNode<T>* rear;
	int count;
};

template<class T>
DoubleList<T>::DoubleList()
{
	DoubleNode<T>* node = new DoubleNode<T>;

	rear = node;
	front = node;
	node->next = front;
	node->prior = rear;

	count = 0;
}

template<class T>
DoubleList<T>::DoubleList(const T A[], const int n)
{
	DoubleNode<T>* PA = new DoubleNode<T>;

	rear = PA;
	front = PA;
	PA->next = front;
	PA->prior = rear;

	count = 0;

	for (int i = 0; i < n; i++)
	{
		DoubleNode<T>* node = new DoubleNode<T>;

		PA->next = node;		//����ǰ���

		node->data = A[i];		//���½ڵ����
		node->prior = PA;
		node->next = front;

		rear = node;			//�����������
		front->prior = node;
		count++;

		PA = node;				//������ʱ��㣬Ϊ��һ�������׼��
	}
}

template<class T>
DoubleList<T>::DoubleList(DoubleList<T>& doublelist)
{
	DoubleNode<T>* PA = new DoubleNode<T>;
	DoubleNode<T>* PB = doublelist.get_front()->next;

	//����ͷ���
	rear = PA;
	front = PA;
	PA->next = front;
	PA->prior = rear;

	count = 0;
	//�������
	for (; PB != doublelist.get_front(); PB = PB->next)
	{
		DoubleNode<T>* node = new DoubleNode<T>;

		PA->next = node;		//����ǰ���

		node->data = PB->data;	//���½ڵ����
		node->prior = PA;
		node->next = front;

		rear = node;			//�����������
		front->prior = node;
		count++;

		PA = node;				//������ʱ��㣬Ϊ��һ�������׼��
	}
}

template<class T>
DoubleNode<T>* DoubleList<T>::get_front() const
{
	return front;
}

template<class T>
DoubleNode<T>* DoubleList<T>::get_rear() const
{
	return rear;
}

template<class T>
int DoubleList<T>::length() const
{
	return count;
}						//�õ�������

template<class T>
void DoubleList<T>::print() const
{
	DoubleNode<T>* PA = front->next;
	if (count == 0)
	{
		cout << "{ }" << endl;
		return;
	}

	cout << "{ ";
	for (; PA->next != front; PA = PA->next)
	{
		cout << PA->data << ", ";
	}

	cout << PA->data << " }" << endl;
}

template<class T>
inline bool DoubleList<T>::invert()
{
	if (count < 2)return true;
	 
	rear = front->next;
	DoubleNode<T>* temp,*PA = front;
	
	while (PA != rear)
	{
		temp = PA->prior;
		PA->prior = PA->next;
		PA->next = temp;
		PA = PA->next;
	}

	temp = PA->prior;
	PA->prior = PA->next;
	PA->next = temp;

	return true;
}

template<class T>
DoubleList<T>::~DoubleList()
{
	DoubleNode<T>* PA = rear;
	DoubleNode<T>* temp = PA->prior;
	while (PA->next != front)
	{
		delete PA;
		PA = temp;
		temp = PA->prior;
		count--;
	}
	delete PA;
	delete front;
	front = NULL;
	rear = NULL;
}

