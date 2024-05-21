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
	Tuple() {}
	Tuple(int i, int j, int data) {
		ti = i;
		tj = j;
		this->data = data;
		next = NULL;
	}
	Tuple(Tuple* tuple) {
		ti = tuple->ti;
		tj = tuple->tj;
		this->data = tuple->data;
		next = NULL;
	}
};

class TripleList
{
public:
	TripleList();						//Ĭ�Ϲ��캯��
	TripleList(int A[][MAX]);			//��Ԫ���캯��
	TripleList(TripleList& tl);			//��Ԫ��������
	TripleList(const TripleList& tl);	//��Ԫ��������
	~TripleList();						//��������

	int get_length() const;					//��ȡ����
	Tuple* get_front() const;				//���ͷ���
	Tuple* get_rear() const;				//���β���
	int getValue(int i,int j) const;		//��þ����ӦԪ�ص�ֵ

	void append(Tuple* t);				//β��
	void insert(Tuple* t);				//���� ���������i��j ȷ��Key��ͬ
	void print() const;					//��ӡ��Ԫ��
	TripleList& operator= (const TripleList& tl);	//�Ⱥ����������
	TripleList& operator+ (const TripleList& tl);	//�Ӻ����������
	TripleList& operator* (const TripleList& tl);	//�˺����������

private:
	int count;
	Tuple *front,*rear;					//ͷ���δʵ������β������һ��Ԫ��ΪNULL
};