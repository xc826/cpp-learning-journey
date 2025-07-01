#include <iostream>
using namespace std;


class person
{
public:
	person()
	{
		cout << "无参构造函数" << endl;
	}

	person(int a, string b)
	{
		age = a;
		name = new string(b);
		cout << "有参构造函数" << a << endl;
	}

	person(const person& p)
	{
		age = p.age;
		name = new string(*p.name);
		cout << "拷贝函数调用" << endl;
	}

	~person()
	{
		if (name != NULL)
		{
			delete name;
			name = NULL;
		}
		cout << "析构函数" << endl;
	}

	int age;
	string* name;
};


void test01()
{
	person p1(18, "Tom");
	cout << "p1.age=" << p1.age << endl;
	cout << "p1.name=" << *p1.name << endl;

	person p2(p1);
	cout << "p2.age=" << p2.age << endl;
	cout << "p2.name=" << *p2.name << endl;
}



int main()
{
	test01();

	system("pause");
	return 0;
}