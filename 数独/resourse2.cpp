//#include <iostream>
//#include <conio.h>
//#include <Windows.h>
//#include <stack>
//using namespace std;
//struct mymove {//��¼ÿһ������ 
//	int x;
//	int y;
//	int digit;
//	mymove(int a, int b, int c) {
//		x = a, y = b, digit = c;//���øò�������λ�ú������ 
//	}
//};
//class desktop {
//private:
//	clock_t c_start, c_end;
//	int sudoku[10][10];//��ǰ�������� 
//	stack <mymove> opback;//���ݲ�����ʷ 
//	int level;//��ǰ�Ѷ� 
//	int num[9];//ÿ���Ѷ��е��������
//	int puzzlebank[29][10][10]; //�������� ���������Ѷȵ����������һ�𣬵ڶ����������±�洢��������
//	int check() {//����0��ʾ����������1��ʾ�������������-1��ʾ�д��� 
//		int tool[9] = { 0,0,0,0,0,0,0,0,0 };//�洢1~9���ִ��ڵ����� 
//		int flag = 1;
//		int i, j;
//		for (i = 0; i < 3; i++)//������� 
//			for (j = 0; j < 3; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//��������� 
//				return -1;
//			else if (tool[i] == 0)//����δ��� 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 0; i < 3; i++)//������� 
//			for (j = 3; j < 6; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//��������� 
//				return -1;
//			else if (tool[i] == 0)//����δ��� 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 0; i < 3; i++)//������� 
//			for (j = 6; j < 9; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//��������� 
//				return -1;
//			else if (tool[i] == 0)//����δ��� 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 3; i < 6; i++)//������� 
//			for (j = 0; j < 3; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//��������� 
//				return -1;
//			else if (tool[i] == 0)//����δ��� 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 3; i < 6; i++)//����м� 
//			for (j = 3; j < 6; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//��������� 
//				return -1;
//			else if (tool[i] == 0)//����δ��� 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 3; i < 6; i++)//������� 
//			for (j = 6; j < 9; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//��������� 
//				return -1;
//			else if (tool[i] == 0)//����δ��� 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 6; i < 9; i++)//������� 
//			for (j = 0; j < 3; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//��������� 
//				return -1;
//			else if (tool[i] == 0)//����δ��� 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 6; i < 9; i++)//������� 
//			for (j = 3; j < 6; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//��������� 
//				return -1;
//			else if (tool[i] == 0)//����δ��� 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//
//		for (i = 6; i < 9; i++)//������� 
//			for (j = 6; j < 9; j++) {
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//		for (i = 0; i < 9; i++)
//			if (tool[i] > 1)//��������� 
//				return -1;
//			else if (tool[i] == 0)//����δ��� 
//				flag = 0;
//		for (i = 0; i < 9; i++)
//			tool[i] = 0;
//		//�������е�3x3��	
//		int k;
//		for (i = 0; i < 9; i++) {
//			for (j = 0; j < 9; j++) {//����� 
//				int pos = sudoku[i][j] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//			for (j = 0; j < 9; j++)
//				if (tool[j] > 1)//��������� 
//					return -1;
//				else if (tool[j] == 0)//����δ��� 
//					flag = 0;
//			for (j = 0; j < 9; j++)//���³�ʼ�� 
//				tool[j] = 0;
//
//			for (j = 0; j < 9; j++) {//����� 
//				int pos = sudoku[j][i] - 1;
//				if (pos >= 0)
//					tool[pos]++;
//			}
//			for (j = 0; j < 9; j++)
//				if (tool[j] > 1)//��������� 
//					return -1;
//				else if (tool[j] == 0)//����δ��� 
//					flag = 0;
//			for (j = 0; j < 9; j++)//���³�ʼ�� 
//				tool[j] = 0;
//		}
//		return flag;
//	}
//	void show() {//��ӡ��ǰ�������� 
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
//				cout << "��������ȷ�����֣�" << endl;
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
//		num[0] = 1;//�Ѷ�1��������� 
//		for (i = 1; i < 9; i++)
//			num[i] = 0;
//		int puzzletemp[10][10] = { {0,0,4,8,0,5,0,3,0},{5,2,8,0,0,0,0,0,4},
//		{0,0,0,4,7,0,0,0,2},{6,3,0,0,0,0,5,0,0},{0,0,5,1,9,0,0,4,0},{0,0,0,0,3,8,9,0,0},
//		{0,9,2,0,0,3,0,1,0},{0,0,0,0,5,7,4,0,3},{3,5,0,0,1,0,0,0,0} };
//		i = 0;
//		memcpy(&puzzlebank[num[i] - 1][0][0], &puzzletemp[0][0], sizeof(puzzletemp));//���� 
//	}
//	void Menu() {
//		cout << "    ��������ѡ����:  " << endl;
//		cout << "       1.��ʼ����      " << endl;
//		cout << "       2.ѡ���Ѷ�      " << endl;
//		cout << "       3.�˳���Ϸ      " << endl;
//		cout << endl;
//	}
//	void choose() {
//		system("cls");
//		cout << "       ��ǰ�Ѷ�Ϊ��" << level << endl;
//		cout << "      ��������1~1ѡ���Ѷȣ�   " << endl;
//		cout << "  �����Ѷ���δ���ţ������ڴ���" << endl;
//		cout << endl;
//		char c;
//		c = _getch();
//		switch (c) {
//		case '1':
//			level = 1;
//			cout << "�����Ѷ�Ϊ�Ѷ�1��" << endl;
//			Sleep(2500);
//			return;
//		default:
//			cout << "Ŀǰֻ���Ѷ�1��" << endl;
//			Sleep(3000);
//			break;
//		}
//	}
//	void startsudoku() {
//		cout << "��ȡ��Ŀ�С���" << endl;
//		srand((unsigned)time(NULL));//srand()��������һ���Ե�ǰʱ�俪ʼ���������
//		int pos = rand() % num[level - 1];//�鵽�Ķ�Ӧ�Ѷȵ���� 
//		int i, j;
//		if (level > 0)
//			for (i = 0; i < level - 1; i++)
//				pos += num[i];
//		//Ѱ������еĶ�Ӧ��Ŀ 
//		cout << "��ȡ��Ŀ�С���" << endl;
//		for (i = 0; i < 9; i++)
//			for (j = 0; j < 9; j++)
//				sudoku[i][j] = puzzlebank[pos][i][j];//��ȡ��Ŀ 
//		while (opback.size() != 0)
//			opback.pop();//�����ʷ����ջ 
//		cout << "��������������ϣ�" << endl;
//		system("pause");
//		c_start = clock();//��ʼ��ʱ 
//
//		while (1) {
//			system("cls");
//			show();
//			cout << "   ������ָ�  " << endl;
//			cout << "   1.��������    " << endl;
//			cout << "   2.��������    " << endl;
//			cout << "   3.�鿴��ʱ    " << endl;
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
//					cout << "��ϲ�ƽ���������" << endl;
//					c_end = clock();
//					cout << "����ʱ" << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
//					cout << "���������档����" << endl;
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
//					cout << "���棺���������ظ���" << endl;
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
//				cout << "������֧�ֵĲ�����" << endl;
//				Sleep(2000);
//				break;
//			}
//		}
//	}
//	void fillin() {
//		int x, a, b;
//		cout << "���������������:";
//		x = getnumber();
//		while (1) {
//			cout << "����������ĺ�����:";
//			b = getnumber() - 1;
//			cout << "�����������������:";
//			a = getnumber() - 1; //��������1~9ת��Ϊ��������0~8 
//			if (sudoku[a][b] == 0) {
//				sudoku[a][b] = x;
//				mymove temp(a, b, x);
//				opback.push(temp);//������ѹ��ջ 
//				return;
//			}
//			else {//���λ������ 
//				cout << "�벻Ҫ�ظ�������" << endl;
//				Sleep(1500);
//				break;
//			}
//		}
//	}
//	void undo() {
//		if (opback.size() != 0) {
//			mymove temp = opback.top();//��ȡ��һ������
//			sudoku[temp.x][temp.y] = 0;
//			cout << "�����ɹ���" << endl;
//			Sleep(1500);
//			return;
//		}
//		else {
//			cout << "��ǰû�в������Գ�����" << endl;
//			Sleep(1500);
//		}
//		return;
//	}
//	void showtime() {
//		system("cls");
//		c_end = clock();
//		cout << "     ��ǰ��ʱΪ:     " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
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
//			cout << "���棺����ָ�" << endl;
//			Sleep(3000);
//			break;
//		}
//		system("cls");
//	}
//}

