#include <iostream>
using namespace std;

class cube
{
public:
	double L;
	double H;
	double W;
	double S()
	{
		return 2 * L * H + 2 * L * W + 2 * H * W;
	}
	double V()
	{
		return L * H * W;
	}
	//��Ա�����ж��Ƿ���ȣ��Ѿ���һ���������ˣ�ֻ���ٴ���һ����Ҫ�Աȵ������弴��
	bool judge_class(cube& c)
	{
		if (L == c.L && H == c.H && W == c.W)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

bool judge(cube& c1, cube& c2)
{
	if (c1.L == c2.L && c1.H == c2.H && c1.W == c2.W)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cube c1;
	c1.L = 2;
	c1.H = 3;
	c1.W = 4;

	cout << "The surface area of the cube is " << c1.S() << endl;
	cout << "The volume of the cube is " << c1.V() << endl;

	cube c2;
	c2.L = 5;
	c2.H = 6;
	c2.W = 7;

	//ȫ�ֺ����ж�
	if (judge(c1, c2))
	{
		cout << "The two cubes are the same." << endl;
	}
	else
	{
		cout << "The two cubes are different." << endl;
	}

	//��Ա�����ж�
	if (c1.judge_class(c2))
	{
		cout << "The two cubes are the same." << endl;
	}
	else
	{
		cout << "The two cubes are different." << endl;
	}

	system("pause");
	return 0;
}