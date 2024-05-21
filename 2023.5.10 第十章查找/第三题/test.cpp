#include"BTree.h"

void test()
{
	BTree tree;
	int value;
	while (cin >> value)
	{
		if (value == -1)break;
		tree.Insert(value);
	}
}

int main()
{
	test();
	return 0;
}
