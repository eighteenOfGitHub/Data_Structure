#include "Tree.h"

TNode::TNode(char c) {
	data = c;
	firstChild = NULL;
	nextBrother = NULL;
}

Tree::~Tree(){
	destory(root);
	root = NULL;
}

void Tree::createByFile(){
	if (root != NULL) { destory(root); }
	ifstream ifs("MyTree.txt",ios_base::in);
	createByFile(ifs, root);
	ifs.close();
	cout << "¼��ɹ���" << endl;
}

void Tree::createByInput(){
	if (root != NULL) { destory(root); }
	cout << "���ø����" << endl;
	setChild(root);
	cout << "����ɹ���" << endl;
}

void Tree::saveByFile(){
	ofstream ofs("MyTree.txt", ios_base::out);
	saveByFile(ofs, root);
	ofs.close();
}

bool Tree::preOrder(){
	if (root == NULL) {
		return false;
	}
	preOrder(root);
	cout << endl;
	return true;
}

bool Tree::postOrder(){
	if (root == NULL) {
		return false;
	}
	postOrder(root);
	cout << endl;
	return true;
}

void Tree::visit(TNode* T){
	if (T == NULL) {
		cout << "# ";
	}
	else {
		cout << T->data << " ";
	}
}

void Tree::destory(TNode* T){
	if (T == NULL) {
		return;
	}
	destory(T->firstChild);
	destory(T->nextBrother);
	delete T;
	T = NULL;
}

void Tree::preOrder(TNode* T){
	if (T != NULL) {
		visit(T);
		preOrder(T->firstChild);
		preOrder(T->nextBrother);
	}
}

void Tree::postOrder(TNode* T){
	if (T != NULL) {
		postOrder(T->firstChild);
		visit(T);
		postOrder(T->nextBrother);
	}	
}

void Tree::setChild(TNode*& T){
	char c;
	TNode** tempptr = &T;	//���ڱ����һ�����ӽ�㣬���ں������øú��ӽ�����ĺ��ӽ��
	//���뺢�ӽ����
	cout << "�������һ�����ӽ�㣨#��Ϊ��������";
	cin >> c;
	if (c == '#') { return; }
	T = new TNode(c);
	TNode* cur = T;
	cout << "�����������������ӽ�㣨#��Ϊ��������";
	while (1) {
		cin >> c;
		if (c == '#') { break; }
		cur->nextBrother = new TNode(c);
		cur = cur->nextBrother;
	}
	//���뺢�ӽ�����ĸ����ĺ��ӽ����
	TNode* temp = *tempptr;
	while (temp != NULL) {
		cout << "���� " << temp->data << " �ĺ��ӽ��" << endl;
		setChild(temp->firstChild);
		temp = temp->nextBrother;
	}
}

void Tree::createByFile(ifstream& ifs, TNode*& T){
	char c;
	ifs >> c;
	if (c == '#') {
		return;
	}
	else {
		T = new TNode(c);
	}
	createByFile(ifs, T->firstChild);
	createByFile(ifs, T->nextBrother);
}

void Tree::saveByFile(ofstream& ofs, TNode* T){
	if (T == NULL) {
		ofs << '#' << " ";
		return;
	}
	ofs << T->data<<" ";
	saveByFile(ofs, T->firstChild);
	saveByFile(ofs, T->nextBrother);
}


