#pragma once

struct Node
{
	char data;
	Node* next;
};

class List	//单链表
{
public:
	//构造
	List();										//默认构造函数
	List(List& list);							//拷贝构造函数
	List(char A[], int n);						//数组构造函数
	~List();									//析构函数
	
	//获取链表成员变量
	int length()const;							//求长度
	Node* get_head() { return head; }			//读取链表表头指针
	Node* get_rear() { return rear; }			//读取链表表尾指针
	
	//操作元素
	bool get_element(const int i, char& x)const;//按序号取元素
	Node* locate(const char x)const;			//搜索元素
	bool insert(const int i, const char x);		//插入元素(第i个之前，原本的第i个元素变成第i+1个)
	bool delete_end();							//删除尾元素
	bool append(const char x);					//尾增
	
	//操作链表
	void copy(List A);							//A链表复制到B链表
	bool isequal(List A);						//判断链表是否相等
private:
	int count;
	Node* head;
	Node* rear;
};

