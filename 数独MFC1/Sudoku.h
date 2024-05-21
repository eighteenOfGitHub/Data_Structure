#pragma once
#ifndef SUDOKU_H
#define SUDPKU_H

#include "pch.h"
#include<iostream>
#include"Stack.hpp"
using namespace std;

class Sudoku {
public:
	Sudoku();
	void practice(int opotion);

	void clear();				//�������
	void input();				//��������
	void getAnswer(int n);		//�������ʵ��(dfs)
	void output(int game[9][9]);				//������
	bool check(int n, int num, int game[9][9]); //����Ƿ�ϸ�
	void getGame();	//��������
	void beginGame(int curGame[9][9], int option);	//��ϰ����ҳ�漰ʵ��

	Stack<MyRemove> myremove;
	int myGame[9][9];
	int curGame[9][9];
	bool flag = false;
};

#endif // !SUDOKU_H

