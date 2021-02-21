#include"orderfile.h"

orderfile::orderfile() {

	ifstream ifs(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuid;
	string stuName;
	string roomid;
	string status;

	this->m_size = 0;


	while (ifs >> date && ifs>>interval && ifs>>stuid && ifs>> stuName
		&& ifs>>roomid && ifs>>status)
	{
		string key;
		string value;
		map<string, string> m;

		fenge(date, key, value);
		m.insert(make_pair(key, value));

		fenge(interval, key, value);
		m.insert(make_pair(key, value));

		fenge(stuid, key, value);
		m.insert(make_pair(key, value));

		fenge(stuName, key, value);
		m.insert(make_pair(key, value));

		fenge(roomid, key, value);
		m.insert(make_pair(key, value));

		fenge(status, key, value);
		m.insert(make_pair(key, value));

		this->m_order.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();
}


void orderfile::fenge(string s,string &key,string &value) {
	
	int pos = s.find(":");

	key = s.substr(0, pos);
	value = s.substr(pos + 1, s.size() - pos - 1);
	

}


void orderfile::updateorder() {

	if (this->m_size == 0) {

		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0;i < m_size;i++)
	{
		ofs << "date:" << this->m_order[i]["date"] << " ";
		ofs << "interval:" << this->m_order[i]["interval"] << " ";
		ofs << "stuid:" << this->m_order[i]["stuid"] << " ";
		ofs << "stuName:" << this->m_order[i]["stuName"] << " ";
		ofs << "roomid:" << this->m_order[i]["roomid"] << " ";
		ofs << "status:" << this->m_order[i]["status"] << endl;
	}
	ofs.close();
}