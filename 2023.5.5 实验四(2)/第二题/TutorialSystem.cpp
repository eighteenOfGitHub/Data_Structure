#include"TutorialSystem.h"

//-------------------------Staff构造-----------------------
Staff::Staff() {
	next = NULL;
	student = NULL;
}
Staff::Staff(StaffType type, string name = "head") {
	this->type = type;
	this->name = name;
	this->next = NULL;
	this->student = NULL;
}
//-------------------------TutorialSystem构造与方法-----------------------
TutorialSystem::TutorialSystem() {
	m_front = new Staff(FRONT);
}

TutorialSystem::~TutorialSystem(){
	_destroy(m_front);
}

bool TutorialSystem::insert(string name, int option) {
	switch (option){
	case 1: {//导师
		Staff* staff = new Staff(TUTOR, name);
		Staff* temp = m_front; 
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = staff;
		return true;
	}

	case 2: {//研究生
		Staff* staff = new Staff(GRADUATESTUDENT, name);
		Staff* temp = m_front->next;
		if (temp == NULL) { return false; }
		//展示导师信息
		int teacherCount = 1;
		for (; temp != NULL; temp = temp->next, teacherCount++) {
			cout << teacherCount << "." << temp->name << endl;
		}
		teacherCount--;
		//选择导师
		int option;
	recinoption1:
		cout << "请选择导师：";
		cin >> option;
		if (option > teacherCount || option < 1) {
			cout << "输入有误，请重新输入！" << endl;
			goto recinoption1;
		}
		//录入研究生信息
		temp = m_front->next;
		for (int i = 1; i < option; i++) {
			temp = temp->next;
		}
		if (temp->student == NULL) {	//导师暂未带学生
			temp->student = staff;
		}
		else {
			staff->next = temp->student;
			temp->student = staff;
		}
		return true;
	}

	case 3: {//本科生
		Staff* staff = new Staff(UNDERGRADUATE, name);
		//展示导师信息
		Staff* tempT = m_front->next;
		if (tempT == NULL) { return false; }
		int teacherCount = 1;
		for (; tempT != NULL; tempT = tempT->next, teacherCount++) {
			cout << teacherCount << "." << tempT->name << endl;
		}
		//选择导师
		int option;
	recinoption2:
		cout << "请选择导师：";
		cin >> option;
		if (option > teacherCount || option < 1) {
			cout << "输入有误，请重新输入！" << endl;
			goto recinoption2;
		}
		//找到导师
		tempT = m_front->next;
		for (int i = 1; i < option; i++) {
			tempT = tempT->next;
		}
		Staff* tempG = tempT->student;
		if (tempG == NULL ) {					//导师暂未带学生
			tempT->student = staff;
		}
		else if (tempG->type == UNDERGRADUATE) {//导师暂未带研究生
			staff->next = tempT->student;
			tempT->student = staff;
		}
		else {
			//展示导师所带研究生
			int graduateCount = 0;
			for (; tempG != NULL && tempG->type == GRADUATESTUDENT; tempG = tempG->next) {
				cout << ++graduateCount << "." << tempG->name << endl;
			}
			cout << graduateCount + 1 << ".直接选择导师" << endl;
			//选择研究生
		recinoption3:
			cout << "请选择研究生：";
			cin >> option;
			if (option > graduateCount + 1 || option < 1) {
				cout << "输入有误，请重新输入！" << endl;
				goto recinoption3;
			}
			//录入学生信息
			tempG = tempT->student;
			if (option == graduateCount + 1) {	//直接选择导师
				for (int i = 1; i < graduateCount; i++) {
					tempG = tempG->next;
				}
				staff->next = tempG->next;
				tempG->next = staff;
			}
			else {								//选择研究生
				for (int i = 1; i < option; i++) {
					tempG = tempG->next;
				}
				if (tempG->student == NULL) {	//研究生未带本科生
					tempG->student = staff;
				}
				else {
					staff->next = tempG->student;
					tempG->student = staff;
				}
			}
		}
		return true;
		}
	}
}

bool TutorialSystem::deleteStaff(string name){
	Staff* temp1 = m_front;
	Staff* cur1 = m_front->next;
	while (cur1 != NULL) {	//找导师
		if (cur1->name == name) {
			temp1->next = cur1->next;
			_destroy(cur1->student);
			delete cur1;
			return true;
		}
		else {
			Staff* temp2 = cur1;
			Staff* cur2 = cur1->student;
			while (cur2 != NULL) {
				if (cur2->type == GRADUATESTUDENT) {
					if (cur2->name == name) {
						if (temp2 == cur1) {	//没找到
							temp2->student = cur2->next;
						}
						else {
							temp2->next = cur2->next;
						}
						_destroy(cur2->student);
						delete cur2;
						return true;
					}
					Staff* temp3 = cur2;
					Staff* cur3 = cur2->student;
					while (cur3 != NULL) {	//如果是研究生
						if (cur3->name == name) {	//由研究生直到的本科生中找到要删除的人
							if (temp3 == cur2) {	//没找到
								temp3->student = cur3->next;
							}
							else {
								temp3->next = cur3->next;
							}
							delete cur3;
							return true;
						} 
						if (temp3 == cur2) {	//没找到
							temp3 = temp3->student;
						}
						else {
							temp3 = temp3->next;
						}
						cur3 = cur3->next;
					}
				}
				else {	//如果是本科生
					if (cur2->name == name) {
						if (temp2 == cur1) {	//没找到
							temp2->student = cur2->next;
						}
						else {
							temp2->next = cur2->next;
						}
						delete cur2;
						return true;
					}
				}
				if (temp2 == cur1) {
					temp2 = temp2->student;
				}
				else {
					temp2 = temp2->next;
				}
				cur2 = cur2->next;
			}
		}
		temp1 = temp1->next;
		cur1 = cur1->next;
	}
	return false;
}


