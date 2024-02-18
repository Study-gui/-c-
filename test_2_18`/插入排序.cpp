#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void insertsort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
			else {
				break;
			}
		}
	}


}

int mian()
{
	int arr[10] = { 9,6,5,4,7,8,4,3,1,2 };
	insertsort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}