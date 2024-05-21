#pragma once
#include<iostream>
using namespace std;

struct Node
{
	int _m;
	Node* _next;
};

class Stack
{
public:
	Stack();
	bool Empty() const;					//�ж�ջ��
	Node* get_top() const;				//�õ�ջ��ָ��
	void push(const int m);				//��ջ
	void pop();							//��ջ
private:
	Node* _top;
	int _count;
};

Stack::Stack()
{
	Node* top = new Node;
	top->_next = NULL;
	_top = top;
	_count = 0;
}

Node* Stack::get_top() const				//�õ�ջ��ָ��
{
	return _top;
}

bool Stack::Empty() const					//�ж�ջ��
{
	return _count == 0;
}

void Stack::push(const int m)	//��ջ
{
	Node* node = new Node;
	node->_m = m;
	node->_next = _top;
	_top = node;

	_count++;
}

void Stack::pop()							//��ջ
{
	Node* temp = _top;
	_top = _top->_next;
	
	temp->_next = NULL;
	delete temp;
	
	_count--;
}
