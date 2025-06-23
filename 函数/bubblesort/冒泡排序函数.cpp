#include"Ã°ÅÝÅÅÐòº¯Êý.h"

int bubblesort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < n - i - 1;j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " " << endl;
    }
    system("pause");
    return 0;
}
