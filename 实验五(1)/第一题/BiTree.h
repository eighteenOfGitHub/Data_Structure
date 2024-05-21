#ifndef BINARYTREE_H
#define BINARYTREE_H
#pragma once
#include<iostream>
#include"Stack.hpp"
using namespace std;

struct BiTreeNode
{
	char data;
	BiTreeNode* lChild, * rChild;
	BiTreeNode();
	BiTreeNode(char data);
};

class BiTree
{
public:
	BiTree();							//Ĭ�Ϲ��캯��
	BiTree(const char* str);			//������캯���ӿ�
	BiTree(BiTree& tree);			//�������캯��
	~BiTree();							//��������

	void preOrderTarverse() const;				//�����������ӿ�
	void inOrderTarverse() const;				//�����������ӿ�
	void postOrderTarverse() const;				//�����������ӿ�
	BiTreeNode* get_root() { return root; }			//��ø����ָ��
	int get_count()const { return count; }		//��ý����

private:
	void _createTree(BiTreeNode*& node, const char* str);	//������캯��ʵ��
	void _preOrderTarverse(BiTreeNode* node, int depth) const;		//����������ʵ��
	void _inOrderTarverse(BiTreeNode* node, int depth) const;		//����������ʵ��
	void _postOrderTarverse(BiTreeNode* node, int depth) const;		//����������ʵ��
	void destroyTree(BiTreeNode* node);					//ɾ�����ʵ��
	BiTreeNode* Copy(BiTreeNode* node);					//���ƽ��ʵ��
private:
	BiTreeNode* root;					//���ڵ����ָ����
	int count;
};
#endif // !BINARYTREE_H
