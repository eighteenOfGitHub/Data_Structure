#include"TutorialSystem.h"

//-------------------------Staff����-----------------------
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
//-------------------------TutorialSystem�����뷽��-----------------------
TutorialSystem::TutorialSystem() {
	m_front = new Staff(FRONT);
}

TutorialSystem::~TutorialSystem(){
	_destroy(m_front);
}

bool TutorialSystem::insert(string name, int option) {
	switch (option){
	case 1: {//��ʦ
		Staff* staff = new Staff(TUTOR, name);
		Staff* temp = m_front; 
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = staff;
		return true;
	}

	case 2: {//�о���
		Staff* staff = new Staff(GRADUATESTUDENT, name);
		Staff* temp = m_front->next;
		if (temp == NULL) { return false; }
		//չʾ��ʦ��Ϣ
		int teacherCount = 1;
		for (; temp != NULL; temp = temp->next, teacherCount++) {
			cout << teacherCount << "." << temp->name << endl;
		}
		teacherCount--;
		//ѡ��ʦ
		int option;
	recinoption1:
		cout << "��ѡ��ʦ��";
		cin >> option;
		if (option > teacherCount || option < 1) {
			cout << "�����������������룡" << endl;
			goto recinoption1;
		}
		//¼���о�����Ϣ
		temp = m_front->next;
		for (int i = 1; i < option; i++) {
			temp = temp->next;
		}
		if (temp->student == NULL) {	//��ʦ��δ��ѧ��
			temp->student = staff;
		}
		else {
			staff->next = temp->student;
			temp->student = staff;
		}
		return true;
	}

	case 3: {//������
		Staff* staff = new Staff(UNDERGRADUATE, name);
		//չʾ��ʦ��Ϣ
		Staff* tempT = m_front->next;
		if (tempT == NULL) { return false; }
		int teacherCount = 1;
		for (; tempT != NULL; tempT = tempT->next, teacherCount++) {
			cout << teacherCount << "." << tempT->name << endl;
		}
		//ѡ��ʦ
		int option;
	recinoption2:
		cout << "��ѡ��ʦ��";
		cin >> option;
		if (option > teacherCount || option < 1) {
			cout << "�����������������룡" << endl;
			goto recinoption2;
		}
		//�ҵ���ʦ
		tempT = m_front->next;
		for (int i = 1; i < option; i++) {
			tempT = tempT->next;
		}
		Staff* tempG = tempT->student;
		if (tempG == NULL ) {					//��ʦ��δ��ѧ��
			tempT->student = staff;
		}
		else if (tempG->type == UNDERGRADUATE) {//��ʦ��δ���о���
			staff->next = tempT->student;
			tempT->student = staff;
		}
		else {
			//չʾ��ʦ�����о���
			int graduateCount = 0;
			for (; tempG != NULL && tempG->type == GRADUATESTUDENT; tempG = tempG->next) {
				cout << ++graduateCount << "." << tempG->name << endl;
			}
			cout << graduateCount + 1 << ".ֱ��ѡ��ʦ" << endl;
			//ѡ���о���
		recinoption3:
			cout << "��ѡ���о�����";
			cin >> option;
			if (option > graduateCount + 1 || option < 1) {
				cout << "�����������������룡" << endl;
				goto recinoption3;
			}
			//¼��ѧ����Ϣ
			tempG = tempT->student;
			if (option == graduateCount + 1) {	//ֱ��ѡ��ʦ
				for (int i = 1; i < graduateCount; i++) {
					tempG = tempG->next;
				}
				staff->next = tempG->next;
				tempG->next = staff;
			}
			else {								//ѡ���о���
				for (int i = 1; i < option; i++) {
					tempG = tempG->next;
				}
				if (tempG->student == NULL) {	//�о���δ��������
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
	while (cur1 != NULL) {	//�ҵ�ʦ
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
						if (temp2 == cur1) {	//û�ҵ�
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
					while (cur3 != NULL) {	//������о���
						if (cur3->name == name) {	//���о���ֱ���ı��������ҵ�Ҫɾ������
							if (temp3 == cur2) {	//û�ҵ�
								temp3->student = cur3->next;
							}
							else {
								temp3->next = cur3->next;
							}
							delete cur3;
							return true;
						} 
						if (temp3 == cur2) {	//û�ҵ�
							temp3 = temp3->student;
						}
						else {
							temp3 = temp3->next;
						}
						cur3 = cur3->next;
					}
				}
				else {	//����Ǳ�����
					if (cur2->name == name) {
						if (temp2 == cur1) {	//û�ҵ�
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
			cout << name << " Ϊ��ʦ" << endl;
			return true;
		}
		Staff* cur2 = cur1->student;
		while (cur2 != NULL) {
			if (cur2->name == name) {
				if (cur2->type == GRADUATESTUDENT) {
					cout << name << " Ϊ�о�������ʦΪ���� " << cur1->name << endl;
				}
				else {
					cout << name << " Ϊ����������ʦΪ���� " << cur1->name << endl;
				}
				return true;
			}
			Staff* cur3 = cur2->student;
			while (cur3 != NULL) {
				if (cur3->name == name) {
					cout << name << " Ϊ����������ʦΪ�о��� " << cur2->name << endl;
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
	cout << "��ʦ������" << getTCount(m_front) << endl;
	cout << "�о���������" << getGCount(m_front) << endl;
	cout << "����������:" << getUCount(m_front) << endl;
	cout << "��ʦ\t�о���/������" << endl;
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
		cout << "��δ��¼��Ա��Ϣ" << endl;
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

////�ܽ�һ��
////Ϊʲô�����ӽڵ�Ҫ����ȥ����ָ�룿
////�տ�ʼ�Ҵ���һ��ָ���ʱ���ҷ��ִ�����ɺ�gl = NULL��Ϊʲô��
////��Ϊû��һ��������¼gl��һ���ڵ�ĵ�ַ������������Ҳ������ˡ�
////��ʱ�����Ҫһ������ָ�룬ָ���ͷ�ڵ�ĵ�ַ��
//
// //�ܽ����
////�ⲿ�����Զ����������ͣ����ö�������ӿڣ���ǿ���ṹ��ȫ�ԣ������޲���
//
////˼��һ��
////Ϊʲô������ȣ�ֵ��㳤����Ϊ������
////�������ȵ����������е����Ϊ1�����ݽṹ���ԣ����룬ɾ���Ȳ�����Ϊ���ӣ�
////���������ı仯����ͳ�ƣ������ڸ��ӳ����в���ɾ������������Զ��������ȵĲ���
////������ԣ�����ȵ�����һ��������������ʱ��