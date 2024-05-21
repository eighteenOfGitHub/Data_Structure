#include"Tree.h"

void showMenu() {
	cout << "--------------------\n"
		<< "���ܲ˵���\n"
		<< "1.ָ�����빹��ɭ��\n"
		<< "2.�����ļ�����ɭ��\n"
		<< "3.�������\n"
		<< "4.�������\n"
		<< "5.��������\n"
		<< "6.�˳�\n"
		<< "--------------------" << endl;
}

int main(){
	char option;
	Tree tree;
	while (1) {
		showMenu();
		cout << "��ѡ���ܣ�";
		cin >> option;
		switch (option) {
		case '1':
			tree.createByInput();
			break;
		case '2':
			tree.createByFile();
			break;
		case '3':
			if (!tree.preOrder()) {
				cout << "���󣡸����Ϊ�գ�" << endl;
			}
			break;
		case '4':
			if (!tree.postOrder()) {
				cout << "���󣡸����Ϊ�գ�" << endl;
			}
			break;
		case '5':
			if (tree.getRoot() == NULL) {
				cout << "����Ϊ�գ�����ʧ�ܣ�" << endl;
			}
			else {
				tree.saveByFile();
				cout << "����ɹ���" << endl;
			}
			break;
		case '6':
			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}