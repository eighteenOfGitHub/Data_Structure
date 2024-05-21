#include"Stack.hpp"


int main()
{
	Stack<char> s1;
	Stack<char> s2;
	Stack<char> temp1;
	Stack<char> temp2;

	cout << "s1:";
	for (int i = 0; i < 6; i++)
	{
		s1.push(char('a' + i));
		cout << char('a' + i) << " ";
	}
	cout << endl;

	s2.push('a');
	s2.push('b');
	s2.push('c');
	s2.push('b');
	s2.push('a');
	cout << "s2: a b c  b a" << endl;

	cout << "temp1: ";
	node<char>* PA = s1.getptop();
	for (char a, int i = 0; i < s1.length(); i++, PA = PA->next)
	{
		a = PA->data;
		temp1.push(a);
		cout << a << " ";
	}
	cout << endl;

	if (s1.isequal(temp1))
		cout << "s1 is." << endl;
	else
		cout << "s1 isn't." << endl;

	cout << "temp2:";
	node<char>* PB = s2.getptop();
	for (char a, int i = 0; i < s2.length(); i++, PB = PB->next)
	{
		a = PB->data;
		temp2.push(a);
		cout << a << " ";
	}
	cout << endl;

	if (s2.isequal(temp2))
		cout << "s2 is." << endl;
	else
		cout << "s2 isn't." << endl;

	return 0;
}




