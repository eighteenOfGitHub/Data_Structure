#include"Sudoku.h"
using namespace std;

void showmenu() {
	cout << "--------------------\n"
		<< "------数独游戏------\n"
		<< "--------------------\n"
		<< "1.求解模式\n"
		<< "2.练习模式\n"
		<< "3.退出\n"
		<< "请选择模式：";
}

int main() {
	Suduku suduku;
	while (1) {
		showmenu();
		char option;
		cin >> option;
		switch (option) {
		case '1': {
			system("cls");
			suduku.solveByInput();
			break;
		}

		case '2': {
			system("cls");
			cout << "1.简单\n"
				<< "2.中等\n"
				<< "3.困难\n"
				<< "请选择难度：";
			char option;
			cin >> option;
			while (option != '1' && option != '2' && option != '3') {
				cout << "输入有误！请重新选择难度：";
				cin >> option;
			}
			system("cls");
			suduku.practice(option - '1' + 1);
			break;
		}
		case '3': {
			system("pause");
			return 0;
		}
		default: {
			cout << "输入有误！请重新输入！" << endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}

	return 0;
}


/*

测试用例

1 7 0 0 0 4 0 0 0
3 6 0 8 1 0 0 5 4
0 0 8 0 5 0 1 0 9 
0 0 7 0 3 5 0 4 8
0 0 0 0 0 0 2 7 0
0 0 0 0 0 8 6 0 1
0 0 0 0 6 0 0 8 0
7 0 0 0 0 0 0 0 0
0 0 0 4 0 3 0 1 6

0 9 0 4 8 1 7 6 3
4 1 3 7 0 2 9 0 5
8 6 0 3 5 9 0 1 2
6 2 4 1 9 5 3 7 8
7 0 9 0 4 3 1 2 6
1 3 8 6 0 7 0 9 4
2 7 0 5 3 8 6 0 9
3 8 6 9 0 4 2 5 7
0 4 5 2 7 6 0 3 0
*/