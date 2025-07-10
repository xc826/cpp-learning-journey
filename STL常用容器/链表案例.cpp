#include<iostream>
using namespace std;
#include<list>



class person {
public:
	person(string name, int age, int height, int weight) {
		m_Name = name;
		m_Age = age;
		m_Height = height;
		m_Weight = weight;

	}

public:
	string m_Name;  //姓名
	int m_Age;      //年龄
	int m_Height;   //身高
	int m_Weight;   //体重
};


void printList(const list<person>& L) {

	for (list<person>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << (*it).m_Name << " " << (*it).m_Age << " " << (*it).m_Height << " "<< (*it).m_Weight << endl;
	}
	cout << endl;
}

bool compare(person& p1, person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		if (p1.m_Height == p2.m_Height)
		{
			return p1.m_Weight < p2.m_Weight;
		}
		else
		{
			return p1.m_Height > p2.m_Height;
		}
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}

void test()
{
	list<person> L;

	person p1("刘备", 35, 175, 70);
	person p2("曹操", 45, 180, 80);
	person p3("孙权", 40, 170, 60);
	person p4("赵云", 25, 190, 100);
	person p5("张飞", 35, 175, 50);
	person p6("关羽", 35, 200, 120);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	printList(L);

	L.sort(compare);

	printList(L);
}


int main()
{

	test();

	system("pause");
	return 0;
}


