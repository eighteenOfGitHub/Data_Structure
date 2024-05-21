#pragma once
#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;		//数据域
	node<T>* next;	//指针域
};

template<class T>
class Queue
{
public:
	Queue();						//默认构造
	Queue(Queue<T>& queue);			//拷贝构造
	~Queue();						//析构
	bool empty() const;				//队空
	bool get_front(T& x)const;		//获取首元素
	bool append(const T x);			//入队
	bool serve();					//出队
private:
	int count;						//总量
	node<T>* front, * rear;			//头指针，尾指针
};

template<class T>
Queue<T>::Queue()
{
	front = new node<T>;		//头指针指向头结点，头结点无数据域
	rear = front;			//尾指针接到头指针上
	front->next = NULL;		//头指针质置空
	count = 0;
}

template<class T>
Queue<T>::Queue(Queue<T>& queue)
{
	front = new node<T>;		//头指针指向头结点，头结点无数据域
	rear = front;			//尾指针接到头指针上
	front->next = NULL;		//头指针质置空
	count = 0;

	//深拷贝
	node<T>* ptr = queue.front;
	while (ptr->next != NULL)
	{
		append(const T ptr->next->data);
		ptr = ptr->next;
	}

}

template<class T>
bool Queue<T>::empty()const
{
	return rear == front;
}

template<class T>
bool Queue<T>::get_front(T& x)const
{
	if (empty())
		return false;
	x = front->next->data;
	return true;
}

template<class T>
bool Queue<T>::append(const T x)
{
	node<T>* s = new node<T>;	//创建新结点
	s->data = x;			//存入数据
	s->next = NULL;			//next置空

	rear->next = s;			//将新结点连接到尾结点的next

	rear = s;				//更新尾结点
	count++;				//更新总数量

	return true;
}

template<class T>
bool Queue<T>::serve()				//出队
{
	node<T>* temp;
	if (empty())
		return false;
	temp = front->next;				//暂存首结点
	front->next = temp->next;		//头指针连接第二个结点
	delete temp;					//删除头结点
	count--;						//更新总数量

	if (front->next == NULL)		//如果队空，则尾结点连接头结点	
		rear = front;

	return true;
}

template<class T>
Queue<T>::~Queue()
{
	while (!empty())serve();
	delete front;
}