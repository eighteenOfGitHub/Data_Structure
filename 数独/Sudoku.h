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
	void clear();				//�������
	void input();				//��������
	void getAnswer(int n);		//�������ʵ��(dfs)
	//bool isOneAnswer();		//������̽������
	//void isOneAnswer(int n,int& count,int tempGame[9][9], bool& tempflag);	//������̽��������ʵ��
	void output(int game[9][9]);				//������
	bool check(int n, int num, int game[9][9]); //����Ƿ�ϸ�
	void getGame();	//��������
	void beginGame(int curGame[9][9],int option);	//��ϰ����ҳ�漰ʵ��

private:
	int myGame[9][9];
	bool flag = false;
};