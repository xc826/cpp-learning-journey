#include <iostream>
using namespace std;

int main()
{
	int num = 100;
	cout << "三位数中的水仙花数如下：" << endl;
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