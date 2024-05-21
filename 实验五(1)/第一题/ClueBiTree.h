#pragma once
#ifndef CLUEBITREE_H
#define CLUEBITREE_H
#include<iostream>
#include"BiTree.h"
using namespace std;

struct ClueBiTreeNode {
	char data;
	ClueBiTreeNode* lChild, * rChild;
	int lTag, rTag;		//0 Ϊ�ӽ�㣬1 Ϊǰ��̽��
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
	void preOrderTarverse() const;				//�����������ӿ�
	void inOrderTarverse() const;				//�����������ӿ�
	void postOrderTarverse() const;				//�����������ӿ�

	void preOrderThread();	//�����������������ӿ�
	void inOrderThread();	//�����������������ӿ�
	void postOrderThread();	//�����������������ӿ�

	void preOrderThreadTarverse();	//�����������������
	void inOrderThreadTarverse();	//�����������������
	void postOrderThreadTarverse();	//�����������������
private:
	void create(ClueBiTreeNode*& cur,BiTreeNode* node);
	void visit(ClueBiTreeNode* node)const;
	void _preOrderTarverse(ClueBiTreeNode* node) const;		//����������ʵ��
	void _inOrderTarverse(ClueBiTreeNode* node) const;		//����������ʵ��
	void _postOrderTarverse(ClueBiTreeNode* node) const;	//����������ʵ��

	void _preOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur);	//��������������ڲ�ʵ��
	void _inOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur);		//��������������ڲ�ʵ��
	void _postOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur);	//��������������ڲ�ʵ��
};

#endif // !CLUEBITREE_H
