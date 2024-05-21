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
	List();								//Ĭ�Ϲ��캯��
	List(List& list);							//�������캯��
	List(int A[], int n);						//���鹹�캯��
	~List();									//��������

	//��ȡ�����Ա����
	int length()const;							//�󳤶�
	Node* get_head() { return head; }			//��ȡ�����ͷָ��

	//�������
	void append(int n);							//β��	

	//��������
	void print()const;							//�������
	void get_sameelement(List list,List& objlist);		//ȡ����ͬԪ�ص���������

private:
	int count;
	Node* head;
	Node* rear;
};

void List::get_sameelement(List list, List& objlist)
{
	if (count == 0 || list.length() == 0)return;	//���������⴦��
	Node* cur1 = head->next;
	Node* cur2 = list.get_head()->next;
	for (; cur1 != NULL && cur2 != NULL; cur1 = cur1->next)		//cur1����
	{
		Node* temp = cur2;
		bool isadd = 0;
		for (; cur2->data <= cur1->data && cur2 != NULL; cur2 = cur2->next)
		{
			if (cur1->data == cur2->data)		//�ҵ���ͬԪ�أ����
			{
				objlist.append(cur1->data);
				isadd = 1;
				cur2 = cur2->next;
				break;
			}
		}
		if (isadd == 0)cur2 = temp;		//δ�ҵ���cur2�ع�
	}
}

void List::append(int n)
{
	Node* node = new Node;
	node->data = n;
	node->next = NULL;

	rear->next = node;
	rear = node;
	count++;
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




