//#include <iostream>
//#include <conio.h>
//#include <Windows.h>
//#include <stack>
//using namespace std;
//struct mymove {//记录每一步操作 
//	int x;
//	int y;
//	int digit;
//	mymove(int a, int b, int c) {
//		x = a, y = b, digit = c;//设置该步操作的位置和填的数 
//	}
//};
//class desktop {
//private:
//	clock_t c_start, c_end;
//	int sudoku[10][10];//当前数独内容 
//	stack <mymove> opback;//回溯操作历史 
//	int level;//当前难度 
//	int num[9];//每个难度中的题库数量
//	int puzzlebank[29][10][10]; //数独谜题 其中所有难度的数独题存在一起，第二个第三个下标存储谜题内容
//	int check() {//返回0表示正常，返回1表示完成数独，返回-1表示有错误 
//		int tool[9] = { 0,0,0,0,0,0,0,0,0 };//存储1~9数字存在的数量 
//		int flag = 1;
//		int i, j;
//		for (i = 0; i < 3; i++)//检查左上 
//			for (j = 0; j < 3; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//数独填错了 
//				return -1;
//			else if (tool[i] == 0)//数独未完成 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 0; i < 3; i++)//检查中上 
//			for (j = 3; j < 6; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//数独填错了 
//				return -1;
//			else if (tool[i] == 0)//数独未完成 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 0; i < 3; i++)//检查右上 
//			for (j = 6; j < 9; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//数独填错了 
//				return -1;
//			else if (tool[i] == 0)//数独未完成 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 3; i < 6; i++)//检查左中 
//			for (j = 0; j < 3; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//数独填错了 
//				return -1;
//			else if (tool[i] == 0)//数独未完成 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 3; i < 6; i++)//检查中间 
//			for (j = 3; j < 6; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//数独填错了 
//				return -1;
//			else if (tool[i] == 0)//数独未完成 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 3; i < 6; i++)//检查右中 
//			for (j = 6; j < 9; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//数独填错了 
//				return -1;
//			else if (tool[i] == 0)//数独未完成 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 6; i < 9; i++)//检查左下 
//			for (j = 0; j < 3; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//数独填错了 
//				return -1;
//			else if (tool[i] == 0)//数独未完成 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 6; i < 9; i++)//检查中下 
//			for (j = 3; j < 6; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//数独填错了 
//				return -1;
//			else if (tool[i] == 0)//数独未完成 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 6; i < 9; i++)//检查右下 
//			for (j = 6; j < 9; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//数独填错了 
//				return -1;
//			else if (tool[i] == 0)//数独未完成 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//		//检索所有的3x3块	
//		int k;
//		for (i = 0; i < 9; i++) {
//			for (j = 0; j < 9; j++) {//检查行 
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//			for (j = 0; j < 9; j++)
//				if (tool[j] > 1)//数独填错了 
//					return -1;
//				else if (tool[j] == 0)//数独未完成 
//					flag = 0;
//			for (j = 0; j < 9; j++)//重新初始化 
//				tool[j] = 0;
//
//			for (j = 0; j < 9; j++) {//检查列 
//				int pos = sudoku[j][i] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//			for (j = 0; j < 9; j++)
//				if (tool[j] > 1)//数独填错了 
//					return -1;
//				else if (tool[j] == 0)//数独未完成 
//					flag = 0;
//			for (j = 0; j < 9; j++)//重新初始化 
//				tool[j] = 0;
//		}
//		return flag;
//	}
//	void show() {//打印当前数独迷阵 
//		int i, j, k, t;
//
//		for (k = 0; k < 9; k++) {
//			for (i = 0; i < 37; i++)
//				cout << "-";
//			cout << endl;
//			for (i = 0; i < 9; i++)
//				if (sudoku[k][i] != 0)
//					cout << "| " << sudoku[k][i] << " ";
//				else
//					cout << "|   ";
//			cout << "|  " << k + 1 << endl;
//		}
//		for (i = 0; i < 37; i++)
//			cout << "-";
//		cout << endl;
//		for (i = 0; i < 9; i++)
//			cout << "  " << i + 1 << " ";
//		cout << endl;
//	}
//	int getnumber() {
//		char c;
//		cin >> c;
//		while (1) {
//			if (c >= '1' && c <= '9')
//				return c - 48;
//			else {
//				cout << "请输入正确的数字！" << endl;
//				Sleep(2500);
//			}
//		}
//	}
//public:
//	desktop() {
//		int i, j;
//		for (i = 0; i < 9; i++)
//			for (j = 0; j < 9; j++)
//				sudoku[i][j] = 0;
//		level = 1;
//		num[0] = 1;//难度1的题的数量 
//		for (i = 1; i < 9; i++)
//			num[i] = 0;
//		int puzzletemp[10][10] = { {0,0,4,8,0,5,0,3,0},{5,2,8,0,0,0,0,0,4},
//		{0,0,0,4,7,0,0,0,2},{6,3,0,0,0,0,5,0,0},{0,0,5,1,9,0,0,4,0},{0,0,0,0,3,8,9,0,0},
//		{0,9,2,0,0,3,0,1,0},{0,0,0,0,5,7,4,0,3},{3,5,0,0,1,0,0,0,0} };
//		i = 0;
//		memcpy(&puzzlebank[num[i] - 1][0][0], &puzzletemp[0][0], sizeof(puzzletemp));//拷贝 
//	}
//	void Menu() {
//		cout << "    输入数字选择功能:  " << endl;
//		cout << "       1.开始数独      " << endl;
//		cout << "       2.选择难度      " << endl;
//		cout << "       3.退出游戏      " << endl;
//		cout << endl;
//	}
//	void choose() {
//		system("cls");
//		cout << "       当前难度为：" << level << endl;
//		cout << "      输入数字1~1选择难度：   " << endl;
//		cout << "  更多难度暂未开放，敬请期待！" << endl;
//		cout << endl;
//		char c;
//		c = _getch();
//		switch (c) {
//		case '1':
//			level = 1;
//			cout << "设置难度为难度1！" << endl;
//			Sleep(2500);
//			return;
//		default:
//			cout << "目前只有难度1！" << endl;
//			Sleep(3000);
//			break;
//		}
//	}
//	void startsudoku() {
//		cout << "抽取题目中……" << endl;
//		srand((unsigned)time(NULL));//srand()函数产生一个以当前时间开始的随机种子
//		int pos = rand() % num[level - 1];//抽到的对应难度的题号 
//		int i, j;
//		if (level > 0)
//			for (i = 0; i < level - 1; i++)
//				pos += num[i];
//		//寻找题库中的对应题目 
//		cout << "读取题目中……" << endl;
//		for (i = 0; i < 9; i++)
//			for (j = 0; j < 9; j++)
//				sudoku[i][j] = puzzlebank[pos][i][j];//读取题目 
//		while (opback.size() != 0)
//			opback.pop();//清空历史操作栈 
//		cout << "数独谜题载入完毕！" << endl;
//		system("pause");
//		c_start = clock();//开始计时 
//
//		while (1) {
//			system("cls");
//			show();
//			cout << "   请输入指令：  " << endl;
//			cout << "   1.填入数字    " << endl;
//			cout << "   2.撤销操作    " << endl;
//			cout << "   3.查看用时    " << endl;
//			char c;
//			c = _getch();
//
//			switch (c) {
//			case '1': {
//				fillin();
//				int temp = check();
//				if (temp == 1) {
//					system("cls");
//					show();
//					cout << "恭喜破解数独迷阵！" << endl;
//					c_end = clock();
//					cout << "总用时" << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
//					cout << "返回主界面。。。" << endl;
//					Sleep(1000);
//					cout << "5--" << endl;
//					Sleep(1000);
//					cout << "4--" << endl;
//					Sleep(1000);
//					cout << "3--" << endl;
//					Sleep(1000);
//					cout << "2--" << endl;
//					Sleep(1000);
//					cout << "1--" << endl;
//					return;
//				}
//				else if (temp == -1) {
//					cout << "警告：存在数字重复！" << endl;
//					Sleep(2000);
//				}
//				break;
//			}
//			case '2':
//				undo();
//				break;
//			case '3':
//				showtime();
//				break;
//			default:
//				cout << "请输入支持的操作！" << endl;
//				Sleep(2000);
//				break;
//			}
//		}
//	}
//	void fillin() {
//		int x, a, b;
//		cout << "请输入填入的数字:";
//		x = getnumber();
//		while (1) {
//			cout << "请输入填入的横坐标:";
//			b = getnumber() - 1;
//			cout << "请输入填入的纵坐标:";
//			a = getnumber() - 1; //数独坐标1~9转化为数组坐标0~8 
//			if (sudoku[a][b] == 0) {
//				sudoku[a][b] = x;
//				mymove temp(a, b, x);
//				opback.push(temp);//将操作压入栈 
//				return;
//			}
//			else {//这个位置有数 
//				cout << "请不要重复填数！" << endl;
//				Sleep(1500);
//				break;
//			}
//		}
//	}
//	void undo() {
//		if (opback.size() != 0) {
//			mymove temp = opback.top();//提取上一步操作
//			sudoku[temp.x][temp.y] = 0;
//			cout << "撤销成功！" << endl;
//			Sleep(1500);
//			return;
//		}
//		else {
//			cout << "当前没有操作可以撤销！" << endl;
//			Sleep(1500);
//		}
//		return;
//	}
//	void showtime() {
//		system("cls");
//		c_end = clock();
//		cout << "     当前用时为:     " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
//		Sleep(1500);
//		return;
//	}
//
//};
//int main() {
//char command;
//	desktop d1;
//	while (1) {
//		d1.Menu();
//		command = _getch();
//		switch (command) {
//		case '1':
//			d1.startsudoku();
//			break;
//		case '2':
//			d1.choose();
//			break;
//		case '3':
//			return 0;
//		default:
//			cout << "警告：错误指令！" << endl;
//			Sleep(3000);
//			break;
//		}
//		system("cls");
//	}
//}

