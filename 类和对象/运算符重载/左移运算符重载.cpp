#include <iostream>
using namespace std;

class person
{
	friend ostream& operator<<(ostream& cout, person& p);
public:
	person(int a, int b)
	{
		age = a;
		weight = b;
	}
private:
	int age;
	int weight;
};

ostream& operator<<(ostream & cout, person & p)
{
	cout << "age: " << p.age << " weight: " << p.weight;
	return cout;
}


void test()
{
	person p1(20, 60);
	cout << p1<<endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}