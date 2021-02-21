#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include"globalFile.h"
using namespace std;

class orderfile {

public:
	orderfile();

	void updateorder();//更新预约记录

	void fenge(string s,string &key,string &value);

	map<int, map<string, string>> m_order;//存放记录

	int m_size;


};