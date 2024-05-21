#pragma once
#include<iostream>
using namespace std;
enum GNodeType {HEAD = 0, VALUE = 1, SUB = 2};

struct GListNode
{
	GNodeType type;			//元素类型
	union					//数据域
	{
		char data;			//有效值
		GListNode* sublist;	//指向指标的指针
	};
	GListNode* next;		//下一个指针

	GListNode(GNodeType type = HEAD, char value = '\0') :type(type), next(NULL)
	{
		if (type == VALUE)
		{
			data = value;
		}
		else if (type == SUB)
		{
			sublist = NULL;
		}
	}
};

class GList
{
private:
	GListNode* _front;	//头结点指针
public:
	GList(const char* str) : _front(NULL)
	{
		_CreateGList(_front,str);	//根据指定序列创建广义表
	}
	~GList(){}			//析构函数
public:
	void Print();	//打印表 对外接口
	int Size();		//获取广义表中值结点数目 对外接口
	int Depth();	//获取广义表的最深层次数 对外接口
private:
	void _CreateGList(GListNode*& link, const char*& str);	//构造函数底层逻辑
	bool _IsValue(const char ch);							//判断指定字符是否为值结点所允许的类型 
	int _Size(GListNode* head);	//获取广义表中值结点数目 函数实现
	int _Depth(GListNode* head);	//获取广义表的最深层次数 函数实现
	void _Print(GListNode* link);	//打印表 函数实现
};
