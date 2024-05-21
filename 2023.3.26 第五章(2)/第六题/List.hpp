#pragma once
#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class List	//单链表
{
public:
	List();										//默认构造函数
	List(List<T>& list);						//拷贝构造函数
	List(const T A[],int n);					//数组构造函数
	int length()const;							//求长度
	~List();									//析构函数
	bool get_element(const int i, T& x)const;	//按序号取元素
	Node<T>* locate(const T x)const;			//搜索元素
	bool insert(const int i, const T x);		//插入元素(第i个之前，原本的第i个元素变成第i+1个)
	bool delete_end();							//删除尾元素
	Node<T>* get_head() { return head; }		//读取链表表头指针
	Node<T>* get_rear() { return rear; }		//读取链表表尾指针
	bool isson(List<T> A);						//判断是否为子集
private:
	int count;
	Node<T>* head;
	Node<T>* rear;
};

template<class T>
List<T>::List()
{
	head = new Node<T>;
	head->next = NULL;
	rear = head;
	count = 0;
}

template<class T>
List<T>::List(List<T>& list)
{
	head = new Node<T>;
	head->next = NULL;
	rear = head;
	count = 0;

	Node<T>* PA = list.get_head()->next;
	Node<T>* PB = head;					//设置当前表，即B表尾指针
	while (PA != NULL)					//在A表中还有元素时
	{
		Node<T>* s = new Node<T>;			//产生结点
		s->data = PA->data;				//复制结点的值
		PB->next = s;					// 插入复制的结点到表尾
		PB = s;							//重新指示表尾，以便下一个元素插入
		rear = s;
		count++;						//继续复制A表的下一个元素

		PA = PA->next;
		PB->next = NULL;				//将B表尾结点的后继指针置为空
	}
}

template<class T>
inline List<T>::List(const T A[], int n)
{
	head = new Node<T>;
	head->next = NULL;
	rear = head;
	count = n;

	Node<T>* PA = head;					//设置当前表，即B表尾指针
	for (int i = 0; i < count; i++)
	{
		Node<T>* s = new Node<T>;			//产生结点
		s->data = A[i];				//复制结点的值
		PA->next = s;					// 插入复制的结点到表尾
		PA = s;							//重新指示表尾，以便下一个元素插入
		rear = s;
	}
	PA->next = NULL;				//将B表尾结点的后继指针置为空
}

template<class T>
List<T>::~List()
{
	while (head != rear)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}

template<class T>
int List<T>::length() const
{
	return count;
}

template<class T>
bool List<T>::get_element(const int i, T& x)const
{
	Node<T>* p = head->next;
	int j = 1;
	while (p != NULL && j != i)	//不是目标结点或不空，就继续搜索
	{
		p = p->next;
		j++;
	}
	if (p == NULL)return false;
	x = p->data;
	return true;
}

template<class T>
Node<T>* List<T>::locate(const T x)const
{
	Node<T>* p = head->next;
	while (p != NULL)
	{
		if (p->data == x)return p;
		else p = p->next;
	}
	return NULL;
}

template<class T>
bool List<T>::insert(const int i, const T x)
{
	Node<T>* p = head;
	int j = 0;
	for (; j != i - 1 && p != NULL; j++)
		p = p->next;
	if (i < 1 || i>count + 1)	//等价与if(p == NULL) 
		return false;

	Node<T>* s = new Node<T>;	//产生新结点
	s->data = x;
	s->next = p->next;
	p->next = s;
	count++;
	return true;
}

template<class T>
bool List<T>::delete_end()
{
	if (count == 0)
		return false;
	Node<T>* p = head;
	while (p->next->next != NULL)
		p = p->next;
	rear = p;
	delete p->next;
	p->next = NULL;
	return true;
}

template<class T>
bool List<T>::isson(List<T> A)
{
	Node<T>* PA = head->next;
	Node<T>* PB = A.get_head()->next;
	if (A.length() == 0)return true; 
	while (1)
	{
		if (PB->data != PA->data)
			PA = PA->next;
		else
			PB = PB->next;

		if (PA == NULL)
			return false;
		if (PB == NULL)
			return true;
	}
}


