#include <iostream>
using namespace std;

class person
{
	friend ostream& operator<<(ostream& cout,const person& p);
public:
	person(int a)
	{
		age = a;
	}
	//前置++
	person& operator++()
	{
		age++;
		return *this;
	}
	//后置++,要以值返回，不能直接返回引用，因为temp是一个局部对象，函数执行完后，temp就被销毁了
	person operator++(int)
	{
		person temp = *this;
		age++;
		return temp;
	}


private:
	int age;
};

ostream& operator<<(ostream& cout,const person& p)
{
	cout << "age: " << p.age ;
	return cout;
}


void test()
{
	person p1(20);
	cout << ++p1 << endl;
	cout << p1 << endl;
}

void test2()
{
	person p1(20);
	cout << p1++ << endl;
	cout << p1 << endl;
}

int main()
{
	//test();
	test2();
	system("pause");
	return 0;
}