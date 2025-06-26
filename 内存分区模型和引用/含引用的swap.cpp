#include <iostream>
using namespace std;

void swap1(int m,int n)
{
	int temp = m;
	m = n;
	n = temp;
}

void swap2(int* m,int* n)
{
	int temp = *m;
	*m = *n;
	*n = temp;	
}
void swap3(int& m,int& n)//引用传递，形参也可修饰实参
{
	int temp = m;
	m = n;
	n = temp;
}
int main() {

	int a = 10, b = 20;
	cout << "Before swap1: a = " << a << ", b = " << b << endl;
	swap1(a, b);
	cout << "After swap1: a = " << a << ", b = " << b << endl;
	int c = 10, d = 20;
	cout << "Before swap2: c = " << c << ", d = " << d << endl;
	swap2(&c, &d);
	cout << "After swap2: c = " << c << ", d = " << d << endl;
	int e = 10, f = 20;
	cout << "Before swap3: e = " << e << ", f = " << f << endl;
	swap3(e, f);
	cout << "After swap3: e = " << e << ", f = " << f << endl;

	system("pause");

	return 0;
}
