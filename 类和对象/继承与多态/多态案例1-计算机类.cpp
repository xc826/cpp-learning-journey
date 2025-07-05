#include <iostream>
using namespace std;	

//��ͨд��

class calculator
{
public:

	int getresult(string ope)
	{
		if (ope == "+")
			return a + b;
		else if (ope == "-")
			return a - b;
		else if (ope == "*")
			return a * b;
		else if (ope == "/")
			return a / b;
		else
			return 0;
	}


	int a;
	int b;
};

void test1()
{
	calculator c;
	c.a = 10;
	c.b = 5;
	cout << c.getresult("+") << endl;
	cout << c.getresult("-") << endl;
	cout << c.getresult("*") << endl;
	cout << c.getresult("/") << endl;
}

//���ö�̬ʵ��

class abstractcal
{
public:
	virtual int getresult()
	{
		return 0;
	}

	int num1;
	int num2;
};

//�ӷ�

class addcalculator :public abstractcal
{
public:
	int getresult()
	{
		return num1 + num2;
	}
};


//����
class subcalculator :public abstractcal
{
public:
	int getresult()
	{
		return num1 - num2;
	}
};


//�˷�

class mulcalculator :public abstractcal
{
public:
	int getresult()
	{
		return num1 * num2;
	}
};

void test()
{
	abstractcal* abs = new mulcalculator;//�������������Ҫ�ǵ������ͷ�
	abs->num1 = 30;
	abs->num2 = 20;

	cout << abs->getresult() << endl;

	//mulcalculator m;
	delete abs;

	abs = new addcalculator;//�������������Ҫ�ǵ������ͷ�
	abs->num1 = 30;
	abs->num2 = 20;

	cout << abs->getresult() << endl;
	delete abs;


	abs = new subcalculator;//�������������Ҫ�ǵ������ͷ�
	abs->num1 = 30;
	abs->num2 = 20;

	cout << abs->getresult() << endl;
	delete abs;
}

int main() {

	test();

	system("pause");

	return 0;
}