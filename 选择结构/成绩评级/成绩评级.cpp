#include <iostream>
using namespace std;

int main() 
{
	cout << "请输入一个高考考试分数" << endl;
	int score;
	cin >> score;
	if (score > 600)
	{
		cout << "恭喜你考上一本" << endl;
		if (score > 700)
		{
			cout << "你考上了北大" << endl;
		}
		else if (score > 650)
		{
			cout << "你考上了清华" << endl;
		}
		else
		{
			cout << "你考上了复旦" << endl;
		}
	}
	else if (score > 500)
	{
		cout << "你考上了二本" << endl;
	}
	else if (score > 400)
	{
		cout << "你考上了三本" << endl;
	}
	else
	{
		cout << "很遗憾你没有考上本科" << endl;
	}



	system("pause");

	return 0;
}