//是否正确
//bool isSolved(vector<vector<char>>& board) {
//    r = vector<bitset<9>>(9, bitset<9>());
//    c = vector<bitset<9>>(9, bitset<9>());
//    cell = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));
//    for (int i = 0; i < board.size(); i++) {
//        for (int j = 0; j < board.size(); j++) {
//            if (board[i][j] == '.') {
//                continue;
//            }
//            int n = board[i][j] - '1';
//            if (r[i][n] || c[j][n] || cell[i / 3][j / 3][n]) return false;
//            r[i][n] = 1;
//            c[j][n] = 1;
//            cell[i / 3][j / 3][n] = 1;
//        }
//    }
//    return true;
//}
//};

////随机生成数独
//   /*creat 函数主要是实现了随机生成指定难度等级的数独盘面，并通过挖去部分数字来生成数独游戏。*/
//vector<vector<char>> creat(int type) {
//    vector<vector<char>> board(9, vector<char>(9, '.'));//表示初始化一个 9 行 9 列的二维数组，并将每个元素初始化为 '.'
//    //将当前时间的值作为随机数种子，让程序每次运行时都能获得一个随机序列。这样在后续程序中调用 rand 函数时将会生成不同的随机数序列。
//    srand(time(0));g
//    for (int i = 1; i < 10; i++) {
//        int x = rand() % 9;//rand() % 9 的结果为一个范围在 0 到 8 之间的整数，因此 x 的值也是 0 到 8 之间的一个随机整数。
//        int y = rand() % 9;
//        while (board[x][y] != '.') {//避免新生成的数字覆盖原有的数字。
//            x = rand() % 9;
//            y = rand() % 9;
//        }
//        board[x][y] = '0' + i;
//    }
    //this->solveSudoku(board);
//
//    int brank = 0;//挖去的空白格子数
//
//    //其输入参数 type 是一个整数，表示需要生成的数独难度等级
//
//    if (type == 0) {
//    }
//    else if (type == 1) {
//        brank = 25;//25
//    }
//    else if (type == 2) {
//        brank = 40;//40
//    }
//    else {
//        brank = 55;//55
//    }
//    /*循环挖去 brank 个空白格子，具体过程是在数独盘面中随机选取一个位置，并判断该位置是否已经为空，如果不为空则继续随机选取
//    直至找到一个非空位置；然后将该位置的数字置空，即用 '.' 来代替原来的数字。*/
//    for (int i = 1; i <= brank; i++) {
//        int x = rand() % 9;
//        int y = rand() % 9;
//        while (board[x][y] == '.') {
//            x = rand() % 9;
//            y = rand() % 9;
//        }
//        board[x][y] = '.';
//    }
//    return board;//最终返回一个挖去了部分数字的数独盘面。
//}