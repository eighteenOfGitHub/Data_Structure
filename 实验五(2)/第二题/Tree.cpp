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
	cout << "录入成功！" << endl;
}

void Tree::createByInput(){
	if (root != NULL) { destory(root); }
	cout << "设置根结点" << endl;
	setChild(root);
	cout << "输入成功！" << endl;
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
	TNode** tempptr = &T;	//用于保存第一个孩子结点，便于后面设置该孩子结点链的孩子结点
	//输入孩子结点链
	cout << "请输入第一个孩子结点（#作为结束）：";
	cin >> c;
	if (c == '#') { return; }
	T = new TNode(c);
	TNode* cur = T;
	cout << "请依次输入其他孩子结点（#作为结束）：";
	while (1) {
		cin >> c;
		if (c == '#') { break; }
		cur->nextBrother = new TNode(c);
		cur = cur->nextBrother;
	}
	//输入孩子结点链的各结点的孩子结点链
	TNode* temp = *tempptr;
	while (temp != NULL) {
		cout << "设置 " << temp->data << " 的孩子结点" << endl;
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


