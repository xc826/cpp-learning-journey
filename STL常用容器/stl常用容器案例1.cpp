#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<deque>
#include<time.h>


class person
{
public:

	person(string name, int score)
	{
		m_name = name;
		m_score = score;
	}



	string m_name;
	int m_score;
};


void mark(vector<person>& v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;//д��������forѭ������Ļ����ͼǵ��ڲ�forѭ��֮ǰҪ���deque��Ҫô���ǰ���д���ⲿforѭ��������

		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		//cout << "ѡ�֣� " << it->m_name << " ��֣� " << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;

		sort(d.begin(), d.end());

		d.pop_back();
		d.pop_front();

		int num = 0;

		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			num += *dit;
		}

		int ave = num / d.size();

		it->m_score = ave;

	}
}

void showscore(vector<person>& v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << it->m_name << " ƽ���֣� " << it->m_score << endl;
	}
}

void test01()
{
	person p1("A", 0);
	person p2("B", 0);
	person p3("C", 0);
	person p4("D", 0);
	person p5("E", 0);


	vector<person> v;


	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//����
	//for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "������ " << (*it).m_name << " ������ " << (*it).m_score << endl;
	//}

	mark(v);

	showscore(v);


}

int main()
{
	srand((unsigned int)time(NULL));
	test01();
	




	system("pause");
	return 0;
}