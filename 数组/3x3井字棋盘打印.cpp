#include <iostream>
using namespace std;

int main()
{
	char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << " ";
			if (j < 2)
			{
				cout << " |";
			}
		}
		cout << endl;
		if (i < 2)
		{
			cout<<"---+---+---"<<endl;
		}
	}
	return 0;
}