#include<iostream>
using namespace std;


class abstractdrinking
{
public:
	virtual void boil() = 0;

	virtual void brew() = 0;

	virtual void pourincup() = 0;

	virtual void addsomething() = 0;

	void makedrink()
	{
		boil();
		brew();
		pourincup();
		addsomething();
	}

};

//����
class coffee :public abstractdrinking
{
public:
	virtual void boil()
	{
		cout << "ũ��ɽȪ" << endl;
	}

	virtual void brew()
	{
		cout << "�忧��" << endl;
	}

	virtual void pourincup()
	{
		cout << "����������" << endl;
	}

	virtual void addsomething()

	{
		cout << "���Ǻ�ţ��" << endl;
	}
};
//��
class tea :public abstractdrinking
{
public:
	virtual void boil()
	{
		cout << "����" << endl;
	}

	virtual void brew()
	{
		cout << "���" << endl;
	}

	virtual void pourincup()
	{
		cout << "����������" << endl;
	}

	virtual void addsomething()

	{
		cout << "�����" << endl;
	}
};
	
void dowork(abstractdrinking* abs)
{
	abs->makedrink();
	delete abs;
}

void test()
{
	dowork(new coffee);

	cout << endl;

	dowork(new tea);
}
int main()
{
	test();

	system("pause");
	return 0;
}