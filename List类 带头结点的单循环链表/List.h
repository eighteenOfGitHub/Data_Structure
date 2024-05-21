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
	List();					//默认构造		
	List(int A[], int n);	//数组构造
	List(List& list);		//拷贝构造
	~List();				//析构

	Node* get_head()const; //获得头结点地址
	Node* get_rear()const;	//获得尾结点地址
	int length()const;		//获得链表长度

	void Print()const;			//遍历输出
	void Append(const int data);//尾增
	bool is_specialfunc()const; //判断是否满足：其中每个结点的元素值与其序号的差的绝对值不大于３

private:
	void Destroy(Node* cur, Node* node);	//删除该结点以后的链表（包括该节点）

private:
	int _count;
	Node* _head;	//头结点
	Node* _rear;
};

bool List::is_specialfunc()const //判断是否满足：其中每个结点的元素值与其序号的差的绝对值不大于３
{
	int i = 1;
	Node* cur = _head->_next;
	for (; cur != _head; cur = cur->_next)
	{
		if (abs(i - cur->_data) <= 3) { return false; }
	}
	return true;
}

List::List()					//默认构造		
{
	_head = new Node;
	_rear = _head;
	_count = 0;
}
List::List(int A[], int n)	//数组构造
{
	_head = new Node;
	Node* cur = _head, * temp;

	for (int i = 0; i < n; i++)
	{
		temp = new Node(A[i]);
		cur->_next = temp;
		cur = cur->_next;
	}

	cur->_next = _head;		//尾结点连接首结点，构成循环
	_rear = cur;
	_count = n;
}
List::List(List& list)		//拷贝构造
{
	Node* p = list.get_head();
	_head = new Node;
	Node* cur = _head, * temp;

	for (; p != _head; p = p->_next)
	{
		temp = new Node(p->_data);
		cur->_next = temp;
		cur = cur->_next;
	}

	cur->_next = _head;		//尾结点连接首结点，构成循环
	_rear = cur;
	_count = list.length();
}
List::~List()				//析构
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

void List::Print()const		//遍历输出
{
	Node* cur = _head->_next;
	for (; cur != _head; cur = cur->_next)
		cout << cur->_data << " ";
	cout << endl;
}

void List::Append(const int data)//尾增
{
	Node* node = new Node(data);
	_rear->_next = node;
	_rear = node;
	_rear->_next = _head;
	_count++;
}

Node* List::get_head()const //获得头结点地址
{
	return _head;
}
Node* List::get_rear()const	//获得尾结点地址
{
	return _rear;
}
int List::length()const		//获得链表长度
{
	return _count;
}

