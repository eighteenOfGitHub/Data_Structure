#pragma once
#ifndef BTREE_H
#define BTREE_H

#include<iostream>
using namespace std;

struct BTNode	//����B-�����
{
	bool isleaf;		//�Ƿ�ΪҶ�ӽ�� True Ϊ�ǣ�FALSEΪ��

	int count;			//��ǰԪ������
	int data[3];		//Ԫ��

	BTNode* parent;		//���ڵ�
	BTNode* child[4];	//���ӽ������
	
	BTNode();
	BTNode(int x);
	void Insert(int x);	//Ҷ�ӽ��Ԫ�ز���
};

class BTree
{
private:
	BTNode* root;
public:
	BTree();
	~BTree();
	void Insert(int x);				//����Ԫ�ض���ӿ�
private:
	void Insert(BTNode* t, int x);	//����Ԫ���ڲ�ʵ��
	void Destroy(BTNode* t);
};

#endif // !BTREE_H
