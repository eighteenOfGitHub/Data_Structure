#include"Generalized List.h"

void Test()
{
	GList genList("(a,b,(c,d),(e,(f),h))");
	genList.Print();
	cout << endl;
	cout << "Size is :" << genList.Size() << endl;
	cout << "Depth is :" << genList.Depth() << endl << endl;
}

int main()
{
	Test();
	return 0;
}