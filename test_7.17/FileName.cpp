 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//调整奇数偶数位置，使数组所有的奇数都位于偶数前面
//void is_arr_enve(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	//从左往右找偶数，从右往左找奇数进行交换
//	while (left < right)
//	{
//		//遇到偶数停下来
//		while ((left<right)&&arr[left] % 2 == 1)
//		{
//			left++;
//		}
//		//遇到奇数停下来
//		while ((left < right) && arr[right] % 2 == 0)
//		{
//			right++;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right++;
//		}
//	}
//}
//int main()
//{
//	//输入
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//调整
//	is_arr_enve(arr, sz);
//	//输出
//	for(i=0;i<sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
//}
//输入两个升序排列的序列，将两个序列合并为一个有序序列并输出
#include <stdio.h>
int main()
{
    //对两个数组进行一一比较进行输出
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int i = 0;
    int arr[n];
    int brr[m];
    for (i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d ", &brr[i]);
    }
    int j = 0;
    int a = 0;

    while (j < n && a < m)
    {
        if (arr[j] < brr[a])
        {
            printf("%d ", arr[j]);
            j++;
        }
        else {
            printf("%d ", brr[a]);
            a++;
        }
    }
    if (j < n)
    {
        for (; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
    }
    else {
        for (; a < m; a++)
        {
            printf("%d ", brr[a]);
        }
    }
    return 0;
}