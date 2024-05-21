#include"Tree.h"

void test()
{
	Tree tree("A(B(D(H,),E(I,)),C(F(J,K),G)#");
	cout << "ÏÈÐò±éÀú£º";
	tree.Preorder();
	cout << endl;
	char Array[100];
	for (int i = 0; i < 100; i++)
		Array[i] = '^';
	int maxindex = 1;
	tree.Get_MaxIndex(maxindex);
	tree.TurnToArray(Array);
	for (int i = 1; i <= maxindex; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
}

int main()
{
	test();
	return 0;
}