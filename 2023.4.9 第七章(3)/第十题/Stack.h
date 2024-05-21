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
	Stack();			//Ĭ�Ϲ��캯��
	void Push(int n);	//��ջ
	void Pop();			//��ջ
	bool Empty()const;	//�ж��Ƿ�Ϊ��
	Node* get_top()const;				//����ջ��ָ��
	int get_count()const;				//����Ԫ�ظ���
	void Invert_Print(Node* cur)const;	//�����������Ԫ��
private:
	Node* _top;			//ջ��ָ��Ϊ��
	int _count;
};

Stack::Stack()			//Ĭ�Ϲ��캯��
{
	Node* node = new Node;
	node->_next = NULL;
	_top = node;
	_count = 0;
}

void Stack::Push(int n)	//��ջ
{
	Node* node = new Node;
	node->_data = n;
	node->_next = _top->_next;
	_top->_next = node;
	_count++;
}

void Stack::Pop()			//��ջ
{
	if (_top->_next == NULL)return;
	Node* temp = _top->_next;
	_top->_next= _top->_next->_next;
	delete temp;
	_count--;
}

bool Stack::Empty()const	//�ж��Ƿ�Ϊ��
{
	return _count == 0;
}

Node* Stack::get_top()const	//����ջ��ָ��
{
	return _top;
}
int Stack::get_count()const	//����Ԫ�ظ���
{
	return _count;
}

void Stack::Invert_Print(Node* cur)const	//�����������Ԫ��
{
	if (_count == 0)return;
	if (cur->_next != NULL)
	{
		this->Invert_Print(cur->_next);
		cout << cur->_next->_data << " ";
	}

}
