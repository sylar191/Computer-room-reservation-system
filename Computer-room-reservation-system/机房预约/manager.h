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

	void addperson();//添加账号

	void showperson();//查看账号

	void showcomputer();//查看机房信息

	void cleanfile();//清空预约记录

	void initVector();//vector初始化 

	bool checkrepeat(int id, int type);//检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)

	vector<student> vStu;

	vector<teacher> vTea;

	vector<computer> vCom;

};