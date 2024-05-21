#pragma once
#include<iostream>
using namespace std;

struct AvlNode
{
	int data;		//ֵ��
	AvlNode* rchild, * lchild;
	AvlNode(int d)
	{
		data = d;
		rchild = NULL;
		lchild = NULL; 
	}
};

class AvlTree
{
public:
	//���캯��
	AvlTree();
	~AvlTree();

	void Insert(int x);			//����Ԫ�ض���ӿ�

	void PreorderTraversal();	//�����������ӿ�
	void InorderTraversal();	//�����������ӿ�

private:
	//����Ԫ���ڲ�ʵ��
	void Insert(AvlNode* &t, int x);


	//��������ת��
	AvlNode* LLadjust(AvlNode* a);
	AvlNode* LRadjust(AvlNode* a);
	AvlNode* RLadjust(AvlNode* a);
	AvlNode* RRadjust(AvlNode* a);

	//����
	void PreorderTraversal(AvlNode* t); //ǰ�����
	void InorderTraversal(AvlNode* t);	//�������

	//��ع���
	int GetHeight(AvlNode* t);			//�õ��߶�
	void Delete(AvlNode* t);			//ɾ���Դ˽��Ϊ������

private:
	AvlNode* root;
};