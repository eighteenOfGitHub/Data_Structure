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

class AvlTree	//��С�Ҵ�
{
public:
	//���캯��
	AvlTree();
	~AvlTree();

	AvlNode* binarySearchTree(int target);
	void Insert(int* x);			//����Ԫ�ض���ӿ�

private:
	//����Ԫ���ڲ�ʵ��
	void Insert(AvlNode*& t, int x);


	//��������ת��
	AvlNode* LLadjust(AvlNode* a);
	AvlNode* LRadjust(AvlNode* a);
	AvlNode* RLadjust(AvlNode* a);
	AvlNode* RRadjust(AvlNode* a);


	//����
	AvlNode* binarySearchTree(AvlNode* node, int target);


	//��ع���
	int GetHeight(AvlNode* t);			//�õ��߶�
	void Delete(AvlNode* t);			//ɾ���Դ˽��Ϊ������

private:
	AvlNode* root;
};

#include"AvlTree.h"
//----------------------------�����Ĺ��������---------------------------------------
AvlTree::AvlTree()
{
	root = NULL;
}
AvlTree::~AvlTree()
{
	Delete(root);
}

//----------------------------����---------------------------------------


AvlNode* AvlTree::binarySearchTree(AvlNode* node, int target) {
	if (node == nullptr) {
		return NULL;
	}
	if (node->data == target) {
		return node;
	}

	if (target < node->data) {
		return binarySearchTree(node->lchild, target);
	}
	else {
		return binarySearchTree(node->rchild, target);
	}
}


//----------------------------����---------------------------------------

AvlNode* AvlTree::binarySearchTree(int target){
	return binarySearchTree(root, target);
}

void AvlTree::Insert(int* x)
{
	for(int i= 0;i<10000;i++){
		Insert(root, *(x+i));
	}
	
}

void AvlTree::Insert(AvlNode*& t, int x)
{
	if (t == NULL)
	{
		t = new AvlNode(x);
		return;
	}
	else if (x < t->data)
	{
		Insert(t->lchild, x);
		if (GetHeight(t->lchild) - GetHeight(t->rchild) > 1)	//�������߶� �� �������߶� ��2
		{
			AvlNode* left = t->lchild;
			if (GetHeight(left->lchild) > GetHeight(left->rchild))	//LL��
			{
				t = LLadjust(t);
			}
			else													//LR��
			{
				t = LRadjust(t);
			}
		}
	}
	else if (x > t->data)
	{
		Insert(t->rchild, x);
		if (GetHeight(t->rchild) - GetHeight(t->lchild) > 1)	//�������߶� �� �������߶� ��2
		{
			AvlNode* right = t->rchild;
			if (GetHeight(right->lchild) > GetHeight(right->rchild))	//RL��
			{
				t = RLadjust(t);
			}
			else														//RR��
			{
				t = RRadjust(t);
			}
		}
	}
}

//----------------------------λ�õ���---------------------------------------

AvlNode* AvlTree::LLadjust(AvlNode* a)
{
	AvlNode* b = a->lchild;
	a->lchild = b->rchild;
	b->rchild = a;
	return b;
}
AvlNode* AvlTree::LRadjust(AvlNode* a)
{
	AvlNode* c = a->lchild->rchild;
	AvlNode* b = a->lchild;
	b->rchild = c->lchild;
	a->lchild = c->rchild;
	c->lchild = b;
	c->rchild = a;
	return c;
}
AvlNode* AvlTree::RLadjust(AvlNode* a)
{
	AvlNode* c = a->rchild->lchild;
	AvlNode* b = a->rchild;
	b->lchild = c->rchild;
	a->rchild = c->lchild;
	c->lchild = a;
	c->rchild = b;
	return c;
}
AvlNode* AvlTree::RRadjust(AvlNode* a)
{
	AvlNode* b = a->rchild;
	a->rchild = b->lchild;
	b->lchild = a;
	return b;

}
//----------------------------���߰�---------------------------------------
int max(const int n, const int m)
{
	return (m > n) ? m : n;
}

//----------------------------��ع���---------------------------------------

int AvlTree::GetHeight(AvlNode* t)
{
	if (t == NULL)return 0;
	return max(GetHeight(t->lchild), GetHeight(t->rchild)) + 1;
}

void AvlTree::Delete(AvlNode* t)
{
	if (t == NULL)return;
	Delete(t->lchild);
	Delete(t->rchild);
	delete t;
}


//class BinaryTreeSearch {//����������
//public:
//    struct TreeNode {
//        int data;
//        TreeNode* left;
//        TreeNode* right; 
//
//        TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
//    };
//
//public:
//    static TreeNode* binarySearchTree(TreeNode* root, int target) {
//        if (root == nullptr || root->data == target) {
//            return root;
//        }
//
//        if (target < root->data) {
//            return binarySearchTree(root->left, target);
//        }
//        else {
//            return binarySearchTree(root->right, target);
//        }
//    }
//};