#include<iostream>
#include"globalFile.h"
#include"identity.h"
#include"orderfile.h"
#include<fstream>
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<string>
using namespace std;


void managermenu(Identity* &managerr)
{
	while (1) {
		managerr->openmenu();

		manager* man = (manager*)managerr;

		int select = 0;

		cin >> select;

		switch (select)
		{
		case 1:
			cout << "添加账号" << endl;
			man->addperson();

			break;

		case 2:
			cout << "查看账号" << endl;
			man->showperson();
			break;

		case 3:
			cout << "查看机房" << endl;
			man->showcomputer();
			break;

		case 4:
			cout << "清空预约" << endl;
			man->cleanfile();

			break;

		default:
			delete managerr;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		}
	}


}void studentmenu(Identity* &studentt)
{
	while (1) {
		studentt->openmenu();

		student* stu = (student*)studentt;

		int select = 0;

		cin >> select;

		switch (select)
		{
		case 1:
			cout << "申请预约" << endl;
			stu->applyorder();

			break;

		case 2:
			cout << "查看自身预约" << endl;
			
			stu->showmyorder();
			break;

		case 3:
			cout << "查看所有预约" << endl;
			stu->showallorder();
			break;

		case 4:
			cout << "取消预约" << endl;
			stu->cancelorder();

			break;

		default:
			delete studentt;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		}
	}
}


void teachermenu(Identity * &teacherr) {

	while (1)
	{
		teacherr->openmenu();

		teacher *tea = (teacher *)teacherr;

		int select = 0;
		cin >>select;
		if (select == 1) {
			tea->showallorder();//查看所有预约
			
		}
		else if (select == 2)
		{
			tea->vaildorder();//审核预约

		}
		else
		{
			delete teacherr;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}



	}


}

void loginIn(string filename, int type) {
	Identity *person = NULL;

	ifstream ifs(filename,ios::in);
	
	int id = 0;
	string name;
	string pwd;

	if (type == 1) 
	{
		cout << "输入学号" << endl;
		cin >> id;	
	}
	else if(type==2)
	{
		cout << "输入职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1){
		int fid;
		string fname, fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "学生验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, pwd);
				studentmenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		int fid;
		string fname, fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{

			if (id == fid && name == fname && pwd == fpwd) {
				cout << "教师验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);
				teachermenu(person);
				return;
			}
		}

	}
	else if (type == 3) {
		string fname, fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{

			if (name == fname && pwd == fpwd) {
				cout << "管理员验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new manager(name, pwd);
				managermenu(person);
				return;
			}
		}
	}

	cout << "验证登陆失败" << endl;

	system("pause");
	system("cls");
	return;

}



int main() {
	int select = 0;

	while (1) {
		cout << "======================  欢迎来到传智播客机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";

		cout << "输入您的选择: ";
		cin >> select;


		switch (select)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);

			break;

		case 2:
			loginIn(TEACHER_FILE, 2);
			break;

		case 3 :
			loginIn(ADMIN_FILE, 3);
			break;

		case 0:
			cout << "谢谢使用" << endl;
			system("pause");
			return 0;

			break;


		default:cout << "输入有误 " << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}