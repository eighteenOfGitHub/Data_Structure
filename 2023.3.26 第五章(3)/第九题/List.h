#pragma once

struct Node
{
	char data;
	Node* next;
};

class List	//������
{
public:
	//����
	List();										//Ĭ�Ϲ��캯��
	List(List& list);							//�������캯��
	List(char A[], int n);						//���鹹�캯��
	~List();									//��������
	
	//��ȡ�����Ա����
	int length()const;							//�󳤶�
	Node* get_head() { return head; }			//��ȡ�����ͷָ��
	Node* get_rear() { return rear; }			//��ȡ�����βָ��
	
	//����Ԫ��
	bool get_element(const int i, char& x)const;//�����ȡԪ��
	Node* locate(const char x)const;			//����Ԫ��
	bool insert(const int i, const char x);		//����Ԫ��(��i��֮ǰ��ԭ���ĵ�i��Ԫ�ر�ɵ�i+1��)
	bool delete_end();							//ɾ��βԪ��
	bool append(const char x);					//β��
	
	//��������
	void copy(List A);							//A�����Ƶ�B����
	bool isequal(List A);						//�ж������Ƿ����
private:
	int count;
	Node* head;
	Node* rear;
};

