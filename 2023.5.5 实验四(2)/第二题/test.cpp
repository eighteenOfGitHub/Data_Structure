#include"TutorialSystem.h"

void showContents(){
	cout << "-----------------------\n"
		<< "欢迎使用导师制管理系统!\n"
		<< "目录：\n"
		<< "1.录入\n"
		<< "2.删除\n"
		<< "3.查询\n"
		<< "4.显示\n"
		<< "5.退出\n"
		<< "-----------------------\n"
		<< "请选择您所需要的功能：";
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
				cout << "PS：输入 over 结束录入功能\n"
					<< "请输入姓名：";
				cin >> name;
				if (name == "over") {break;} 
				cout << "1.导师\n"
					<< "2.研究生\n"
					<< "3.本科生\n";
				recinoption:
				cout << "请选择职业：";
				cin >> option;
				if (option > 3 || option < 1) {
					cout << "输入有误，请重新输入！" << endl;
					goto recinoption;
				}
				if (turtorialsystem.insert(name, option)) {
					cout << "录入成功！" << endl;
				}
				else {
					cout << "系统尚未收录导师信息，请先录入导师！" << endl;
				}
			}
			break;
			}
		case 2: {
			if (!turtorialsystem.isEmpty()) {
				string name;
				cout << "请输入所要删除的姓名：";
				cin >> name;
				if (turtorialsystem.deleteStaff(name)) {
					cout << "删除成功！" << endl;
				}
				else {
					cout << "输入姓名有误或未录入该职员信息!"<<endl;
				}
			}
			else {cout << "数据为空！请先录入数据！";}
			}
				break;
		case 3: {
			if (turtorialsystem.isEmpty()) {
				cout << "数据为空！请先录入数据！";
			}
			else {
				string name;
				cout << "请输入所要查找的姓名：";
				cin >> name;
				if (!turtorialsystem.find(name)) {
					cout << "输入姓名有误或未录入该职员信息!" << endl;
				}
				break;
			}
			}
			case 4:
				turtorialsystem.show();
				break;
			case 5:
				cout << "欢迎下次使用！" << endl;
				system("pause");
				return 0;
			default:
				cout << "选项不合法，请重新操作！" << endl;
		}
		system("pause");
		system("cls");
	}
	return 0;
}