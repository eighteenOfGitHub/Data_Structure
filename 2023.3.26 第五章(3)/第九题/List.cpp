#include"List.h"
#include<iostream>
using namespace std;

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

List::List(char A[], int n)
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

bool List::get_element(const int i, char& x)const
{
	Node* p = head->next;
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

Node* List::locate(const char x)const
{
	Node* p = head->next;
	while (p != NULL)
	{
		if (p->data == x)return p;
		else p = p->next;
	}
	return NULL;
}

bool List::insert(const int i, const char x)
{
	Node* p = head;
	int j = 0;
	for (; j != i - 1 && p != NULL; j++)
		p = p->next;
	if (i < 1 || i>count + 1)	//等价与if(p == NULL) 
		return false;

	Node* s = new Node;	//产生新结点
	s->data = x;
	s->next = p->next;
	p->next = s;
	count++;
	return true;
}

bool List::delete_end()
{
	if (count == 0)
		return false;
	Node* p = head;
	while (p->next->next != NULL)
		p = p->next;
	rear = p;
	delete p->next;
	p->next = NULL;
	return true;
}

void List::copy(List A)
{
	Node* PA = A.get_head()->next;
	Node* PB = head;					//设置当前表，即B表尾指针
	while (PA != NULL)					//在A表中还有元素时
	{
		Node* s = new Node;				//产生结点
		s->data = PA->data;				//复制结点的值
		PB->next = s;					// 插入复制的结点到表尾
		PB = s;							//重新指示表尾，以便下一个元素插入
		count++;						//继续复制A表的下一个元素

		PA = PA->next;
		PB->next = NULL;				//将B表尾结点的后继指针置为空
	}
}


bool List::append(const char x)
{
	Node* s = new Node;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
	count++;
	return true;
}

bool List::isequal(List A)
{
	if (count != A.count)
		return false;
	else
	{
		Node* PA = head->next;
		Node* PB = A.head->next;
		while (PA != NULL)
		{
			if (PA->data != PB->data)
				return false;
			PA = PA->next;
			PB = PB->next;
		}
		return true;
	}
}