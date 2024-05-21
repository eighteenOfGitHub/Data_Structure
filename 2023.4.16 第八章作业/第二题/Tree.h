#pragma once
#ifndef TREE_H
#define TREE_H

#include<iostream>
#include"Stack.hpp"
#include"Linked List.h"
using namespace std;

//---------------------------Tree��----------------------------
struct TreeNode
{
	char data;
	TreeNode* lchild, * rchild;
};

class Tree
{
public:
	Tree();							//Ĭ�Ϲ��캯��
	Tree(const char* str);			//������캯���ӿ�
	Tree(Tree& tree);				//�������캯��
	~Tree();						//��������

	TreeNode* Get_root() { return root; }	//��ø����ָ��
	int Get_count()const { return count; }	//��ý����

	void Preorder() const;					//�����������ӿ�
	void Get_MaxIndex(int& max);			//��ö�����ת˳��������Žӿ�
	void TurnToArray(char array[]);			//������ת˳���ӿ�

private:	
	void CreateTree(TreeNode*& node, const char* str);			//������캯��ʵ��
	void Preorder(TreeNode* node) const;						//����������ʵ��
	void DestroyTree(TreeNode* node);							//ɾ�����ʵ��
	TreeNode* Copy(TreeNode* node);								//���ƽ��ʵ��

	void Get_MaxIndex(TreeNode* node, int& max, int cur);		//��ö�����ת˳���������ʵ��
	void TurnToArray(TreeNode* node, char array[],int index);	//������ת˳���ʵ��

private:
	TreeNode* root;					//���ڵ����ָ����
	int count;
};
#endif // !TREE_H