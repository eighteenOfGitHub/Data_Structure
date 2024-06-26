#pragma once
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class List	//单链表
{
public:
	//构造
	List();										//默认构造函数
	List(List& list);							//拷贝构造函数
	List(int A[], int n);						//数组构造函数
	~List();									//析构函数

	//获取链表成员变量
	int length()const;							//求长度
	Node* get_head() { return head; }			//读取链表表头指针

	//操作结点
	void append(int n);							//尾增	

	//操作链表
	void print()const;							//遍历输出
	void depart(List& list1, List& list2);		//分离奇偶结点

private:
	int count;
	Node* head;
	Node* rear;
};
void List::append(int n)
{
	Node* node = new Node;
	node->data = n;
	node->next = NULL;
	
	rear->next = node;
	rear = node;
	count++;
}

void List::depart(List& list1, List& list2)
{
	Node* cur = head->next;
	for (int i = 1; cur != NULL; i++,cur = cur->next)
	{
		if (i % 2 == 1)list1.append(cur->data);
		else list2.append(cur->data);
	}
}

void List::print()const
{
	if (count == 0)
	{
		cout << " is NULL!" << endl;
		return;
	}

	Node* PA = head;
	while (PA->next != NULL)
	{
		PA = PA->next;
		cout << PA->data << " ";
	}
	cout << endl;
}

List::List()
{
	head = new Node;
	head->next = NULL;
	rear = head;
	count = 0;
}

List::List(List& list)
{
	head = new Node;
	head->next = NULL;
	rear = head;
	count = 0;

	Node* PA = list.get_head()->next;
	Node* PB = head;					//设置当前表，即B表尾指针
	while (PA != NULL)					//在A表中还有元素时
	{
		Node* s = new Node;				//产生结点
		s->data = PA->data;				//复制结点的值
		PB->next = s;					// 插入复制的结点到表尾
		PB = s;							//重新指示表尾，以便下一个元素插入
		rear = s;
		count++;						//继续复制A表的下一个元素

		PA = PA->next;
		PB->next = NULL;				//将B表尾结点的后继指针置为空
	}
}

List::List(int A[], int n)
{
	head = new Node;
	head->next = NULL;
	rear = head;

	Node* PA = head;
	for (int i = 0; i < n; i++)
	{
		Node* s = new Node;
		s->data = A[i];
		s->next = NULL;
		PA->next = s;
		PA = s;
	}

	rear = PA;
	count = n;
}

List::~List()
{
	while (head != rear)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}

int List::length() const
{
	return count;
}

