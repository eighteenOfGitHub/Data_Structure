#pragma once
#include<iostream>
#include"Stack.hpp"
using namespace std;

class Suduku {
public:
	Suduku();
	void solveByInput();
	void practice(int opotion);

private:
	void clear();				//清空棋盘
	void input();				//输入棋盘
	void getAnswer(int n);		//求解棋盘实现(dfs)
	//bool isOneAnswer();		//获得棋盘解的数量
	//void isOneAnswer(int n,int& count,int tempGame[9][9], bool& tempflag);	//获得棋盘解的数量的实现
	void output(int game[9][9]);				//输出结果
	bool check(int n, int num, int game[9][9]); //检查是否合格
	void getGame();	//生成棋盘
	void beginGame(int curGame[9][9],int option);	//练习操作页面及实现

private:
	int myGame[9][9];
	bool flag = false;
};