#include"Stack.hpp"

int main()
{
	Stack<int> S1(10);
	if (S1.empty())
		cout << "S1 is empty" << endl;
	S1.push(1);
	
	int x;
	S1.get_top(x);
	cout << "the top of S1 element is " << x << endl;

	Stack<int> S2(S1);
	if (!S2.full())
		cout << "S2 is not full" << endl;
	S2.push(2);
	
	S2.get_top(x);
	cout << "the top of S2 element is " << x << endl;

	S1 = S2;
	cout << "the top of S1 element is " << x << endl;

	return 0;
}