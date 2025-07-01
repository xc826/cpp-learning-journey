#include<iostream>
using namespace std;


class phone
{
public:
	phone(string b)
	{
		brand = b;
		cout << "Phone构造 " << endl;
	}

	~phone()
	{
		cout << "Phone析构 " << endl;
	}
	string brand;
};

class person
{
public:
	person(string oname, string opname):name(oname), pname(opname)
	{
		cout << "Person构造 " << endl;
	}
~person()
	{
		cout << "Person析构 " << endl;
	}

	string name;
	phone pname;

};

void test01()
{
	person p("John", "Apple");

	cout << "Name: " << p.name << endl;
	cout << "Phone Brand: " << p.pname.brand << endl;
}



int main()
{
	test01();

	//Person p;

	system("pause");
	return 0;
}