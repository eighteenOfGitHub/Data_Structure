#include "pch.h"
#include<iostream>
#include "Sudoku.h"
#include <time.h>

Sudoku::Sudoku() {
	clear();
}

//--------------------Suduku主要接口--------------------

void Sudoku::practice(int option) {

	//抽题并得到答案
	getGame();

	//设置游戏当前状态，挖空
	int curGame[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			curGame[i][j] = myGame[i][j];
		}
	}
	int brank = 0;//挖去的空白格子数
	if (option == 0) {
	}
	else if (option == 1) {
		brank = 25;//25
	}
	else if (option == 2) {
		brank = 40;//40
	}
	else {
		brank = 55;//55
	}

	for (int i = 1; i <= brank; i++) {
		int x = rand() % 9;
		int y = rand() % 9;
		while (curGame[x][y] == 0) {
			x = rand() % 9;
			y = rand() % 9;
		}
		curGame[x][y] = 0;
	}

	//开始游戏
	beginGame(curGame, option);
}


void Sudoku::beginGame(int curGame[9][9], int option) {
	Stack<MyRemove> myremove;
	clock_t start_time = clock();
	while (1) {
		output(curGame);
		cout << "1.输入\n"
			<< "2.检查\n"
			<< "3.撤销\n"
			<< "4.提示\n"
			<< "5.查看答案\n"
			<< "6.返回上级\n"
			<< "请选择功能：";
		char option;
		cin >> option;
		while (option < '1' || option > '6') {
			cout << "输入有误！请重新选择选项：";
			cin >> option;
		}
		if (option == '6') {
			break;
		}
		switch (option) {
		case '1': {
			int x, y, value;
		reInput:
			cout << "请输入横坐标、纵坐标、数字：";
			cin >> x >> y >> value;
			if (x > 9 || y > 9 || value > 9 || x < 1 || y < 1 || value < 1) {
				cout << "数值错误！请重新输入！" << endl;
				goto reInput;
			}
			if (curGame[x - 1][y - 1] != 0) {
				cout << "该点已存在！请重新输入！" << endl;
				goto reInput;
			}
			if (!check((x - 1) * 9 + (y - 1), value, curGame)) {
				cout << "该数字已存在，不可填入！请重新输入！" << endl;
				goto reInput;
			}

			//保存数据
			curGame[x - 1][y - 1] = value;
			//步骤入栈
			MyRemove remove(x - 1, y - 1, value);
			myremove.push(remove);
			cout << "输入成功！" << endl;
			break;
		}

		case '2': {
			bool haveWrong = 0;
			bool iscomplete = 1;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (curGame[i][j] != 0) {
						if (curGame[i][j] != myGame[i][j]) {
							cout << "第 " << i + 1 << " 行，第 " << j + 1 << " 列 数字错误！" << endl;
							haveWrong = 1;
						}
					}
					else {
						haveWrong = 1;
						iscomplete = 0;
					}
				}
			}
			if (iscomplete && !haveWrong) {
				clock_t end_time = clock();
				cout << "恭喜你！挑战成功！" << endl;
				int time = (end_time - start_time) / 1000;
				if (option == 2 && time < 600) {
					cout << "你的成绩为 A " << endl;
				}
				else if ((option == 2 && time >= 600 && time < 1800) || (option == 1 && time < 600)) {
					cout << "你的成绩为 B " << endl;
				}
				else if ((option == 2 && time >= 1800 && time < 3600) || (option == 1 && time >= 600 && time < 1800)) {
					cout << "你的成绩为 C " << endl;
				}
				else if ((option == 2 && time >= 3600) || (option == 1 && time >= 1800 && time < 3600)) {
					cout << "你的成绩为 D " << endl;
				}
				else {//(option == 1 && time >= 3600)
					cout << "你的成绩为 E " << endl;
				}
				system("pause");
				return;
			}
			else if (!iscomplete && !haveWrong) {
				cout << "不错哟！暂时没有错误！" << endl;
			}
			break;
		}
		case '3': {
			if (myremove.empty()) {
				cout << "撤销失败！请先输入数字！" << endl;
			}
			else {
				MyRemove remove;
				myremove.get_top(remove);
				curGame[remove.x][remove.y] = 0;
				myremove.pop();
				cout << "撤销成功！" << endl;
			}
			break;
		}
		case '4': {
			srand((unsigned)time(NULL));
			int n = rand() % 81;
			while (curGame[n / 9][n % 9] != 0) {
				n = rand() % 81;
			}
			cout << "第 " << n / 9 + 1 << " 行，第 " << n % 9 + 1 << " 列 数字为：" << myGame[n / 9][n % 9] << endl;
			break;
		}
		case '5': {
			system("cls");
			output(myGame);
			break;
		}
		default: {
			cout << "输入有误！请重新输入！" << endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}
}

