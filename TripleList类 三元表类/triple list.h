#pragma once
#include<iostream>
using namespace std;
const int MAX = 5;

struct Tuple
{
	int ti;		//��
	int tj;		//��
	int data;	//ֵ
	Tuple* next;
};

class TripleList
{
public:
	TripleList();						//Ĭ�Ϲ��캯��
	TripleList(int A[][MAX]);			//��Ԫ���캯��
	TripleList(TripleList& tl);			//��Ԫ��������
	TripleList(const TripleList& tl);	//��Ԫ��������
	~TripleList();						//��������

	int get_length() const;				//��ȡ����
	Tuple* get_front() const;			//���ͷ���
	Tuple* get_rear() const;			//���β���

	void append(Tuple* t);				//β��
	void print() const;					//��ӡ��Ԫ��
	TripleList& operator= (const TripleList& tl);	//�Ⱥ����������
	TripleList& operator+ (const TripleList& tl);			//�Ӻ����������

private:
	int count;
	Tuple *front,*rear;					//ͷ���δʵ������β������һ��Ԫ��ΪNULL
};









