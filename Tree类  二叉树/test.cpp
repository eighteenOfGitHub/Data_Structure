#include"Tree.h"

void test()
{
	Tree tree2("A(B(D,E(G,)),C(,F))#");
	tree2.Preorder();
}

int main()
{
	test();
	return 0;
}