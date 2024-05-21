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
	List();					//默认构造		
	List(int A[], int n);	//数组构造
	List(List& list);		//拷贝构造
	~List();				//析构

	Node* get_front()const; //获得首结点地址
	Node* get_rear()const;	//获得尾结点地址
	int length()const;		//获得链表长度

	void Print()const;		//遍历输出

private:
	void Destroy(Node* cur,Node* node);	//删除该结点以后的链表（包括该节点）

private:
	int _count;
	Node* _front;
	Node* _rear;
};

List::List()					//默认构造		
{
	_front = new Node;
	_rear = _front;
	_count = 0;
}
List::List(int A[], int n)	//数组构造
{
	Node* cur = new Node(A[0]);	//用于遍历
	_front = cur;
	Node* temp = cur; //用于上一个结点连接当前结点
	cur = cur->_next;

	for (int i = 1; i < n; i++)
	{
		cur = new Node(A[i]);
		temp->_next = cur;
		temp = cur;
		cur = cur->_next;
	}

	temp->_next = _front;		//尾结点连接首结点，构成循环
	_rear = temp;
	_count = n;
}
List::List(List& list)		//拷贝构造
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

	temp->_next = _front;		//尾结点连接首结点，构成循环
	_rear = temp;
	_count = list.length();
}
List::~List()				//析构
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

void List::Print()const		//遍历输出
{
	Node* cur = _front;
	cout << cur->_data << " ";
	cur = cur->_next;
	for (; cur != _front; cur = cur->_next)
		cout << cur->_data << " ";
	cout << endl;
}

Node* List::get_front()const //获得首结点地址
{
	return _front;
}
Node* List::get_rear()const	//获得尾结点地址
{
	return _rear;
}
int List::length()const		//获得链表长度
{
	return _count;
}