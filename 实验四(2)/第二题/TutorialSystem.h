#pragma once
#include<iostream>
#include<string>
using namespace std;
enum StaffType { TUTOR/*导师*/ = 0, GRADUATESTUDENT/*研究生*/ = 1, UNDERGRADUATE/*本科生*/ = 2, FRONT/*头结点*/ = 3 };

struct Staff {
	StaffType type;
	string name;
	Staff* next;
	Staff* student;
	Staff();
	Staff(StaffType type, string name);
};

class TutorialSystem{
private:
	Staff* m_front;	//头结点为空
public:
	TutorialSystem();
	~TutorialSystem();
	bool insert(string name,int option);	//0 录入成功; 1 录入失败
	bool deleteStaff(string name);			//删除对外接口
	bool find(string name);					//查找
	void show();							//显示对外接口     
	
	bool isEmpty();							//判断为空
private:
	void _show(Staff* staff);						//显示功能实现
	bool _deleteStaff(string name, Staff* staff);	//删除功能实现
	void _destroy(Staff* staff);					//删除该结点以及其所有的next 和 student

	int getTCount(Staff* staff);			//获得导师数量
	int getGCount(Staff* staff);			//获得研究生数量
	int getUCount(Staff* staff);			//获得本科生数量
};
