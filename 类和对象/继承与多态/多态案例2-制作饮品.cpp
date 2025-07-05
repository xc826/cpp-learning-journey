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

//¿§·È
class coffee :public abstractdrinking
{
public:
	virtual void boil()
	{
		cout << "Å©·òÉ½Èª" << endl;
	}

	virtual void brew()
	{
		cout << "³å¿§·È" << endl;
	}

	virtual void pourincup()
	{
		cout << "µ¹½ø±­×ÓÀï" << endl;
	}

	virtual void addsomething()

	{
		cout << "¼ÓÌÇºÍÅ£ÄÌ" << endl;
	}
};
//²è
class tea :public abstractdrinking
{
public:
	virtual void boil()
	{
		cout << "âù±¦" << endl;
	}

	virtual void brew()
	{
		cout << "³å²è" << endl;
	}

	virtual void pourincup()
	{
		cout << "µ¹½ø±­×ÓÀï" << endl;
	}

	virtual void addsomething()

	{
		cout << "¼ÓèÛè½" << endl;
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