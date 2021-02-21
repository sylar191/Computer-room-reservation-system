#include "teacher.h"

teacher::teacher() {

};

teacher::teacher(int id, string name, string pwd) {
	this->m_empid = id;
	this->m_name = name;
	this->m_pwd = pwd;
};

void teacher::openmenu() {
	cout << "欢迎教师：" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
};

void teacher::showallorder() {
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
};

void teacher::vaildorder() {
	orderfile ord;

	if (ord.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约记录如下：" << endl;
	
	vector<int> v;
	int index = 1;
	for (int i = 0;i < ord.m_order.size();i++)
	{
		if (ord.m_order[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "、";
			cout << "预约日期： 周" << ord.m_order[i]["date"];
			cout << " 时段：" << (ord.m_order[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << ord.m_order[i]["roomId"];
			string status = " 状态： ";  // 0取消的预约   1 审核中   2 已预约  -1 预约失败
			if (ord.m_order[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}
		}
	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0;
	int ret = 0;
	while (1)
	{
		cin >> select;

		if (select >= 0 && select <= v.size())
		{
			if (select == 0)  break;


			else
			{	

				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;

				cin >> ret;

				if (ret == 1) {
					ord.m_order[v[select - 1]]["status"] = "2";
				}
				else if (select == 2) {
					ord.m_order[v[select - 1]]["status"] = "-1";
				}

				
				ord.updateorder();
				cout << "审核完毕！" << endl;
				break;
			}

		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");

	};//审核预约