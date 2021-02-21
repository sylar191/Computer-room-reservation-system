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
			cout << "����˺�" << endl;
			man->addperson();

			break;

		case 2:
			cout << "�鿴�˺�" << endl;
			man->showperson();
			break;

		case 3:
			cout << "�鿴����" << endl;
			man->showcomputer();
			break;

		case 4:
			cout << "���ԤԼ" << endl;
			man->cleanfile();

			break;

		default:
			delete managerr;
			cout << "ע���ɹ�" << endl;
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
			cout << "����ԤԼ" << endl;
			stu->applyorder();

			break;

		case 2:
			cout << "�鿴����ԤԼ" << endl;
			
			stu->showmyorder();
			break;

		case 3:
			cout << "�鿴����ԤԼ" << endl;
			stu->showallorder();
			break;

		case 4:
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelorder();

			break;

		default:
			delete studentt;
			cout << "ע���ɹ�" << endl;
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
			tea->showallorder();//�鿴����ԤԼ
			
		}
		else if (select == 2)
		{
			tea->vaildorder();//���ԤԼ

		}
		else
		{
			delete teacherr;
			cout << "ע���ɹ�" << endl;
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
		cout << "����ѧ��" << endl;
		cin >> id;	
	}
	else if(type==2)
	{
		cout << "����ְ����" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1){
		int fid;
		string fname, fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "ѧ����֤��½�ɹ�" << endl;
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
				cout << "��ʦ��֤��½�ɹ�" << endl;
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
				cout << "����Ա��֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new manager(name, pwd);
				managermenu(person);
				return;
			}
		}
	}

	cout << "��֤��½ʧ��" << endl;

	system("pause");
	system("cls");
	return;

}



int main() {
	int select = 0;

	while (1) {
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";

		cout << "��������ѡ��: ";
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
			cout << "ллʹ��" << endl;
			system("pause");
			return 0;

			break;


		default:cout << "�������� " << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}