#include <iostream>
using namespace std;

class person
{
public:
	void operator()(string str)
	{
		cout<<str<<endl;
	}
};

void test()
{
	person p;
	p("Hello, world!");

}




int main()
{
	test();

	system("pause");
	return 0;
}