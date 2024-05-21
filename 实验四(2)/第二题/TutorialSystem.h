#pragma once
#include<iostream>
#include<string>
using namespace std;
enum StaffType { TUTOR/*��ʦ*/ = 0, GRADUATESTUDENT/*�о���*/ = 1, UNDERGRADUATE/*������*/ = 2, FRONT/*ͷ���*/ = 3 };

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
	Staff* m_front;	//ͷ���Ϊ��
public:
	TutorialSystem();
	~TutorialSystem();
	bool insert(string name,int option);	//0 ¼��ɹ�; 1 ¼��ʧ��
	bool deleteStaff(string name);			//ɾ������ӿ�
	bool find(string name);					//����
	void show();							//��ʾ����ӿ�     
	
	bool isEmpty();							//�ж�Ϊ��
private:
	void _show(Staff* staff);						//��ʾ����ʵ��
	bool _deleteStaff(string name, Staff* staff);	//ɾ������ʵ��
	void _destroy(Staff* staff);					//ɾ���ý���Լ������е�next �� student

	int getTCount(Staff* staff);			//��õ�ʦ����
	int getGCount(Staff* staff);			//����о�������
	int getUCount(Staff* staff);			//��ñ���������
};
