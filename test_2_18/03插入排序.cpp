#include<iostream>
using namespace std;



void InsertSort1(int* arr, int size)
{
	int j;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int tmp = arr[i];
			for (j = i - 1; j >= 0&&tmp<arr[j]; j--)
			{
				arr[j+1] = arr[j];
			}
			arr[j+1] = tmp;
		}
	}
}

int main()
{
	int arr[10] = { 9,6,5,4,7,8,4,3,1,2 };
	InsertSort1(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}