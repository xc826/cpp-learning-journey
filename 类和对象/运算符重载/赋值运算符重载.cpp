#include <iostream>
using namespace std;

class person
{
public:
	person(int a)
	{
		age = new int(a);
	}
	
	~person()
	{
		if (age != NULL)
		{
			delete age;
			age = NULL;
		}
	}

	person& operator=(const person& p)
	{
		//判断是否有属性在堆区，如果有先释放干净，再进行深拷贝
		if (age != NULL)
		{
			delete age;
			age = NULL;
		}
		//进行深拷贝
		age = new int(*p.age);
		return *this;//返回自身对象，实现链式赋值
	}

	int* age;
};

void test()
{
	person p1(20);
	person p2(30);
	person p3(40);
	p3 = p2 = p1;
	cout<<"age:"<<*p1.age<<endl;
	cout<<"age:"<<*p2.age<<endl;
	cout<<"age:"<<*p3.age<<endl;
}



int main()
{

	test();

	system("pause");
	return 0;
}