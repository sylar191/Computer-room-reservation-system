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

	void applyorder();//����ԤԼ

	void showmyorder();//�鿴�ҵ�ԤԼ

	void showallorder();//�鿴����ԤԼ

	void cancelorder();//ȡ��ԤԼ;

	int m_id; //ѧ��ѧ��

	vector<computer> vCom;
};