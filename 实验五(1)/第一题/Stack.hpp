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
	Stack();					//Ĭ�Ϲ��캯��
	~Stack();					//��������
	bool empty();				//�ж�ջ��
	bool get_top(T& x);			//ȡջ��Ԫ��
	bool push(const T x);		//��ջ
	bool pop();					//��ջ
private:
	int count;					//����
	Node<T>* top;				//ջ��ָ��
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
