#include <iostream>
using namespace std;
#include <ctime>
int main()
{
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	while (true)
	{
		cout << "���������µ����֣�" << endl;
		int guess;
		cin >> guess;

		if (guess == num)
		{
			cout << "��ϲ���¶��ˣ�" << endl;
			break;
		}
		else if (guess > num)
		{
			cout << "�µ����ִ��ˣ�" << endl;
		}
		else
		{
			cout << "�µ�����С�ˣ�" << endl;
		}
	}
		system("pause");

		return 0;
}