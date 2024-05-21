#pragma once
#include<iostream>
using namespace std;

struct Node
{
	int _data;
	Node* _next;
};

class Stack
{
public:
	Stack();			//默认构造函数
	void Push(int n);	//入栈
	void Pop();			//出栈
	bool Empty()const;	//判断是否为空
	Node* get_top()const;				//返回栈顶指针
	int get_count()const;				//返回元素个数
	void Invert_Print(Node* cur)const;	//倒置输出所有元素
private:
	Node* _top;			//栈顶指针为空
	int _count;
};

Stack::Stack()			//默认构造函数
{
	Node* node = new Node;
	node->_next = NULL;
	_top = node;
	_count = 0;
}

void Stack::Push(int n)	//入栈
{
	Node* node = new Node;
	node->_data = n;
	node->_next = _top->_next;
	_top->_next = node;
	_count++;
}

void Stack::Pop()			//出栈
{
	if (_top->_next == NULL)return;
	Node* temp = _top->_next;
	_top->_next= _top->_next->_next;
	delete temp;
	_count--;
}

bool Stack::Empty()const	//判断是否为空
{
	return _count == 0;
}

Node* Stack::get_top()const	//返回栈顶指针
{
	return _top;
}
int Stack::get_count()const	//返回元素个数
{
	return _count;
}

void Stack::Invert_Print(Node* cur)const	//倒置输出所有元素
{
	if (_count == 0)return;
	if (cur->_next != NULL)
	{
		this->Invert_Print(cur->_next);
		cout << cur->_next->_data << " ";
	}

}
