#pragma once
#include<iostream>
#include"identity.h"
#include"globalFile.h"
#include"computer.h"
#include"orderfile.h"
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

class student :public Identity{

public:
	
	student();

	student(int id, string name, string pwd);

	
	virtual void openmenu();

	void applyorder();//申请预约

	void showmyorder();//查看我的预约

	void showallorder();//查看所有预约

	void cancelorder();//取消预约;

	int m_id; //学生学号

	vector<computer> vCom;
};