//�Ƿ���ȷ
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

////�����������
//   /*creat ������Ҫ��ʵ�����������ָ���Ѷȵȼ����������棬��ͨ����ȥ��������������������Ϸ��*/
//vector<vector<char>> creat(int type) {
//    vector<vector<char>> board(9, vector<char>(9, '.'));//��ʾ��ʼ��һ�� 9 �� 9 �еĶ�ά���飬����ÿ��Ԫ�س�ʼ��Ϊ '.'
//    //����ǰʱ���ֵ��Ϊ��������ӣ��ó���ÿ������ʱ���ܻ��һ��������С������ں��������е��� rand ����ʱ�������ɲ�ͬ����������С�
//    srand(time(0));g
//    for (int i = 1; i < 10; i++) {
//        int x = rand() % 9;//rand() % 9 �Ľ��Ϊһ����Χ�� 0 �� 8 ֮������������ x ��ֵҲ�� 0 �� 8 ֮���һ�����������
//        int y = rand() % 9;
//        while (board[x][y] != '.') {//���������ɵ����ָ���ԭ�е����֡�
//            x = rand() % 9;
//            y = rand() % 9;
//        }
//        board[x][y] = '0' + i;
//    }
    //this->solveSudoku(board);
//
//    int brank = 0;//��ȥ�Ŀհ׸�����
//
//    //��������� type ��һ����������ʾ��Ҫ���ɵ������Ѷȵȼ�
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
//    /*ѭ����ȥ brank ���հ׸��ӣ�������������������������ѡȡһ��λ�ã����жϸ�λ���Ƿ��Ѿ�Ϊ�գ������Ϊ����������ѡȡ
//    ֱ���ҵ�һ���ǿ�λ�ã�Ȼ�󽫸�λ�õ������ÿգ����� '.' ������ԭ�������֡�*/
//    for (int i = 1; i <= brank; i++) {
//        int x = rand() % 9;
//        int y = rand() % 9;
//        while (board[x][y] == '.') {
//            x = rand() % 9;
//            y = rand() % 9;
//        }
//        board[x][y] = '.';
//    }
//    return board;//���շ���һ����ȥ�˲������ֵ��������档
//}