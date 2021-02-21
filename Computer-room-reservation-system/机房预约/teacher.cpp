#include "teacher.h"

teacher::teacher() {

};

teacher::teacher(int id, string name, string pwd) {
	this->m_empid = id;
	this->m_name = name;
	this->m_pwd = pwd;
};

void teacher::openmenu() {
	cout << "��ӭ��ʦ��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
};

void teacher::showallorder() {
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
};

void teacher::vaildorder() {
	orderfile ord;

	if (ord.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ��¼���£�" << endl;
	
	vector<int> v;
	int index = 1;
	for (int i = 0;i < ord.m_order.size();i++)
	{
		if (ord.m_order[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "��";
			cout << "ԤԼ���ڣ� ��" << ord.m_order[i]["date"];
			cout << " ʱ�Σ�" << (ord.m_order[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << ord.m_order[i]["roomId"];
			string status = " ״̬�� ";  // 0ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
			if (ord.m_order[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}
		}
	cout << "��������˵�ԤԼ��¼��0������" << endl;
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

				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;

				cin >> ret;

				if (ret == 1) {
					ord.m_order[v[select - 1]]["status"] = "2";
				}
				else if (select == 2) {
					ord.m_order[v[select - 1]]["status"] = "-1";
				}

				
				ord.updateorder();
				cout << "�����ϣ�" << endl;
				break;
			}

		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");

	};//���ԤԼ