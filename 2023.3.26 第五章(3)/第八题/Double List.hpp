#pragma once
#include<iostream>
using namespace std;

template<class T>
struct DoubleNode
{
	DoubleNode<T>* prior;
	T data;
	DoubleNode<T>* next;
};

template<class T>
class DoubleList
{
public:
	DoubleList();							//构造函数
	DoubleList(const T A[], const int n);	//数组构造函数
	DoubleList(DoubleList<T>& list);		//拷贝构造函数
	~DoubleList();							//析构函数
	DoubleNode<T>* get_front() const;		//得到头结点指针
	DoubleNode<T>* get_rear() const;		//得到尾结点指针
	int length() const;						//得到链表长度
	void print() const;						//控制台输出元素
	bool invert();							//倒置
private:
	DoubleNode<T>* front;
	DoubleNode<T>* rear;
	int count;
};

template<class T>
DoubleList<T>::DoubleList()
{
	DoubleNode<T>* node = new DoubleNode<T>;

	rear = node;
	front = node;
	node->next = front;
	node->prior = rear;

	count = 0;
}

template<class T>
DoubleList<T>::DoubleList(const T A[], const int n)
{
	DoubleNode<T>* PA = new DoubleNode<T>;

	rear = PA;
	front = PA;
	PA->next = front;
	PA->prior = rear;

	count = 0;

	for (int i = 0; i < n; i++)
	{
		DoubleNode<T>* node = new DoubleNode<T>;

		PA->next = node;		//更新前结点

		node->data = A[i];		//更新节点变量
		node->prior = PA;
		node->next = front;

		rear = node;			//更新链表变量
		front->prior = node;
		count++;

		PA = node;				//更新临时结点，为下一次添加做准备
	}
}

template<class T>
DoubleList<T>::DoubleList(DoubleList<T>& doublelist)
{
	DoubleNode<T>* PA = new DoubleNode<T>;
	DoubleNode<T>* PB = doublelist.get_front()->next;

	//构造头结点
	rear = PA;
	front = PA;
	PA->next = front;
	PA->prior = rear;

	count = 0;
	//添加数据
	for (; PB != doublelist.get_front(); PB = PB->next)
	{
		DoubleNode<T>* node = new DoubleNode<T>;

		PA->next = node;		//更新前结点

		node->data = PB->data;	//更新节点变量
		node->prior = PA;
		node->next = front;

		rear = node;			//更新链表变量
		front->prior = node;
		count++;

		PA = node;				//更新临时结点，为下一次添加做准备
	}
}

template<class T>
DoubleNode<T>* DoubleList<T>::get_front() const
{
	return front;
}

template<class T>
DoubleNode<T>* DoubleList<T>::get_rear() const
{
	return rear;
}

template<class T>
int DoubleList<T>::length() const
{
	return count;
}						//得到链表长度

template<class T>
void DoubleList<T>::print() const
{
	DoubleNode<T>* PA = front->next;
	if (count == 0)
	{
		cout << "{ }" << endl;
		return;
	}

	cout << "{ ";
	for (; PA->next != front; PA = PA->next)
	{
		cout << PA->data << ", ";
	}

	cout << PA->data << " }" << endl;
}

template<class T>
inline bool DoubleList<T>::invert()
{
	if (count < 2)return true;
	 
	rear = front->next;
	DoubleNode<T>* temp,*PA = front;
	
	while (PA != rear)
	{
		temp = PA->prior;
		PA->prior = PA->next;
		PA->next = temp;
		PA = PA->next;
	}

	temp = PA->prior;
	PA->prior = PA->next;
	PA->next = temp;

	return true;
}

template<class T>
DoubleList<T>::~DoubleList()
{
	DoubleNode<T>* PA = rear;
	DoubleNode<T>* temp = PA->prior;
	while (PA->next != front)
	{
		delete PA;
		PA = temp;
		temp = PA->prior;
		count--;
	}
	delete PA;
	delete front;
	front = NULL;
	rear = NULL;
}

