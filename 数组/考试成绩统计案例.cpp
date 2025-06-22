#include <iostream>
#include<string>
using namespace std;

int main() 
{
	int score[3][3] = { {100,100,100},{90,50,100},{60,70,80} };
	string str[3] = { "张三","李四","王五" };
	int sum[3];
	for (int i = 0; i < 3; i++)
	{
		sum[i] = score[i][0] + score[i][1] + score[i][2];
		cout << str[i] << "同学的总成绩为：" << sum[i] << endl;
	}

	system("pause");

	return 0;
}