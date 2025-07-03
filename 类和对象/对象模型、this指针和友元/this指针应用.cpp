#include <iostream>
using namespace std;

class person
{
public:
	person(int a)
	{
		age = a;
	}
	void compareAge(person* thisPtr)
	{
		if (thisPtr->age > this->age)
		{
			cout << "thisPtr is older than this" << endl;
		}
		else if (thisPtr->age < this->age)
		{
			cout << "this is older than thisPtr" << endl;
		}
		else
		{
			cout << "they are the same age" << endl;
		}
	}
	int age;
};

void test()
{
	person p1(20);
	person p2(25);
	p1.compareAge(&p2);
}

int main()
{
	test();
	system("pause");
	return 0;
}