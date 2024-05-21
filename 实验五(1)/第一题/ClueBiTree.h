#pragma once
#ifndef CLUEBITREE_H
#define CLUEBITREE_H
#include<iostream>
#include"BiTree.h"
using namespace std;

struct ClueBiTreeNode {
	char data;
	ClueBiTreeNode* lChild, * rChild;
	int lTag, rTag;		//0 为子结点，1 为前后继结点
	ClueBiTreeNode() {}
	ClueBiTreeNode(char c);
};

class ClueBiTree {
private:
	ClueBiTreeNode* root;
public:
	ClueBiTree();
	ClueBiTree(BiTree tree);
	ClueBiTreeNode* getRoot();   
	void preOrderTarverse() const;				//先序遍历输出接口
	void inOrderTarverse() const;				//中序遍历输出接口
	void postOrderTarverse() const;				//后序遍历输出接口

	void preOrderThread();	//先序遍历线索化对外接口
	void inOrderThread();	//中序遍历线索化对外接口
	void postOrderThread();	//后序遍历线索化对外接口

	void preOrderThreadTarverse();	//先序线索化遍历输出
	void inOrderThreadTarverse();	//中序线索化遍历输出
	void postOrderThreadTarverse();	//后序线索化遍历输出
private:
	void create(ClueBiTreeNode*& cur,BiTreeNode* node);
	void visit(ClueBiTreeNode* node)const;
	void _preOrderTarverse(ClueBiTreeNode* node) const;		//先序遍历输出实现
	void _inOrderTarverse(ClueBiTreeNode* node) const;		//中序遍历输出实现
	void _postOrderTarverse(ClueBiTreeNode* node) const;	//后序遍历输出实现

	void _preOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur);	//先序遍历线索化内部实现
	void _inOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur);		//中序遍历线索化内部实现
	void _postOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur);	//后序遍历线索化内部实现
};

#endif // !CLUEBITREE_H
