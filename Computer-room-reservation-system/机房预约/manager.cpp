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

	cout << "当前机房数量为" << vCom.size() << endl;

	ifs.close();
};

void manager::openmenu() {
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
};

void manager::addperson() {

	cout << "请输入添加账号的类型" << endl;
	cout << "1添加学生" << endl;
	cout << "2添加老师" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号";

	}
	else if (select == 2) {
		fileName = TEACHER_FILE;
		tip = "请输入教师编号";
	}


	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (1) {

		cin >> id;
		

	
		bool ret = this->checkrepeat(id, select);

		if (ret) cout << "重复，请重新输入" << endl;
		

		else  break;
	}

		cout << "请输入姓名" << endl;
		cin >> name;

		cout << "请输入密码" << endl;
		cin >> pwd;
		cout << endl;

		ofs.open(fileName, ios::out | ios::app);
		ofs << id << " " << name << " " << pwd << " " << endl;
		cout << "添加成功\n" << endl;
		this->initVector();
		cout << endl;
		system("pause");
		system("cls");

		ofs.close();

	
}//添加账号


void manager::initVector() {

	ifstream ifs(STUDENT_FILE, ios::in);

	vStu.clear();

	vTea.clear();

	student s;

	while (ifs >> s.m_id&&ifs >> s.m_name&&ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生的数量是" << vStu.size() << endl;
	ifs.close();



	ifs.open(TEACHER_FILE, ios::in);

	teacher t;

	while (ifs >> t.m_empid&&ifs >> t.m_name&&ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师的数量是" << vTea.size() << endl;
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

	cout << "学号:" << s.m_id << "  姓名:" << s.m_name << "  密码:" << s.m_pwd << endl;

}


void printteacher(teacher &s) {

	cout << "职工号:" << s.m_empid << "  姓名:" << s.m_name << "  密码:" << s.m_pwd << endl;

}

void manager::showperson() {
	
	cout << "请选择查看内容" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有教师" << endl;

	int select = 0;
	
		cin >> select;

		if (select == 1)
		{
			cout << "所有学生信息如下:\n" << endl;
			for_each(vStu.begin(), vStu.end(), printstudent);

		}

		else if (select == 2) {

			cout << "所有教师信息如下:\n" << endl;
			for_each(vTea.begin(), vTea.end(), printteacher);

		}

		else {
			cout << "输入错误,请重新输入" << endl;
			
		}

		system("pause");
		system("cls");
	
}//查看账号

void manager::showcomputer() {
	cout << "机房信息如下： " << endl;
	for (auto it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号： " << it->m_id << " 机房最大容量： " << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}//查看机房信息

void manager::cleanfile(){
	ofstream ofs(ORDER_FILE, ios::trunc);

	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");

}//清空预约记录