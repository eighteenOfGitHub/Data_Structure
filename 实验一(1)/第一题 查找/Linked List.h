#pragma once
#pragma once
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class List	//������
{
public:
	//����
	List();										//Ĭ�Ϲ��캯��
	List(List& list);							//�������캯��
	List(int A[], int n);						//���鹹�캯��
	~List();									//��������

	//��ȡ�����Ա����
	int length()const;							//�󳤶�
	Node* get_head() { return head; }			//��ȡ�����ͷָ��

	//�������
	Node* get_pnode(int i);						//��õ� i ������ָ��
	
	//��������
	void print()const;							//���Ԫ��
private:
	int count;
	Node* head;
	Node* rear;
};

Node* List::get_pnode(int i)
{
	Node* PA = head;
	if (i > count)return NULL;
	for (int j = 0; j < i; j++)
		PA = PA->next;
	return PA;
}

void List::print()const
{
	if (count == 0)
	{
		cout << " is NULL!" << endl;
		return;
	}

	Node* PA = head;
	while (PA->next != NULL)
	{
		PA = PA->next;
		cout << PA->data << " ";
	}
	cout << endl;
}

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

List::List(int A[], int n)
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



