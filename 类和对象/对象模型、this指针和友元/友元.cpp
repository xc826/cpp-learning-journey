#include <iostream>
using namespace std;


class person;

class goodfriend
{
public:

	goodfriend();
	void view();
	void view1();


private:
	person* p;

};

class person
{
	friend void goodfriend::view();
	friend void goodfriend::view1();
public:
	person();

public:
	int age;

private:
	int salary;

};

void goodfriend::view()
{
	cout << "Good friend age is " << p->age << endl;
	cout << "Good friend salary is " << p->salary << endl;
}

void goodfriend::view1()
{
	cout << "Good friend age is " << p->age << endl;
	cout << "Good friend salary is " << p->salary << endl;
}

goodfriend::goodfriend()
{
	p = new person;
}

person::person()
{
	age = 25;
	salary = 5000;
}


void test()
{
	goodfriend gf;
	gf.view();
	gf.view1();
}

int main()
{
	test();
	

	system("pause");
	return 0;
}