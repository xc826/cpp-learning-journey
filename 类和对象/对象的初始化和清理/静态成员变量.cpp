#include <iostream>

using namespace std;

//class person
//{
//public:
//	static int count; // 静态成员变量
//
//};
//
//int person::count = 0; // 静态成员变量初始化
//
//void test01()
//{
//	person p;
//	p.count = 10;
//	cout << "person count: " << p.count << endl;
//
//	person p2;
//	p2.count = 20;
//	cout << "person count: " << p.count << endl;
//	cout << "person count: " << p2.count << endl;
//
//	cout << "person count: " << person::count << endl; // 访问静态成员变量
//}
//
//
//
//
//int main()
//{
//
//	test01();
//	system("pause");
//	return 0;
//}


class person
{
public:
	static void func()// 静态成员函数
	{
		count = 100;
		cout << "person static function" << endl;
	}
	static int count; // 静态成员变量

private:
	static void func2()
	{
	}// 静态成员函数
};

int person::count = 0; // 静态成员变量初始化
//int person::count = 0; // 静态成员变量初始化

void test01()
{
	person p;
	p.func();



	person::func(); // 访问静态成员函数
	//cout << "person count: " << p.count << endl;
	//person::fun2();

}




int main()
{

	test01();
	system("pause");
	return 0;
}