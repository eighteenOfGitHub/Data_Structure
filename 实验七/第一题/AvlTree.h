#pragma once
#include<iostream>
using namespace std;

struct AvlNode
{
	int data;		//值域
	AvlNode* rchild, * lchild;
	AvlNode(int d)
	{
		data = d;
		rchild = NULL;
		lchild = NULL;
	}
};

class AvlTree	//左小右大
{
public:
	//构造函数
	AvlTree();
	~AvlTree();

	AvlNode* binarySearchTree(int target);
	void Insert(int* x);			//插入元素对外接口

private:
	//插入元素内部实现
	void Insert(AvlNode*& t, int x);


	//四种类型转化
	AvlNode* LLadjust(AvlNode* a);
	AvlNode* LRadjust(AvlNode* a);
	AvlNode* RLadjust(AvlNode* a);
	AvlNode* RRadjust(AvlNode* a);


	//查找
	AvlNode* binarySearchTree(AvlNode* node, int target);


	//相关功能
	int GetHeight(AvlNode* t);			//得到高度
	void Delete(AvlNode* t);			//删除以此结点为根的树

private:
	AvlNode* root;
};

#include"AvlTree.h"
//----------------------------函数的构造和析构---------------------------------------
AvlTree::AvlTree()
{
	root = NULL;
}
AvlTree::~AvlTree()
{
	Delete(root);
}

//----------------------------遍历---------------------------------------


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


//----------------------------插入---------------------------------------

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
		if (GetHeight(t->lchild) - GetHeight(t->rchild) > 1)	//左子树高度 比 右子树高度 大2
		{
			AvlNode* left = t->lchild;
			if (GetHeight(left->lchild) > GetHeight(left->rchild))	//LL型
			{
				t = LLadjust(t);
			}
			else													//LR型
			{
				t = LRadjust(t);
			}
		}
	}
	else if (x > t->data)
	{
		Insert(t->rchild, x);
		if (GetHeight(t->rchild) - GetHeight(t->lchild) > 1)	//右子树高度 比 左子树高度 大2
		{
			AvlNode* right = t->rchild;
			if (GetHeight(right->lchild) > GetHeight(right->rchild))	//RL型
			{
				t = RLadjust(t);
			}
			else														//RR型
			{
				t = RRadjust(t);
			}
		}
	}
}

//----------------------------位置调整---------------------------------------

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
//----------------------------工具包---------------------------------------
int max(const int n, const int m)
{
	return (m > n) ? m : n;
}

//----------------------------相关功能---------------------------------------

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


//class BinaryTreeSearch {//二叉树查找
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