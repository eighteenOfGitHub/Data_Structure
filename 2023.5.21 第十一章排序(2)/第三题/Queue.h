#pragma once
#include<iostream>
using namespace std;

struct QNode{
	int data;
	QNode* next;
	QNode(){
		next = NULL;
	}
	QNode(int x){
		data = x;
		next = NULL;
	}
};

class Queue{
private:
	int _count;
	QNode* _head;
	QNode* _rear;
public:
	Queue();
	Queue(int A[],int n);
	Queue(Queue& queue);
	~Queue();

	bool Empty() const;					//�ӿ�
	int get_length() const;				//��ó���
	QNode* get_head() const;			//���ͷ���ָ��
	bool get_front(int& x)const;		//��ȡ��Ԫ��
	void append(const int x);			//���
	bool serve();						//����

private:
	void Destroy(QNode* node);			//ɾ���ý���Լ��Ժ�Ľ��
};

Queue::Queue(){
	_count = 0;
	_head = new QNode;
	_rear = _head;
}

Queue::Queue(int A[], int n) {
	_count = 0;
	_head = new QNode;
	_rear = _head;
	
	for (int i = 0; i < n; i++) {
		QNode* node = new QNode(A[i]);
		_rear->next = node;
		_rear = node;
	}

	_count = n;
}

Queue::Queue(Queue& queue){
	_count = queue.get_length();
	_head = new QNode;
	_rear = _head;

	for (QNode* cur = queue.get_head()->next; cur != NULL; cur = cur->next) {
		QNode* node = new QNode(cur->data);
		_rear->next = node;
		_rear = node;
	}
}

Queue::~Queue()
{
	Destroy(_head);
	_head = NULL;
	_rear = _head;
	_count = 0;
}

bool Queue::Empty() const {
	if (_count == 0)return true;
	else return false;
}

int Queue::get_length() const {
	return _count;
}

bool Queue::get_front(int& x)const {
	if (_head->next == NULL)return false;
	x = _head->next->data;
	return true;
}

QNode* Queue::get_head() const {
	return _head;
}

void Queue::append(const int x) {
	QNode* node = new QNode(x);
	_rear->next = node;
	_rear = node;
	_count++;
}

bool Queue::serve() {
	if (Empty())return false;
	QNode* temp = _head->next;
	_head->next = _head->next->next;
	delete temp;
	_count--;
	if (Empty())_rear = _head;
	return true;
}

void Queue::Destroy(QNode* node) {
	if (node == NULL) return;
	Destroy(node->next);
	delete node;
}
