#include"TutorialSystem.h"

void showContents(){
	cout << "-----------------------\n"
		<< "��ӭʹ�õ�ʦ�ƹ���ϵͳ!\n"
		<< "Ŀ¼��\n"
		<< "1.¼��\n"
		<< "2.ɾ��\n"
		<< "3.��ѯ\n"
		<< "4.��ʾ\n"
		<< "5.�˳�\n"
		<< "-----------------------\n"
		<< "��ѡ��������Ҫ�Ĺ��ܣ�";
}

int main() {
	TutorialSystem turtorialsystem;
	while (1)
	{
		showContents();
		int option;
		cin >> option;
		switch(option){
		case 1: {
			string name;
			while (1) {
				int option;
				cout << "PS������ over ����¼�빦��\n"
					<< "������������";
				cin >> name;
				if (name == "over") {break;} 
				cout << "1.��ʦ\n"
					<< "2.�о���\n"
					<< "3.������\n";
				recinoption:
				cout << "��ѡ��ְҵ��";
				cin >> option;
				if (option > 3 || option < 1) {
					cout << "�����������������룡" << endl;
					goto recinoption;
				}
				if (turtorialsystem.insert(name, option)) {
					cout << "¼��ɹ���" << endl;
				}
				else {
					cout << "ϵͳ��δ��¼��ʦ��Ϣ������¼�뵼ʦ��" << endl;
				}
			}
			break;
			}
		case 2: {
			if (!turtorialsystem.isEmpty()) {
				string name;
				cout << "��������Ҫɾ����������";
				cin >> name;
				if (turtorialsystem.deleteStaff(name)) {
					cout << "ɾ���ɹ���" << endl;
				}
				else {
					cout << "�������������δ¼���ְԱ��Ϣ!"<<endl;
				}
			}
			else {cout << "����Ϊ�գ�����¼�����ݣ�";}
			}
				break;
		case 3: {
			if (turtorialsystem.isEmpty()) {
				cout << "����Ϊ�գ�����¼�����ݣ�";
			}
			else {
				string name;
				cout << "��������Ҫ���ҵ�������";
				cin >> name;
				if (!turtorialsystem.find(name)) {
					cout << "�������������δ¼���ְԱ��Ϣ!" << endl;
				}
				break;
			}
			}
			case 4:
				turtorialsystem.show();
				break;
			case 5:
				cout << "��ӭ�´�ʹ�ã�" << endl;
				system("pause");
				return 0;
			default:
				cout << "ѡ��Ϸ��������²�����" << endl;
		}
		system("pause");
		system("cls");
	}
	return 0;
}