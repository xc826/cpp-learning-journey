#include <iostream>
using namespace std;

class circle
{
public:
	static int m_count;
	circle()
	{
		m_count += 1;
	}

};


int circle::m_count = 0;

int main()
{
	circle c1, c2, c3;
	cout << "Total number of circles created: " << circle::m_count << endl;
	return 0;
}