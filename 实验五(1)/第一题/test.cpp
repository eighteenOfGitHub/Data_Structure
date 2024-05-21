#include<iostream>
#include"BiTree.h"
#include"ClueBiTree.h"
using namespace std;

void test()
{
	BiTree tree("A(B(D,E),C(F,G))#");
	cout << "tree: A(B(D,E),C(F,G))" << endl;
	tree.inOrderTarverse();
	cout << "先序遍历线索化" << endl;

	ClueBiTree cluetree1(tree);
	cluetree1.preOrderTarverse();
	cluetree1.preOrderThread();
	cluetree1.preOrderThreadTarverse();

	cout << "中序遍历线索化" << endl;
	ClueBiTree cluetree2(tree);
	cluetree2.inOrderTarverse();
	cluetree2.inOrderThread();
	cluetree2.inOrderThreadTarverse();

	cout << "后序遍历线索化" << endl;
	ClueBiTree cluetree3(tree);
	cluetree3.postOrderTarverse();
	cluetree3.postOrderThread();
	cluetree3.postOrderThreadTarverse();
}

int main()
{
	test();
	return 0;
}