bool TutorialSystem::find(string name) {
	Staff* cur1 = m_front->next;
	while (cur1 != NULL) {
		if (cur1->name == name) {
			cout << name << " 为导师" << endl;
			return true;
		}
		Staff* cur2 = cur1->student;
		while (cur2 != NULL) {
			if (cur2->name == name) {
				if (cur2->type == GRADUATESTUDENT) {
					cout << name << " 为研究生，导师为教授 " << cur1->name << endl;
				}
				else {
					cout << name << " 为本科生，导师为教授 " << cur1->name << endl;
				}
				return true;
			}
			Staff* cur3 = cur2->student;
			while (cur3 != NULL) {
				if (cur3->name == name) {
					cout << name << " 为本科生，导师为研究生 " << cur2->name << endl;
					return true;
				}
				cur3 = cur3->next;
			}
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
	return false;
}

void TutorialSystem::show() {
	cout << "导师数量：" << getTCount(m_front) << endl;
	cout << "研究生数量：" << getGCount(m_front) << endl;
	cout << "本科生数量:" << getUCount(m_front) << endl;
	cout << "导师\t研究生/本科生" << endl;
	_show(m_front->next);
}
bool TutorialSystem::isEmpty()
{
	if (m_front->next == NULL) {
		return true;
	}
	return false;
}

void TutorialSystem::_destroy(Staff* staff){
	if (staff == NULL) {
		return;
	}
	_destroy(staff->student);
	_destroy(staff->next);
	delete staff;
}
void TutorialSystem::_show(Staff* staff) {
	if (staff == NULL) {
		cout << "暂未收录人员信息" << endl;
	}
	else {
		while (staff != NULL) {
			cout << staff->name << ":";
			Staff* cur1 = staff->student;
			if (cur1 == NULL) {
				cout << "\tNULL" << endl;
			}
			else {
				while (cur1 != NULL) {
					if (cur1->type == GRADUATESTUDENT) {
						cout << "\t" << cur1->name << ":";
						Staff* cur2 = cur1->student;
						if (cur2 == NULL) {
							cout << "\tNULL";
						}
						else {
							while (cur2 != NULL) {
								cout << "\t" << cur2->name;
								cur2 = cur2->next;
							}
						}
						cout << endl;
					}
					else {
						cout << "\t" << cur1->name << endl;
					}
					cur1 = cur1->next;
				}
			}
			staff = staff->next;
		}
	}
}

bool TutorialSystem::_deleteStaff(string name, Staff* staff)
{
	if (staff == NULL) {
		return false;
	}
	else {
		if (staff->name == name) {
			return true;
		}
		else {
			return _deleteStaff(name, staff->next) || _deleteStaff(name, staff->student);
		}
	}

}

int TutorialSystem::getTCount(Staff* staff) {
	int count = 0;
	while (staff->next != NULL) {
		count++;
		staff = staff->next;
	}
	return count;
}
int TutorialSystem::getGCount(Staff* staff) {
	int count = 0;
	Staff* curStudent;
	while (staff->next != NULL) {
		staff = staff->next;
		if (staff->student != NULL) {
			curStudent = staff->student;
			while (curStudent != NULL && curStudent->type == GRADUATESTUDENT) {
				count++;
				curStudent = curStudent->next;
			}
		}
	}
	return count;
}
int TutorialSystem::getUCount(Staff* staff) {
	if (staff == NULL) {
		return 0;
	}
	else {
		if (staff->type == UNDERGRADUATE) {
			return getUCount(staff->next)+getUCount(staff->student) + 1;
		}
		else {
			return getUCount(staff->next) + getUCount(staff->student);
		}
	}
}

////总结一：
////为什么构造子节点要传进去二级指针？
////刚开始我传进一级指针的时候，我发现创建完成后，gl = NULL，为什么？
////因为没有一个变量记录gl第一个节点的地址啊，所以最后找不到它了。
////这时候就需要一个二级指针，指向该头节点的地址。
//
// //总结二：
////外部操作自定义数据类型，设置独立对外接口，加强数结构安全性，减少无操作
//
////思考一：
////为什么不把深度，值结点长度设为参数？
////广义表相比单链表，链队列等深度为1的数据结构而言，插入，删除等操作更为复杂，
////对于总数的变化不好统计，并且在复杂程序中插入删除操作次数会远多于求深度的操作
////总体而言，求深度单另设一函数，减少运算时间