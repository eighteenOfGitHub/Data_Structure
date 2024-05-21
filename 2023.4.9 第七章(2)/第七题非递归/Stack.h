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
	bool Empty() const;					//ÅÐ¶ÏÕ»¿Õ
	Node* get_top() const;				//µÃµ½Õ»¶¥Ö¸Õë
	void push(const int m);				//ÈëÕ»
	void pop();							//³öÕ»
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

Node* Stack::get_top() const				//µÃµ½Õ»¶¥Ö¸Õë
{
	return _top;
}

bool Stack::Empty() const					//ÅÐ¶ÏÕ»¿Õ
{
	return _count == 0;
}

void Stack::push(const int m)	//ÈëÕ»
{
	Node* node = new Node;
	node->_m = m;
	node->_next = _top;
	_top = node;

	_count++;
}

void Stack::pop()							//³öÕ»
{
	Node* temp = _top;
	_top = _top->_next;
	
	temp->_next = NULL;
	delete temp;
	
	_count--;
}
