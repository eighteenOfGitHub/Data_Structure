#pragma once
#include<iostream>
using namespace std;
const int MAX = 5;

struct Tuple
{
	int ti;		//行
	int tj;		//列
	int data;	//值
	Tuple* next;
};

class TripleList
{
public:
	TripleList();						//默认构造函数
	TripleList(int A[][MAX]);			//三元表构造函数
	TripleList(TripleList& tl);			//三元表拷贝构造
	TripleList(const TripleList& tl);	//三元表拷贝构造
	~TripleList();						//析构函数

	int get_length() const;				//获取长度
	Tuple* get_front() const;			//获得头结点
	Tuple* get_rear() const;			//获得尾结点

	void append(Tuple* t);				//尾增
	void print() const;					//打印三元表
	TripleList& operator= (const TripleList& tl);	//等号运算符重载
	TripleList& operator+ (const TripleList& tl);			//加号运算符重载

private:
	int count;
	Tuple *front,*rear;					//头结点未实例化，尾结点的下一个元素为NULL
};









