#include <iostream>
using namespace std;
#include <ctime>
int main()
{
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	while (true)
	{
		cout << "请输入您猜的数字：" << endl;
		int guess;
		cin >> guess;

		if (guess == num)
		{
			cout << "恭喜您猜对了！" << endl;
			break;
		}
		else if (guess > num)
		{
			cout << "猜的数字大了！" << endl;
		}
		else
		{
			cout << "猜的数字小了！" << endl;
		}
	}
		system("pause");

		return 0;
}