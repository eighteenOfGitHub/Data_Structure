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

	void clear();				//清空棋盘
	void input();				//输入棋盘
	void getAnswer(int n);		//求解棋盘实现(dfs)
	void output(int game[9][9]);				//输出结果
	bool check(int n, int num, int game[9][9]); //检查是否合格
	void getGame();	//生成棋盘
	void beginGame(int curGame[9][9], int option);	//练习操作页面及实现

	Stack<MyRemove> myremove;
	int myGame[9][9];
	int curGame[9][9];
	bool flag = false;
};

#endif // !SUDOKU_H

