#include <iostream>
using namespace std;

int main()
{
	int num = 100;
	cout << "��λ���е�ˮ�ɻ������£�" << endl;
	do
	{
		int a = num / 100;
		int b = num / 10 % 10;
		int c = num % 10;
		if (a * a * a + b * b * b + c * c * c == num)
		{
			cout << num << endl;
		}
		num++;
	} while (num < 1000);
	system("pause");
	return 0;
}