#pragma once
#include<iostream>
#include<fstream>
using namespace std;

struct TNode{
	char data;
	TNode* firstChild;
	TNode* nextBrother;
	TNode(char c);
};

class Tree {
private:
	TNode* root;	//为第一棵树的根结点
public:
	Tree() { root = NULL; }
	~Tree();

	void createByFile();
	void createByInput();
	void saveByFile();
	bool preOrder();
	bool postOrder();

	TNode* getRoot() { return root; }
private:
	void visit(TNode* T);
	void destory(TNode* T);
	void preOrder(TNode* T);
	void postOrder(TNode* T);
	void setChild(TNode*& T);
	void createByFile(ifstream& ifs,TNode*& T);
	void saveByFile(ofstream& ofs,TNode* T);
};