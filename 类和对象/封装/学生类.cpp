#include <iostream>
using namespace std;

class student
{
public:
	string name;
	string id;

	void show()
	{
		cout << "ѧ���������ǣ� " << name << "\t"<< "ѧ����ѧ���ǣ� " << id << endl;
	}
};

int main()
{
	student s1;
	s1.name = "����";
	s1.id = "2019001";
	s1.show();

	system("pause");
	return 0;
}