// #define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void Choose(int* arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		int min = i;
//		int j = 0;
//		for (j = i+1; j < size; j++)
//		{
//			if (arr[j] < arr[min])
//			{
//				min = j;
//			}
//		}
//		swap(&arr[i], &arr[min]);
//	}
//}
//
//
//int main()
//{
//	int arr[10] = { 9,6,5,4,7,8,4,3,1,2 };
//
//	Choose(arr, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	system("pause");
//	return 0;
//}