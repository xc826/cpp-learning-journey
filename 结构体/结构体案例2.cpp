#include <iostream>
using namespace std;



struct hero
{
	string name;
	int age;
	string gender;
};

void bubblesort(hero h[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (h[j].age > h[j + 1].age)
			{
				int temp = h[j].age;
				h[j].age = h[j + 1].age;
				h[j + 1].age = temp;
			}
		}
	}
}

void print(hero h[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << h[i].name << "��" << h[i].age << "��" << h[i].gender << endl;
	}
}

int main()
{
	hero h[5] =
	{
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
	};
	int len = sizeof(h) / sizeof(h[0]);
	bubblesort(h, len);
	print(h, len);

	system("pause");
	return 0;




	

}