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
	cout << "��ӭѧ������" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
};

void student::applyorder() {

	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (1)
	{
		cin >> date;
		if (date >= 1 && date <= 5) break;
		cout << "�����������������" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (1)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2) break;
		cout << "�����������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].m_maxnum << endl;
	cout << "2�Ż���������" << vCom[1].m_maxnum << endl;
	cout << "3�Ż���������" << vCom[2].m_maxnum << endl;

	while (1)
	{
		cin >> room;
		if (room >= 1 && room <= 2) break;
		cout << "�����������������" << endl;
	}

	cout << "ԤԼ�ɹ�" << endl;

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

};//����ԤԼ

void student::showmyorder() {

	orderfile ord;

	if (ord.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0;i < ord.m_size;i++)
	{
		if (atoi(ord.m_order[i]["stuid"].c_str()) == this->m_id) {

			cout << "ԤԼ���ڣ� ��" << ord.m_order[i]["date"];
			cout << " ʱ�Σ�" << (ord.m_order[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << ord.m_order[i]["roomid"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (ord.m_order[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (ord.m_order[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (ord.m_order[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;

		}
	}

	system("pause");
	system("cls");
};//�鿴�ҵ�ԤԼ

void student::showallorder() {
	orderfile ord;

	if (ord.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0;i < ord.m_size;i++)
	{
		

			cout << "ԤԼ���ڣ� ��" << ord.m_order[i]["date"];
			cout << " ʱ�Σ�" << (ord.m_order[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << ord.m_order[i]["roomid"];
			cout << " ѧ�ţ�" << ord.m_order[i]["stuid"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (ord.m_order[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (ord.m_order[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (ord.m_order[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;

		
	}

	system("pause");
	system("cls");
};//�鿴����ԤԼ

void student::cancelorder() {

	orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v;

	int index = 1;

	for (int i = 0;i < of.m_size;i++)
	{
		if (atoi(of.m_order[i]["stuid"].c_str()) == this->m_id)
		{
			
			if (of.m_order[i]["status"] == "1" || of.m_order[i]["status"] == "2")
			{
				v.push_back(i);//vector�д�ŵ��Ƿ���Ҫ��ļ�¼��map�����е�λ��
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_order[i]["date"];
				cout << "  ʱ�Σ�" << (of.m_order[i]["interval"]=1?"����":"����");
				cout << "  ������" << of.m_order[i]["roomid"];

				string status = "״̬��";
				if (of.m_order[i]["status"] == "1") {
					status += "�����";
				}
				
				if (of.m_order[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				
				cout << status << endl;
				
			}
		}


	}

	cout << "������ȡ���ļ�¼����0������" << endl;

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
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
			
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");

}//ȡ��ԤԼ;