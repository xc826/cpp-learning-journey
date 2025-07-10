#include <iostream>
using namespace std;
#include<vector>
#include<map>
#include<time.h>
#define cehua 0
#define meishu 1
#define yanfa 2

class person
{
public:
	string m_name;
	int m_salary;
};


void createperson(vector<person>& v)
{
	string nameseed = "ABCDEFGHIJ";
	for (int i=0; i < 10; i++)
	{
		person p;
		p.m_name = "Ա��";
		p.m_name += nameseed[i];

		p.m_salary = rand() % 10000 + 10000;
		v.push_back(p);
		
	}
}


void setgroup(vector<person>& v, multimap<int, person>& m)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		int dc = rand() % 3;
		m.insert(pair<int, person>(dc, *it));

	}
}

void showperson(multimap<int, person>& m)
{
	cout << "�߻����ţ�" << endl;
	multimap<int, person>::iterator pos = m.find(cehua);

	int count = m.count(cehua);
	int index = 0;
	for (;pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_name << " ���ʣ� " << pos->second.m_salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "�������ţ� " << endl;
	pos = m.find(meishu);
	count = m.count(meishu); // ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_name << " ���ʣ� " << pos->second.m_salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "�з����ţ� " << endl;
	pos = m.find(yanfa);
	count = m.count(yanfa); // ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_name << " ���ʣ� " << pos->second.m_salary << endl;
	}
}

int main()
{

	srand((unsigned int)time(NULL));
	vector<person> v;
	createperson(v);

	multimap<int, person> m;
	setgroup(v,m);

	showperson(m);
	system("pause");
	return 0;
}