#include"Tree.h"

void showMenu() {
	cout << "--------------------\n"
		<< "功能菜单：\n"
		<< "1.指定输入构造森林\n"
		<< "2.读入文件构造森林\n"
		<< "3.先序遍历\n"
		<< "4.后序遍历\n"
		<< "5.保存数据\n"
		<< "6.退出\n"
		<< "--------------------" << endl;
}

int main(){
	char option;
	Tree tree;
	while (1) {
		showMenu();
		cout << "请选择功能：";
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
				cout << "错误！根结点为空！" << endl;
			}
			break;
		case '4':
			if (!tree.postOrder()) {
				cout << "错误！根结点为空！" << endl;
			}
			break;
		case '5':
			if (tree.getRoot() == NULL) {
				cout << "数据为空！保存失败！" << endl;
			}
			else {
				tree.saveByFile();
				cout << "保存成功！" << endl;
			}
			break;
		case '6':
			return 0;
			break;
		default:
			cout << "输入有误！请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}