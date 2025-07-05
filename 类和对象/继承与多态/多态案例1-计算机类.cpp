#include <iostream>
using namespace std;	

//普通写法

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

//利用多态实现

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

//加法

class addcalculator :public abstractcal
{
public:
	int getresult()
	{
		return num1 + num2;
	}
};


//减法
class subcalculator :public abstractcal
{
public:
	int getresult()
	{
		return num1 - num2;
	}
};


//乘法

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
	abstractcal* abs = new mulcalculator;//堆区数据用完后要记得销毁释放
	abs->num1 = 30;
	abs->num2 = 20;

	cout << abs->getresult() << endl;

	//mulcalculator m;
	delete abs;

	abs = new addcalculator;//堆区数据用完后要记得销毁释放
	abs->num1 = 30;
	abs->num2 = 20;

	cout << abs->getresult() << endl;
	delete abs;


	abs = new subcalculator;//堆区数据用完后要记得销毁释放
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