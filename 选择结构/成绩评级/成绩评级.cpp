#include <iostream>
using namespace std;

int main() 
{
	cout << "������һ���߿����Է���" << endl;
	int score;
	cin >> score;
	if (score > 600)
	{
		cout << "��ϲ�㿼��һ��" << endl;
		if (score > 700)
		{
			cout << "�㿼���˱���" << endl;
		}
		else if (score > 650)
		{
			cout << "�㿼�����廪" << endl;
		}
		else
		{
			cout << "�㿼���˸���" << endl;
		}
	}
	else if (score > 500)
	{
		cout << "�㿼���˶���" << endl;
	}
	else if (score > 400)
	{
		cout << "�㿼��������" << endl;
	}
	else
	{
		cout << "���ź���û�п��ϱ���" << endl;
	}



	system("pause");

	return 0;
}
