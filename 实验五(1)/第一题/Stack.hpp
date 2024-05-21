#ifndef STACK_HPP
#define STACK_HPP

#pragma once
#include<iostream>
using namespace std;


template<class T>
struct Node{
	T data;
	Node<T>* next;
};

template<class T>
class Stack{
public:
	Stack();					//默认构造函数
	~Stack();					//析构函数
	bool empty();				//判断栈空
	bool get_top(T& x);			//取栈顶元素
	bool push(const T x);		//入栈
	bool pop();					//出栈
private:
	int count;					//总数
	Node<T>* top;				//栈顶指针
};

template<class T>
Stack<T>::Stack(){
	count = 0;
	top = NULL;
}

template<class T>
bool Stack<T>::empty(){
	return count == 0;		//return top == NULL
}

template<class T>
bool Stack<T>::get_top(T& x){
	if (empty())
		return false;
	x = top->data;
	return true;
}

template<class T>
bool Stack<T>::push(const T x){
	Node<T>* s = new Node<T>;
	s->data = x;
	s->next = top;
	top = s;
	count++;

	return true;
}

template<class T>
bool Stack<T>::pop(){
	if (empty())
		return false;
	Node<T>* temp = top;
	top = top->next;
	delete temp;
	count--;
	return true;
}

template<class T>
Stack<T>::~Stack(){
	while (!empty())
		pop();
}

#endif // STACK_HPP
