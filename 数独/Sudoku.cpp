#include "Sudoku.h"
#include<iostream>
#include <time.h>

Suduku::Suduku() {};

//--------------------Suduku��Ҫ�ӿ�--------------------

void Suduku::solveByInput(){
	clear();
	input();
	cout << endl << endl;
	getAnswer(0);
	output(myGame);
}

void Suduku::practice(int option){

	//���Ⲣ�õ���
	getGame();


	//������Ϸ��ǰ״̬���ڿ�
	int curGame[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			curGame[i][j] = myGame[i][j];
		}
	}
	int brank = 0;//��ȥ�Ŀհ׸�����
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

	//��ʼ��Ϸ
	beginGame(curGame,option);
}


void Suduku::beginGame(int curGame[9][9],int option){
	Stack<MyRemove> myremove;
	time_t start_time = 0,end_time = 0;
	time(&start_time);
	while (1) {
		output(curGame);
		cout << "1.����\n"
			<< "2.���\n"
			<< "3.����\n"
			<< "4.��ʾ\n"
			<< "5.�鿴��\n"
			<< "6.�����ϼ�\n"
			<< "��ѡ���ܣ�";
		char option;
		cin >> option;
		while (option < '1' || option > '6') {
			cout << "��������������ѡ��ѡ�";
			cin >> option;
		}
		if (option == '6') {
			break;
		}
		switch (option) {
		case '1': {
			int x,y,value;
		reInput:
			cout << "����������ꡢ�����ꡢ���֣�";
			cin >> x >> y >> value;
			if (x > 9 || y > 9 || value > 9 || x < 1 || y < 1 || value < 1) {
				cout << "��ֵ�������������룡" << endl;
				goto reInput;
			}
			if (curGame[x-1][y-1] != 0) {
				cout << "�õ��Ѵ��ڣ����������룡" << endl;
				goto reInput;
			}
			if (!check((x - 1) * 9 + (y - 1), value, curGame)) {
				cout << "�������Ѵ��ڣ��������룡���������룡" << endl;
				goto reInput;
			}

			//��������
			curGame[x-1][y-1] = value;
			//������ջ
			MyRemove remove(x-1, y-1, value);
			myremove.push(remove);
			cout << "����ɹ���" << endl;
			break;
		}

		case '2': {
			bool haveWrong = 0;
			bool iscomplete = 1;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (curGame[i][j] != 0) {
						if (curGame[i][j] != myGame[i][j]) {
							cout << "�� " << i + 1 << " �У��� " << j + 1 << " �� ���ִ���" << endl;
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
				time(&end_time);
				cout << "��ϲ�㣡��ս�ɹ���" << endl;
				int time = (end_time - start_time) / 1000;
				if (option == 2 && time < 600) {
					cout << "��ĳɼ�Ϊ A " << endl;
				}
				else if ((option == 2 && time >= 600 && time < 1800)|| (option == 1 && time < 600)) {
					cout << "��ĳɼ�Ϊ B " << endl;
				}
				else if ((option == 2 && time >= 1800 && time < 3600) || (option == 1 && time >= 600 && time < 1800)) {
					cout << "��ĳɼ�Ϊ C " << endl;
				}
				else if ((option == 2 && time >= 3600) || (option == 1 && time >= 1800 && time < 3600)){
					cout << "��ĳɼ�Ϊ D " << endl;
				}
				else {//(option == 1 && time >= 3600)
					cout << "��ĳɼ�Ϊ E " << endl;
				}
				system("pause");
				return;
			}
			else if (!iscomplete && !haveWrong) {
				cout << "����Ӵ����ʱû�д���" << endl;
			}
			break;
		}
		case '3': {
			if (myremove.empty()) {
				cout << "����ʧ�ܣ������������֣�" << endl;
			}
			else {
				MyRemove remove;
				myremove.get_top(remove);
				curGame[remove.x][remove.y] = 0;
				myremove.pop();
				cout << "�����ɹ���" << endl;
			}
			break;
		}
		case '4': {
			srand((unsigned)time(NULL));
			int n = rand() % 81;
			while (curGame[n / 9][n % 9] != 0) {
				n = rand() % 81;
			}
			cout << "�� " << n / 9 + 1 << " �У��� " << n % 9 + 1 << " �� ����Ϊ��" << myGame[n / 9][n % 9] << endl;
			break;
		}
		case '5': {
			system("cls");
			output(myGame);
			break;
		}
		default: {
			cout << "�����������������룡" << endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}
}

//--------------------Suduku����ʵ��--------------------

// �������� 
void Suduku::input() {
	char t;
	cout << "�������̣����� 0 ��ʾ\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> t;
			myGame[i][j] = t - '0';
		}
	}
}

// [n/9][n%9]
void Suduku::getAnswer(int n) {

	// �ɹ� 
	if (n > 80) {
		flag = true;
		return; 
	}

	int x = n / 9, y = n % 9;
	// ��ֵ ���� 
	if (myGame[x][y]) {
		getAnswer(n + 1);	
		return;
	}
	// ���� 
	for (int i = 1; i <= 9; i++) {
		// �ж� 
		if (check(n, i, myGame)) {
			// �жϳɹ� ��ֵ 
			myGame[x][y] = i;
			getAnswer(n + 1);
			// �˳�ʱ�ж��Ƿ����  ���ʱ�˳� 
			if (flag) {
				return;
			}
			// δ��� �������� 
			myGame[x][y] = 0;
		}
	}
}

//bool Suduku::isOneAnswer(){
//	int count = 0;
//	bool tempflag = 0;
//
//	int tempGame[9][9];
//	for (int i = 0; i < 9; i++) 
//		for (int j = 0; j < 9; j++)
//			tempGame[i][j] = myGame[i][j];
//
//	isOneAnswer(0, count, tempGame,tempflag);
//	return count == 1;
//}
//
//void Suduku::isOneAnswer(int n, int& count, int tempGame[9][9], bool& tempflag){
//	// �ɹ� 
//	if (n > 80) {
//		count++;
//		tempflag = true;
//		return;
//	}
//
//	int x = n / 9, y = n % 9;
//	// ��ֵ ���� 
//	if (tempGame[x][y]) {
//		isOneAnswer(n+1, count, tempGame, tempflag);
//		return;
//	}
//	// ���� 
//	for (int i = 1; i <= 9; i++) {
//		// �ж� 
//		if (check(n+1, i, tempGame)) {
//			// �жϳɹ� ��ֵ 
//			tempGame[x][y] = i;
//			isOneAnswer(n, count, tempGame, tempflag);
//			// �˳�ʱ�ж��Ƿ����  ���ʱ�˳� 
//			if (tempflag) {
//				if (count > 1) {
//					return;
//				}
//				else {
//					tempflag = false;
//				}
//			} else{
//				// δ��� �������� 
//				tempGame[x][y] = 0;
//			}
//		}
//	}
//}

void Suduku::output(int game[9][9]) {
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

void Suduku::getGame(){
	//clear();
	//srand((unsigned)time(NULL));
	//for (int i = 0; i < 9; i++) {
	//	reGetValue:
	//	int value = rand() % +1;
	//	for (int j = i - 1; j >= 0; j--) {
	//		if (value == myGame[0][j]) {
	//			goto reGetValue;
	//		}
	//	}
	//	myGame[0][i] = value;
	//}
	//getAnswer(0);
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

// �жϼ�������� �Ƿ�������� 
bool Suduku::check(int n, int num,int game[9][9]) {

	// �� 
	for (int i = 0; i < 9; i++) {
		if (game[n / 9][i] == num) {
			return false;
		}
	}

	// �� 
	for (int i = 0; i < 9; i++) {
		if (game[i][n % 9] == num) {
			return false;
		}
	}

	// ��
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

void Suduku::clear(){
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			myGame[i][j] = 0;
		}
	}
	flag = false;
}