//--------------------Suduku功能实现--------------------

// 处理输入 
void Sudoku::input() {
	char t;
	cout << "输入棋盘，空用 0 表示\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> t;
			myGame[i][j] = t - '0';
		}
	}
}

// [n/9][n%9]
void Sudoku::getAnswer(int n) {

	// 成功 
	if (n > 80) {
		flag = true;
		return;
	}

	int x = n / 9, y = n % 9;
	// 有值 跳过 
	if (myGame[x][y]) {
		getAnswer(n + 1);
		return;
	}
	// 遍历 
	for (int i = 1; i <= 9; i++) {
		// 判断 
		if (check(n, i, myGame)) {
			// 判断成功 赋值 
			myGame[x][y] = i;
			getAnswer(n + 1);
			// 退出时判断是否完成  完成时退出 
			if (flag) {
				return;
			}
			// 未完成 重置棋盘 
			myGame[x][y] = 0;
		}
	}
}

void Sudoku::output(int game[9][9]) {
	int i, j, k, t;

	for (k = 0; k < 9; k++) {
		if (k % 3 == 0) {
			for (i = 0; i < 37; i++)
				cout << "-";
		}
		cout << endl;
		cout << "|";
		for (i = 0; i < 9; i++)
			if (game[k][i] != 0) {
				cout << " " << game[k][i] << "  ";
				if (i % 3 == 2) cout << "|";
			}
			else {
				cout << "    ";
				if (i % 3 == 2) cout << "|";
			}
		cout << "  " << k + 1 << endl;
	}
	for (i = 0; i < 37; i++)
		cout << "-";
	cout << endl;
	for (i = 0; i < 9; i++) {
		if (i != 0 && i % 3 == 0) cout << " ";
		cout << "  " << i + 1 << " ";
	}
	cout << endl;
}

void Sudoku::getGame() {

	while (!flag) {
		clear();
		srand((unsigned)time(NULL));
		for (int i = 0; i < 30; i++) {
			int n = rand() % 81;
			int value = rand() % 9 + 1;
			myGame[n / 9][n % 9] = value;
			while (!check(n, value, myGame)) {
				value = rand() % 9 + 1;
			}
			myGame[n / 9][n % 9] = value;
		}
		getAnswer(0);
	}
}

// 判断即将放入的 是否符合条件 
bool Sudoku::check(int n, int num, int game[9][9]) {

	// 行 
	for (int i = 0; i < 9; i++) {
		if (game[n / 9][i] == num) {
			return false;
		}
  	}

	// 列 
	for (int i = 0; i < 9; i++) {
		if (game[i][n % 9] == num) {
			return false;
		}
	}

	// 宫
	int x = n / 9 / 3 * 3;
	int y = n % 9 / 3 * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game[x + i][y + j] == num) {
				return false;
			}
		}
	}

	return true;
}

void Sudoku::clear() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			myGame[i][j] = 0;
		}
	}
	flag = false;
}