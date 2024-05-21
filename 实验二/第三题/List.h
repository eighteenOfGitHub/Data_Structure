#pragma once
#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
	int _data;
	Node* _next;

	Node()
	{
		_next = NULL;
	}
	Node(int data) :_data(data)
	{
		_next = NULL;
	}
};

class List
{
public:
	List();					//Ĭ�Ϲ���		
	List(int A[], int n);	//���鹹��
	List(List& list);		//��������
	~List();				//����

	Node* get_head()const; //���ͷ����ַ
	Node* get_rear()const;	//���β����ַ
	int length()const;		//���������

	void Print()const;			//�������
	void Append(const int data);//β��
	void Get_Intersection(const List list1, const List list2);	//�󽻼�
	void Get_Unionset(const List list1, const List list2);		//�󲢼�

private:
	void Destroy(Node* cur, Node* node);	//ɾ���ý���Ժ�����������ýڵ㣩

private:
	int _count;
	Node* _head;	//ͷ���
	Node* _rear;
};

void  List::Get_Intersection(const List list1, const List list2)	//�󽻼�
{
	Node* cur1 = list1.get_head()->_next;
	Node* cur2 = list2.get_head()->_next;
	Node* temp;

	for (; cur1 != list1.get_head(); cur1 = cur1->_next)
	{
		temp = cur2;
		for (;cur2 != list2.get_head() && cur2->_data <= cur1->_data; cur2 = cur2->_next)
		{
			if (cur1->_data == cur2->_data)
			{
					Append(cur1->_data);
					break;
			}
		}
		if (cur2 == list2.get_head() || cur2->_data > cur1->_data)
			cur2 = temp;
	}
	_rear->_next = _head;

}
void List::Get_Unionset(const List list1, const List list2)	//�󲢼�
{
	Node* cur1 = list1.get_head()->_next;
	Node* cur2 = list2.get_head()->_next;

	while (cur1 != list1.get_head() && cur2 != list2.get_head())
	{
		if (cur1->_data < cur2->_data)
		{
			Append(cur1->_data);
			cur1 = cur1->_next;
		}
		else if(cur1->_data > cur2->_data)
		{
			Append(cur2->_data);
			cur2 = cur2->_next;
		}
		else
		{
			Append(cur1->_data);
			cur1 = cur1->_next;
			cur2 = cur2->_next;
		}
	}
	while (cur1 != list1.get_head())
	{
		Append(cur1->_data);
		cur1 = cur1->_next;
	}
	while (cur2 != list2.get_head())
	{
		Append(cur2->_data);
		cur2 = cur2->_next;
	}
}

List::List()					//Ĭ�Ϲ���		
{
	_head = new Node;
	_rear = _head;
	_rear->_next = _head;
	_count = 0;
}
List::List(int A[], int n)	//���鹹��
{
	_head = new Node;
	Node* cur = _head, * temp;

	for (int i = 0; i < n; i++)
	{
		temp = new Node(A[i]);
		cur->_next = temp;
		cur = cur->_next;
	}

	cur->_next = _head;		//β��������׽�㣬����ѭ��
	_rear = cur;
	_count = n;
}
List::List(List& list)		//��������
{
	_head = new Node;
	Node* p = list.get_head()->_next;
	Node* cur = _head, * temp;

	for (; p != list.get_head(); p = p->_next)
	{
		temp = new Node(p->_data);
		cur->_next = temp;
		cur = cur->_next;
	}

	cur->_next = _head;		//β��������׽�㣬����ѭ��
	_rear = cur;
	_count = list.length();
}
List::~List()				//����
{
	Destroy(_head, _head);
	_rear = NULL;
	_count = 0;
}

void List::Destroy(Node* cur, Node* node)
{
	if (cur == node) { return; }
	Destroy(cur->_next, node);
	delete cur;
	cur = NULL;
}

void List::Print()const		//�������
{
	Node* cur = _head->_next;
	for (; cur != _head; cur = cur->_next)
		cout << cur->_data << " ";
	cout << endl;
}

void List::Append(const int data)//β��
{
	Node* node = new Node(data);
	_rear->_next = node;
	_rear = node;
	_rear->_next = _head;
	_count++;
}

Node* List::get_head()const //���ͷ����ַ
{
	return _head;
}
Node* List::get_rear()const	//���β����ַ
{
	return _rear;
}
int List::length()const		//���������
{
	return _count;
}
