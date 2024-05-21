#pragma once
#include<iostream>
using namespace std;
enum GNodeType {HEAD = 0, VALUE = 1, SUB = 2};

struct GListNode
{
	GNodeType type;			//Ԫ������
	union					//������
	{
		char data;			//��Чֵ
		GListNode* sublist;	//ָ��ָ���ָ��
	};
	GListNode* next;		//��һ��ָ��

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
	GListNode* _front;	//ͷ���ָ��
public:
	GList(const char* str) : _front(NULL)
	{
		_CreateGList(_front,str);	//����ָ�����д��������
	}
	~GList(){}			//��������
public:
	void Print();	//��ӡ�� ����ӿ�
	int Size();		//��ȡ�������ֵ�����Ŀ ����ӿ�
	int Depth();	//��ȡ�������������� ����ӿ�
private:
	void _CreateGList(GListNode*& link, const char*& str);	//���캯���ײ��߼�
	bool _IsValue(const char ch);							//�ж�ָ���ַ��Ƿ�Ϊֵ�������������� 
	int _Size(GListNode* head);	//��ȡ�������ֵ�����Ŀ ����ʵ��
	int _Depth(GListNode* head);	//��ȡ�������������� ����ʵ��
	void _Print(GListNode* link);	//��ӡ�� ����ʵ��
};
