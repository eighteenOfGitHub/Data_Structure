#include"List.h"
#include<iostream>
using namespace std;

List::List()
{
	head = new Node;
	head->next = NULL;
	rear = head;
	count = 0;
}

List::List(List& list)
{
	head = new Node;
	head->next = NULL;
	rear = head;
	count = 0;

	Node* PA = list.get_head()->next;
	Node* PB = head;					//���õ�ǰ����B��βָ��
	while (PA != NULL)					//��A���л���Ԫ��ʱ
	{
		Node* s = new Node;				//�������
		s->data = PA->data;				//���ƽ���ֵ
		PB->next = s;					// ���븴�ƵĽ�㵽��β
		PB = s;							//����ָʾ��β���Ա���һ��Ԫ�ز���
		rear = s;
		count++;						//��������A�����һ��Ԫ��

		PA = PA->next;
		PB->next = NULL;				//��B��β���ĺ��ָ����Ϊ��
	}
}

List::List(char A[], int n)
{
	head = new Node;
	head->next = NULL;
	rear = head;

	Node* PA = head;
	for (int i = 0; i < n; i++)
	{
		Node* s = new Node;
		s->data = A[i];
		s->next = NULL;
		PA->next = s;
		PA = s;
	}

	rear = PA;
	count = n;
}

List::~List()
{
	while (head != rear)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}

int List::length() const
{
	return count;
}

bool List::get_element(const int i, char& x)const
{
	Node* p = head->next;
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

Node* List::locate(const char x)const
{
	Node* p = head->next;
	while (p != NULL)
	{
		if (p->data == x)return p;
		else p = p->next;
	}
	return NULL;
}

bool List::insert(const int i, const char x)
{
	Node* p = head;
	int j = 0;
	for (; j != i - 1 && p != NULL; j++)
		p = p->next;
	if (i < 1 || i>count + 1)	//�ȼ���if(p == NULL) 
		return false;

	Node* s = new Node;	//�����½��
	s->data = x;
	s->next = p->next;
	p->next = s;
	count++;
	return true;
}

bool List::delete_end()
{
	if (count == 0)
		return false;
	Node* p = head;
	while (p->next->next != NULL)
		p = p->next;
	rear = p;
	delete p->next;
	p->next = NULL;
	return true;
}

void List::copy(List A)
{
	Node* PA = A.get_head()->next;
	Node* PB = head;					//���õ�ǰ����B��βָ��
	while (PA != NULL)					//��A���л���Ԫ��ʱ
	{
		Node* s = new Node;				//�������
		s->data = PA->data;				//���ƽ���ֵ
		PB->next = s;					// ���븴�ƵĽ�㵽��β
		PB = s;							//����ָʾ��β���Ա���һ��Ԫ�ز���
		count++;						//��������A�����һ��Ԫ��

		PA = PA->next;
		PB->next = NULL;				//��B��β���ĺ��ָ����Ϊ��
	}
}


bool List::append(const char x)
{
	Node* s = new Node;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
	count++;
	return true;
}

bool List::isequal(List A)
{
	if (count != A.count)
		return false;
	else
	{
		Node* PA = head->next;
		Node* PB = A.head->next;
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