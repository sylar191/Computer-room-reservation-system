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

class teacher :public Identity {

public:
	teacher();

	teacher(int id, string name, string pwd);

	virtual void openmenu();

	void showallorder();

	void vaildorder();//…Û∫À‘§‘º

	int m_empid;//ΩÃ ¶±‡∫≈
};