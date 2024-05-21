#pragma once
#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class List	//������
{
public:
	List();										//Ĭ�Ϲ��캯��
	List(List<T>& list);						//�������캯��
	int length()const;							//�󳤶�
	~List();									//��������
	bool get_element(const int i, T& x)const;	//�����ȡԪ��
	Node<T>* locate(const T x)const;			//����Ԫ��
	bool insert(const int i, const T x);		//����Ԫ��(��i��֮ǰ��ԭ���ĵ�i��Ԫ�ر�ɵ�i+1��)
	//bool delete_element(const int i);			//ɾ��Ԫ��
	bool delete_end();							//ɾ��βԪ��
	Node<T>* get_head() { return head; }		//��ȡ�����ͷָ��
	T get_rear_element()						//��ȡ�����βָ��
	{
		return rear->data;
	}
	void copy(List A);							//A�����Ƶ�B����
	bool append(const T x);						//β��
	bool isequal(List<T> A);					//�ж������Ƿ����
private:
	int count;
	Node<T>* head;
	Node<T>* rear;
};

template<class T>
List<T>::List()
{
	head = new Node<T>;
	head->next = NULL;
	rear = head;
	count = 0;
}

template<class T>
List<T>::List(List<T>& list)
{
	head = new Node<T>;
	head->next = NULL;
	rear = head;
	count = 0;
	
	Node<T>* PA = list.get_head()->next;
	Node<T>* PB = head;					//���õ�ǰ����B��βָ��
	while (PA != NULL)					//��A���л���Ԫ��ʱ
	{
		Node<T>* s = new Node<T>;			//�������
		s->data = PA->data;				//���ƽ���ֵ
		PB->next = s;					// ���븴�ƵĽ�㵽��β
		PB = s;							//����ָʾ��β���Ա���һ��Ԫ�ز���
		rear = s;
		count++;						//��������A�����һ��Ԫ��

		PA = PA->next;					
		PB->next = NULL;				//��B��β���ĺ��ָ����Ϊ��
	}
}

template<class T>
List<T>::~List()
{
	while (head != rear)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}

template<class T>
int List<T>::length() const
{
	return count;
}

template<class T>
bool List<T>::get_element(const int i, T& x)const
{
	Node<T>* p = head->next;
	int j = 1;
	while (p != NULL && j != i)	//����Ŀ����򲻿գ��ͼ�������
	{
		p = p->next;
		j++;
	}
	if (p == NULL)return false;
	x = p->data;
	return true;
}

template<class T>
Node<T>* List<T>::locate(const T x)const
{
	Node<T>* p = head->next;
	while (p != NULL)
	{
		if (p->data == x)return p;
		else p = p->next;
	}
	return NULL;
}

template<class T>
bool List<T>::insert(const int i, const T x)
{
	Node<T>* p = head;
	int j = 0;
	for (; j != i - 1 && p != NULL; j++)
		p = p->next;
	if (i < 1 || i>count + 1)	//�ȼ���if(p == NULL) 
		return false;

	Node<T>* s = new Node<T>;	//�����½��
	s->data = x;
	s->next = p->next;
	p->next = s;
	count++;
	return true;
}

template<class T>
 bool List<T>::delete_end()
{
	 if (count == 0)
		 return false;
	 Node<T>* p = head;
	 while (p->next->next != NULL)
		 p = p->next;
	 rear = p;
	 delete p->next;
	 p->next = NULL;
	return true;
}

/*
template<class T>
bool List<T>::delete_element(const int i)
{
	Node<T>* p = head;
	int j = 0;
	while (j != i - 1 && p != NULL)
	{
		p = p->next;
		j++:
	}
	if (i<0 || i>count)
		return false;
	Node<T>* u = p->next;
	if (u->next == NULL)	//����β���⴦��
	{
		rear = p;
		rear->next = NULL;
		delete u;
	}
	else
	{
		p->next = u->next;
		delete u;
	}
	count--;
	return true;
}
*/

template<class T>
void List<T>::copy(List<T> A)
{
	Node<T>* PA = A.get_head()->next;
	Node<T>* PB = head;					//���õ�ǰ����B��βָ��
	while (PA != NULL)					//��A���л���Ԫ��ʱ
	{
		Node<T>* s = new Node<T>;		//�������
		s->data = PA->data;				//���ƽ���ֵ
		PB->next = s;					// ���븴�ƵĽ�㵽��β
		PB = s;							//����ָʾ��β���Ա���һ��Ԫ�ز���
		count++;						//��������A�����һ��Ԫ��

		PA = PA->next;					
		PB->next = NULL;				//��B��β���ĺ��ָ����Ϊ��
	}
}

template<class T>
bool List<T>::append(const T x)
{
	Node<T>* s = new Node<T>;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
	count++;
	return true;
}

template<class T>
bool List<T>::isequal(List<T> A)
{
	if (count != A.count)
		return false;
	else
	{
		Node<T>* PA = head->next;
		Node<T>* PB = A.head->next;
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