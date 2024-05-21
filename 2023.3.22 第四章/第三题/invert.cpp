#include"Linked List.hpp"

int main()
{
	List<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.append(i);
	}

	cout << "list : ";
	int x;
	for (int i = 0; i < 10; i++)
	{
		list.get_element(i + 1, x);
		cout << x << " ";
	}
	cout << endl;



	cout << "new list : ";
	int x;
	for (int i = 0; i < 10; i++)
	{
		list.get_element(i + 1, x);
		cout << x << " ";
	}
	cout << endl;

	return 0;
}