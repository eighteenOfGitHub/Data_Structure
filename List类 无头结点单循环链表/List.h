#pragma once
#include<iostream>
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

	Node* get_front()const; //����׽���ַ
	Node* get_rear()const;	//���β����ַ
	int length()const;		//���������

	void Print()const;		//�������

private:
	void Destroy(Node* cur,Node* node);	//ɾ���ý���Ժ�����������ýڵ㣩

private:
	int _count;
	Node* _front;
	Node* _rear;
};

List::List()					//Ĭ�Ϲ���		
{
	_front = new Node;
	_rear = _front;
	_count = 0;
}
List::List(int A[], int n)	//���鹹��
{
	Node* cur = new Node(A[0]);	//���ڱ���
	_front = cur;
	Node* temp = cur; //������һ��������ӵ�ǰ���
	cur = cur->_next;

	for (int i = 1; i < n; i++)
	{
		cur = new Node(A[i]);
		temp->_next = cur;
		temp = cur;
		cur = cur->_next;
	}

	temp->_next = _front;		//β��������׽�㣬����ѭ��
	_rear = temp;
	_count = n;
}
List::List(List& list)		//��������
{
	Node* p = list.get_front();
	Node* cur = new Node(p->_data);
	_front = cur;
	Node* temp = cur;
	cur = cur->_next;
	p = p->_next;

	for (;p != _front; p = p->_next)
	{
		cur = new Node(p->_data);
		temp->_next = cur;
		temp = cur;
		cur = cur->_next;
	}

	temp->_next = _front;		//β��������׽�㣬����ѭ��
	_rear = temp;
	_count = list.length();
}
List::~List()				//����
{
	Destroy(_front,_front);
	_rear = NULL;
	_count = 0;
}

void List::Destroy(Node* cur, Node* node)
{
	if (cur == node) { return; }
	Destroy(cur->_next,node);
	delete cur;
	cur = NULL;
}

void List::Print()const		//�������
{
	Node* cur = _front;
	cout << cur->_data << " ";
	cur = cur->_next;
	for (; cur != _front; cur = cur->_next)
		cout << cur->_data << " ";
	cout << endl;
}

Node* List::get_front()const //����׽���ַ
{
	return _front;
}
Node* List::get_rear()const	//���β����ַ
{
	return _rear;
}
int List::length()const		//���������
{
	return _count;
}