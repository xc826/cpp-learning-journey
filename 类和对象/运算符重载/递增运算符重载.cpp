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
	//ǰ��++
	person& operator++()
	{
		age++;
		return *this;
	}
	//����++,Ҫ��ֵ���أ�����ֱ�ӷ������ã���Ϊtemp��һ���ֲ����󣬺���ִ�����temp�ͱ�������
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