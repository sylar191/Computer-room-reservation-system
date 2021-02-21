#include "student.h"


student::student() {

};

student::student(int id, string name, string pwd) {
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	computer c;

	ifstream ifs(COMPUTER_FILE, ios::in);

	while (ifs >> c.m_id && ifs >> c.m_maxnum)
	{
		vCom.push_back(c);
	}
};


void student::openmenu() {
	cout << "欢迎学生代表：" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
};

void student::applyorder() {

	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (1)
	{
		cin >> date;
		if (date >= 1 && date <= 5) break;
		cout << "输入错误，请重新输入" << endl;
	}

	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (1)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2) break;
		cout << "输入错误，请重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << vCom[0].m_maxnum << endl;
	cout << "2号机房容量：" << vCom[1].m_maxnum << endl;
	cout << "3号机房容量：" << vCom[2].m_maxnum << endl;

	while (1)
	{
		cin >> room;
		if (room >= 1 && room <= 2) break;
		cout << "输入错误，请重新输入" << endl;
	}

	cout << "预约成功" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuid:" << this->m_id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomid:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");

};//申请预约

void student::showmyorder() {

	orderfile ord;

	if (ord.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0;i < ord.m_size;i++)
	{
		if (atoi(ord.m_order[i]["stuid"].c_str()) == this->m_id) {

			cout << "预约日期： 周" << ord.m_order[i]["date"];
			cout << " 时段：" << (ord.m_order[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << ord.m_order[i]["roomid"];
			string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
			if (ord.m_order[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (ord.m_order[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (ord.m_order[i]["status"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;

		}
	}

	system("pause");
	system("cls");
};//查看我的预约

void student::showallorder() {
	orderfile ord;

	if (ord.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0;i < ord.m_size;i++)
	{
		

			cout << "预约日期： 周" << ord.m_order[i]["date"];
			cout << " 时段：" << (ord.m_order[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << ord.m_order[i]["roomid"];
			cout << " 学号：" << ord.m_order[i]["stuid"];
			string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
			if (ord.m_order[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (ord.m_order[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (ord.m_order[i]["status"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;

		
	}

	system("pause");
	system("cls");
};//查看所有预约

void student::cancelorder() {

	orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int> v;

	int index = 1;

	for (int i = 0;i < of.m_size;i++)
	{
		if (atoi(of.m_order[i]["stuid"].c_str()) == this->m_id)
		{
			
			if (of.m_order[i]["status"] == "1" || of.m_order[i]["status"] == "2")
			{
				v.push_back(i);//vector中存放的是符合要求的记录在map容器中的位置
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_order[i]["date"];
				cout << "  时段：" << (of.m_order[i]["interval"]=1?"上午":"下午");
				cout << "  机房：" << of.m_order[i]["roomid"];

				string status = "状态：";
				if (of.m_order[i]["status"] == "1") {
					status += "审核中";
				}
				
				if (of.m_order[i]["status"] == "2") {
					status += "预约成功";
				}
				
				cout << status << endl;
				
			}
		}


	}

	cout << "请输入取消的记录，按0代表返回" << endl;

	int select = 0;
	while (1)
	{
		cin >> select;

		if (select >= 0 && select <= v.size())
		{
			if (select == 0)  break;


			else
			{
				of.m_order[v[select - 1]]["status"] = "0";
				of.updateorder();
				cout << "已取消预约" << endl;
				break;
			}
			
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");

}//取消预约;