#include <iostream>
using namespace std;

int main()
{
	int weightA, weightB, weightC;
	cout << "������С��A������(kg): ";
	cin >> weightA;
	cout << "������С��B������(kg): ";
	cin >> weightB;
	cout << "������С��C������(kg): ";
	cin >> weightC;
	if (weightA > weightB && weightA > weightC)
	{
		cout << "С��A���أ�" << endl;
	}
	else if (weightB > weightA && weightB > weightC)
	{
		cout << "С��B���أ�" << endl;
	}
	else
	{
		cout << "С��C���أ�" << endl;
	}
	system("pause");
	return 0;
}