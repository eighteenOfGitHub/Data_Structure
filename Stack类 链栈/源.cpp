
#include"Stack.hpp"

int main()
{
	Stack<int> a;
	if (a.empty())
		cout << " a is empty" << endl;

	int number;
	a.push(1);
	a.get_top(number);
	cout << " top of a is: " << number << endl;
	a.push(2);
	a.get_top(number);
	cout << " top of a is: " << number << endl;
	a.pop();
	a.get_top(number);
	cout << " top of a is: " << number << endl;



	return 0;
}