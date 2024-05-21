#include<iostream>
using namespace std;

struct Link
{
	int data;
	Link* next;
};

void Print01(Link* L)
{
	if (L != NULL)
	{
		cout << L->data;
		Print01(L->next);
	}
}

void Print02(Link* L)
{
	if (L != NULL)
	{
		Print02(L->next);
		cout << L->data;
	}
}

int main()
{
	Link* head = new Link;
	head->next = NULL;

	Link* temp = head;
	for (int i = 1; i <= 5; i++)
	{
		Link* node = new Link;
		node->data = i;
		node->next = NULL;

		temp->next = node;
		temp = node;
	}
	
	Print01(head);
	cout << endl;
	Print02(head);
}