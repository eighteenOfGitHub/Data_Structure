#include"List.h"

int main()
{
	int A[18] = { 1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,8,9};
	List list(A, 18);
	int n_move = list.delete_repetitive_element();
	cout << "ԭ����Ϊ��1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,8,9" << endl;
	cout << "������Ϊ�� ";
	list.print();
	cout << "Ԫ���ƶ�����Ϊ��" << n_move << endl;

	return 0;
}