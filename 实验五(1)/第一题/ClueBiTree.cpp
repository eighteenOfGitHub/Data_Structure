#include"ClueBiTree.h"

//--------------------ClueBiTreeNode实现--------------------

ClueBiTreeNode::ClueBiTreeNode(char c){
	data = c;
	lTag = 0;
	rTag = 0;
	lChild = NULL;
	rChild = NULL;
}

//--------------------ClueBiTree实现--------------------
ClueBiTree::ClueBiTree() {
	root = NULL;
}

ClueBiTree::ClueBiTree(BiTree tree){
	create(root,tree.get_root());
}

ClueBiTreeNode* ClueBiTree::getRoot(){
	return root;
}

void ClueBiTree::create(ClueBiTreeNode*& cur, BiTreeNode* node) {
	if (node == NULL) {
		return;
	}
	cur = new ClueBiTreeNode(node->data);
	create(cur->lChild, node->lChild);
	create(cur->rChild, node->rChild);
}

void ClueBiTree::visit(ClueBiTreeNode* node)const {
	cout << node->data << "";
}

// 先序遍历/中序遍历/后序遍历
void ClueBiTree::preOrderTarverse() const
{
	_preOrderTarverse(root);
	cout << endl;
}
void ClueBiTree::inOrderTarverse() const
{
	_inOrderTarverse(root);
	cout << endl;
}
void ClueBiTree::postOrderTarverse() const
{
	_postOrderTarverse(root);
	cout << endl;
}
void ClueBiTree::_preOrderTarverse(ClueBiTreeNode* node) const
{
	if (node == NULL) { return; }
	visit(node);
	if (node->lTag == 0) {
		_preOrderTarverse(node->lChild);
	}
	if (node->rTag == 0) {
		_preOrderTarverse(node->rChild);
	}
}
void ClueBiTree::_inOrderTarverse(ClueBiTreeNode* node) const
{
	if (node == NULL) { return; }
	if (node->lTag == 0) {
		_inOrderTarverse(node->lChild);
	}
	visit(node);
	if (node->rTag == 0) {
		_inOrderTarverse(node->rChild);
	}
}
void ClueBiTree::_postOrderTarverse(ClueBiTreeNode* node) const
{
	if (node == NULL) { return; }
	if (node->lTag == 0) {
		_postOrderTarverse(node->lChild);
	}
	if (node->rTag == 0) {
		_postOrderTarverse(node->rChild);
	}
	visit(node);
}


// 先序遍历/中序遍历/后序遍历 线索化
void ClueBiTree::preOrderThread() {	//先序遍历线索化对外接口
	ClueBiTreeNode* curPre = NULL, * cur = root;
	_preOrderThread(curPre, cur);
}
void ClueBiTree::inOrderThread() {	//中序遍历线索化对外接口
	ClueBiTreeNode* curPre = NULL, * cur = root;
	_inOrderThread(curPre, cur);
}
void ClueBiTree::postOrderThread() {	//后序遍历线索化对外接口
	ClueBiTreeNode* curPre = NULL, * cur = root;
	_postOrderThread(curPre, cur);
}
void ClueBiTree::_preOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur) {	//先序遍历线索化对外接口
	if (cur == NULL) {
		return;  
	}
	if (cur->lChild == NULL) { //前驱结点
		cur->lChild = curPre;
		cur->lTag = 1;
	}
	if (curPre != NULL && curPre->rChild == NULL) {	//后继结点
		curPre->rChild = cur;
		curPre->rTag = 1;
	}
	curPre = cur;
	if (cur->lTag == 0) {
		_preOrderThread(curPre, cur->lChild);
	}
	if (cur->rTag == 0) {
		_preOrderThread(curPre, cur->rChild);
	}

}
void ClueBiTree::_inOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur) {		//中序遍历线索化对外接口
	if (cur == NULL) {
		return;
	}
	if (cur->lTag == 0) {
		_inOrderThread(curPre, cur->lChild);
	}
	if (cur->lChild == NULL) { //前驱结点
		cur->lChild = curPre;
		cur->lTag = 1;
	}
	if (curPre != NULL && curPre->rChild == NULL) {	//后继结点
		curPre->rChild = cur;
		curPre->rTag = 1;
	}
	curPre = cur;
	if (cur->rTag == 0) {
		_inOrderThread(curPre, cur->rChild);
	}
}
void ClueBiTree::_postOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur) {	//后序遍历线索化对外接口
	if (cur == NULL) {
		return;
	}
	if (cur->lTag == 0) {
		_postOrderThread(curPre, cur->lChild);
	}
	if (cur->rTag == 0) {
		_postOrderThread(curPre, cur->rChild);
	}
	if (cur->lChild == NULL) { //前驱结点
		cur->lChild = curPre;
		cur->lTag = 1;
	}
	if (curPre != NULL && curPre->rChild == NULL) {	//后继结点
		curPre->rChild = cur;
		curPre->rTag = 1;
	}
	curPre = cur;
}

//线索化 输出
void ClueBiTree::preOrderThreadTarverse() {	//先序线索化遍历输出
	ClueBiTreeNode* q = root;
	while (q) {
		while (q->lTag == 0) {
			cout << q->data;
			q = q->lChild;
		}
		while (q->rTag == 1) {
			cout << q->data;
			q = q->rChild;
		}
		cout << q->data;
		if (q->lTag == 0) {
			q = q->lChild;
		}
		else {
			q = q->rChild;
		}
	}
	cout << endl;
}
void ClueBiTree::inOrderThreadTarverse(){	//中序线索化遍历输出
	ClueBiTreeNode* q = root;
	while (q) {
		while (q->lTag == 0) {
			q = q->lChild;
		}
		cout << q->data;
		while (q->rTag == 1) {
			q = q->rChild;
			cout << q->data;
		}
		if (q->rTag == 0) {
			q = q->rChild;
		}
	}
	cout << endl;
}
void ClueBiTree::postOrderThreadTarverse() {	//后序线索化遍历输出
	//按照从左到右的后序遍历输出需要栈存储，为提高时空效率
	//规律观察发现，从左到右的后序遍历输出 是 从右向左的先序遍历输出的倒序
	ClueBiTreeNode* q = root;
	while (q) {
		while (q->rTag == 0) {
			cout << q->data;
			q = q->rChild;
		}
		while (q->lTag == 1) {
			cout << q->data;
			q = q->lChild;
			if (q == NULL)return;
		}
		cout << q->data;
		if (q->rTag == 0) {
			q = q->rChild;
		}
		else {
			q = q->lChild;
		}
	}
	cout << endl;
}