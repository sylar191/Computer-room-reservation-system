#pragma once
#include<iostream>
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"globalFile.h"
#include"computer.h"
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

class manager : public Identity{

public:
	manager();

	manager(string name, string pwd);

	virtual void openmenu();

	void addperson();//����˺�

	void showperson();//�鿴�˺�

	void showcomputer();//�鿴������Ϣ

	void cleanfile();//���ԤԼ��¼

	void initVector();//vector��ʼ�� 

	bool checkrepeat(int id, int type);//����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)

	vector<student> vStu;

	vector<teacher> vTea;

	vector<computer> vCom;

};