#include"ClueBiTree.h"

//--------------------ClueBiTreeNodeʵ��--------------------

ClueBiTreeNode::ClueBiTreeNode(char c){
	data = c;
	lTag = 0;
	rTag = 0;
	lChild = NULL;
	rChild = NULL;
}

//--------------------ClueBiTreeʵ��--------------------
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

// �������/�������/�������
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


// �������/�������/������� ������
void ClueBiTree::preOrderThread() {	//�����������������ӿ�
	ClueBiTreeNode* curPre = NULL, * cur = root;
	_preOrderThread(curPre, cur);
}
void ClueBiTree::inOrderThread() {	//�����������������ӿ�
	ClueBiTreeNode* curPre = NULL, * cur = root;
	_inOrderThread(curPre, cur);
}
void ClueBiTree::postOrderThread() {	//�����������������ӿ�
	ClueBiTreeNode* curPre = NULL, * cur = root;
	_postOrderThread(curPre, cur);
}
void ClueBiTree::_preOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur) {	//�����������������ӿ�
	if (cur == NULL) {
		return;  
	}
	if (cur->lChild == NULL) { //ǰ�����
		cur->lChild = curPre;
		cur->lTag = 1;
	}
	if (curPre != NULL && curPre->rChild == NULL) {	//��̽��
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
void ClueBiTree::_inOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur) {		//�����������������ӿ�
	if (cur == NULL) {
		return;
	}
	if (cur->lTag == 0) {
		_inOrderThread(curPre, cur->lChild);
	}
	if (cur->lChild == NULL) { //ǰ�����
		cur->lChild = curPre;
		cur->lTag = 1;
	}
	if (curPre != NULL && curPre->rChild == NULL) {	//��̽��
		curPre->rChild = cur;
		curPre->rTag = 1;
	}
	curPre = cur;
	if (cur->rTag == 0) {
		_inOrderThread(curPre, cur->rChild);
	}
}
void ClueBiTree::_postOrderThread(ClueBiTreeNode*& curPre, ClueBiTreeNode*& cur) {	//�����������������ӿ�
	if (cur == NULL) {
		return;
	}
	if (cur->lTag == 0) {
		_postOrderThread(curPre, cur->lChild);
	}
	if (cur->rTag == 0) {
		_postOrderThread(curPre, cur->rChild);
	}
	if (cur->lChild == NULL) { //ǰ�����
		cur->lChild = curPre;
		cur->lTag = 1;
	}
	if (curPre != NULL && curPre->rChild == NULL) {	//��̽��
		curPre->rChild = cur;
		curPre->rTag = 1;
	}
	curPre = cur;
}

//������ ���
void ClueBiTree::preOrderThreadTarverse() {	//�����������������
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
void ClueBiTree::inOrderThreadTarverse(){	//�����������������
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
void ClueBiTree::postOrderThreadTarverse() {	//�����������������
	//���մ����ҵĺ�����������Ҫջ�洢��Ϊ���ʱ��Ч��
	//���ɹ۲췢�֣������ҵĺ��������� �� ��������������������ĵ���
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