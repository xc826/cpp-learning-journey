#include <iostream>

using namespace std;

//class person
//{
//public:
//	static int count; // ��̬��Ա����
//
//};
//
//int person::count = 0; // ��̬��Ա������ʼ��
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
//	cout << "person count: " << person::count << endl; // ���ʾ�̬��Ա����
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
	static void func()// ��̬��Ա����
	{
		count = 100;
		cout << "person static function" << endl;
	}
	static int count; // ��̬��Ա����

private:
	static void func2()
	{
	}// ��̬��Ա����
};

int person::count = 0; // ��̬��Ա������ʼ��
//int person::count = 0; // ��̬��Ա������ʼ��

void test01()
{
	person p;
	p.func();



	person::func(); // ���ʾ�̬��Ա����
	//cout << "person count: " << p.count << endl;
	//person::fun2();

}




int main()
{

	test01();
	system("pause");
	return 0;
}