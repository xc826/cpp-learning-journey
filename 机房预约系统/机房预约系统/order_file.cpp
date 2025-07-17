#include"order_file.h"

//构造函数
order_file::order_file()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuid;
	string stuname;
	string roomid;
	string status;

	m_size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> status)
	{
		string key;
		string value;

		map<string, string> m;
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		if (pos != -1)
		{
			pos = interval.find(":");
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		if (pos != -1)
		{
			pos = stuid.find(":");
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		if (pos != -1)
		{
			pos = stuname.find(":");
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		if (pos != -1)
		{
			pos =roomid.find(":");
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		if (pos != -1)
		{
			pos = status.find(":");
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		m_orderdata.insert(make_pair(m_size, m));
		m_size++;
	}


	ifs.close();



}




//更新预约记录
void order_file::update_order()
{
	if (m_size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_size; i++)
	{
		ofs << "date:" <<m_orderdata[i]["date"] << " ";
		ofs << "interval:" << m_orderdata[i]["interval"] << " ";
		ofs << "stuid:" << m_orderdata[i]["stuid"] << " ";
		ofs << "stuname:" << m_orderdata[i]["stuname"] << " ";
		ofs << "roomid:" << m_orderdata[i]["roomid"] << " ";
		ofs << "status:" << m_orderdata[i]["status"] << endl;
	}
	ofs.close();
}