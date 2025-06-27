#include <iostream>
using namespace std;

class student
{
public:
	string name;
	string id;

	void show()
	{
		cout << "学生的姓名是： " << name << "\t"<< "学生的学号是： " << id << endl;
	}
};

int main()
{
	student s1;
	s1.name = "张三";
	s1.id = "2019001";
	s1.show();

	system("pause");
	return 0;
}