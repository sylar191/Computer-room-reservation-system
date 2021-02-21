#include"manager.h"

manager::manager() {

};

manager::manager(string name, string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;

	this->initVector();

	ifstream ifs(COMPUTER_FILE, ios::in);

	computer c;

	while (ifs >> c.m_id && ifs >> c.m_maxnum) {
		vCom.push_back(c);
	}

	cout << "��ǰ��������Ϊ" << vCom.size() << endl;

	ifs.close();
};

void manager::openmenu() {
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
};

void manager::addperson() {

	cout << "����������˺ŵ�����" << endl;
	cout << "1���ѧ��" << endl;
	cout << "2�����ʦ" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ��";

	}
	else if (select == 2) {
		fileName = TEACHER_FILE;
		tip = "�������ʦ���";
	}


	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (1) {

		cin >> id;
		

	
		bool ret = this->checkrepeat(id, select);

		if (ret) cout << "�ظ�������������" << endl;
		

		else  break;
	}

		cout << "����������" << endl;
		cin >> name;

		cout << "����������" << endl;
		cin >> pwd;
		cout << endl;

		ofs.open(fileName, ios::out | ios::app);
		ofs << id << " " << name << " " << pwd << " " << endl;
		cout << "��ӳɹ�\n" << endl;
		this->initVector();
		cout << endl;
		system("pause");
		system("cls");

		ofs.close();

	
}//����˺�


void manager::initVector() {

	ifstream ifs(STUDENT_FILE, ios::in);

	vStu.clear();

	vTea.clear();

	student s;

	while (ifs >> s.m_id&&ifs >> s.m_name&&ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ����������" << vStu.size() << endl;
	ifs.close();



	ifs.open(TEACHER_FILE, ios::in);

	teacher t;

	while (ifs >> t.m_empid&&ifs >> t.m_name&&ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ��������" << vTea.size() << endl;
	ifs.close();

}

bool manager::checkrepeat(int id,int type) {

	if (type == 1) {
		for (auto it = vStu.begin();it != vStu.end();it++)
		{
			if (id == it->m_id) return true;
		}
	}
	else if (type == 2) {
		for (auto it = vTea.begin();it != vTea.end();it++)
		{
			if (id == it->m_empid) return true;
		}
	}
	return false;
}

void printstudent(student &s) {

	cout << "ѧ��:" << s.m_id << "  ����:" << s.m_name << "  ����:" << s.m_pwd << endl;

}


void printteacher(teacher &s) {

	cout << "ְ����:" << s.m_empid << "  ����:" << s.m_name << "  ����:" << s.m_pwd << endl;

}

void manager::showperson() {
	
	cout << "��ѡ��鿴����" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;

	int select = 0;
	
		cin >> select;

		if (select == 1)
		{
			cout << "����ѧ����Ϣ����:\n" << endl;
			for_each(vStu.begin(), vStu.end(), printstudent);

		}

		else if (select == 2) {

			cout << "���н�ʦ��Ϣ����:\n" << endl;
			for_each(vTea.begin(), vTea.end(), printteacher);

		}

		else {
			cout << "�������,����������" << endl;
			
		}

		system("pause");
		system("cls");
	
}//�鿴�˺�

void manager::showcomputer() {
	cout << "������Ϣ���£� " << endl;
	for (auto it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ� " << it->m_id << " ������������� " << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}//�鿴������Ϣ

void manager::cleanfile(){
	ofstream ofs(ORDER_FILE, ios::trunc);

	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");

}//���ԤԼ��¼