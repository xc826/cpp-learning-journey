#include <iostream>
using namespace std;
#include"myarr.hpp"


void printarr(myarray<int>& arr)
{
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


void test()
{
	myarray<int> arr(10);
	for (int i = 0; i < 5; i++)
	{
		arr.tailinsert(i);
	}
	cout << "数列打印输出为：";
	printarr(arr);
	cout << "数列大小为：" << arr.getsize() << endl;
	cout << "数列容量为：" << arr.getcapacity() << endl;


	arr.taildelete();
	printarr(arr);
	cout << "数列大小为：" << arr.getsize() << endl;
	cout << "数列容量为：" << arr.getcapacity() << endl;

	//测试拷贝构造函数
	myarray<int> arr1(arr);
	cout << "拷贝后数列打印输出为：";
	printarr(arr1);
	cout << "拷贝后数列大小为：" << arr1.getsize() << endl;
	cout << "拷贝后数列容量为：" << arr1.getcapacity() << endl;
	
}

//测试自定义数据类型


class person
{
public:
	person() {}
	person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

void printpersonarr(myarray<person>& arr)
{
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << "姓名"<<arr[i].m_Name << "年龄"<<arr[i].m_Age<<endl;
	}
	cout << endl;
}


void test1()
{
	myarray<person> arr3(10);
	person p1("xc", 24);
	person p2("xcc", 25);
	person p3("xccc", 26);
	person p4("xcccc", 27);
	person p5("xccccc", 28);

	arr3.tailinsert(p1);
	arr3.tailinsert(p2);
	arr3.tailinsert(p3);
	arr3.tailinsert(p4);
	arr3.tailinsert(p5);

	cout << "数列打印输出为：" << endl;;
	printpersonarr(arr3);
	cout << "数列大小为：" << arr3.getsize() << endl;
	cout << "数列容量为：" << arr3.getcapacity() << endl;

}



int main()
{
	test();
	test1();


	system("pause");
	return 0;
}