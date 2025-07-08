#include<iostream>
using namespace std;

template<typename T>
void myswap(T& a,T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


template<typename T>
void mysort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j <len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			myswap(arr[max], arr[i]);
		}
	}
}

template<typename T>
void printarr(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;
}

void test1()
{
	int array[] = { 2,4,6,1,4,8,3,6,1 };

	int len = sizeof(array) / sizeof(array[0]);
	//cout << len;
	mysort(array,len);
	printarr(array,len);

	//cout << "a = " << a << " b = " << b << endl;

}

void test2()
{
	char array[] = "bdajeh";

	int len = sizeof(array) / sizeof(array[0]);
	//cout << len;
	mysort(array, len);
	printarr(array, len);

	//cout << "a = " << a << " b = " << b << endl;

}

int main()
{

	test1();
	test2();


	system("pause");
	return 0;
}
