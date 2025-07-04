#include <iostream>
using namespace std;

class person
{
public:
	person(int a, string n)
	{
		age = a;
		name = n;
	}

	bool operator==(const person& p)
	{
		if (age == p.age && name == p.name)
			return true;
		else
			return false;
	}

	bool operator!=(const person& p)
	{
		if (age != p.age || name != p.name)
			return true;
		else
			return false;
	}



	int age;
	string name;
};


void test()
{
	person p1(20, "Tom");
	person p2(21, "Tom");

	if (p1 == p2)
		cout << "p1 and p2 are equal." << endl;
	else
		cout << "p1 and p2 are not equal." << endl;

	if (p1 != p2)
		cout << "p1 and p2 are not equal." << endl;
	else
		cout << "p1 and p2 are equal." << endl;
}


int main()
{
	test();
	system("pause");
	return 0;
}