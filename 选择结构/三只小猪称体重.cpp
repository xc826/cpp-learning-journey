#include <iostream>
using namespace std;

int main()
{
	int weightA, weightB, weightC;
	cout << "请输入小猪A的体重(kg): ";
	cin >> weightA;
	cout << "请输入小猪B的体重(kg): ";
	cin >> weightB;
	cout << "请输入小猪C的体重(kg): ";
	cin >> weightC;
	if (weightA > weightB && weightA > weightC)
	{
		cout << "小猪A最重！" << endl;
	}
	else if (weightB > weightA && weightB > weightC)
	{
		cout << "小猪B最重！" << endl;
	}
	else
	{
		cout << "小猪C最重！" << endl;
	}
	system("pause");
	return 0;
}