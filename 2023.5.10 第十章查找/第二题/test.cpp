#include"AvlTree.h"

void test()
{
	AvlTree tree;
	int value;
	while(cin>>value)
	{
		if (value == -1)break;
		tree.Insert(value);
		tree.PreorderTraversal();
		cout << endl;
		tree.InorderTraversal();
		cout << endl;
	}
	cout << "�������:" << endl;
	tree.PreorderTraversal();
	cout << endl;
	cout << "�������:" << endl;
	tree.InorderTraversal();
	cout << endl;
}

int main()
{
	test();
	return 0;
}