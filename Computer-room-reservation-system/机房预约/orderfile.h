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

	void updateorder();//����ԤԼ��¼

	void fenge(string s,string &key,string &value);

	map<int, map<string, string>> m_order;//��ż�¼

	int m_size;


};